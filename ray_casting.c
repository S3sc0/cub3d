/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:32:11 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 16:51:24 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ????
float	pnret(float x, float a, float b, float c)
{
	if (x > 0)
		return (a);
	else if (x == 0)
		return (b);
	return (c);
}

// when checking x and y coordinates don't go out of the map
int		max_crd(rycrd intersect)
{
	data		info;
	static int	*x;
	static int	y;
	int		i;

	if (x == NULL || y == 0)
	{
		i = -1;
		info = ft_data(NULL);
		y = count_items(info.the_map);
		x = (int *)malloc(sizeof(int) * y);
		while (++i < y)
			x[i] =  ft_strlen(info.the_map[i]) * SQUARE_SIZE;
		y *= SQUARE_SIZE;
	}
	i = (int)(intersect.y / SQUARE_SIZE);
	if (intersect.y > y || intersect.y < 0 || intersect.x > x[i] || intersect.x < 0)
		return (0);
	return (1);
}

// calculate horizantal_intersection
rycrd		h_intersect(float rayAngle, player plr)
{
	rycrd		intersect;
	crd		next;
	float	of_y;
	char	which1;
	int	s;

	s = 0;
	rayAngle *= RADIN;
	of_y = sin(rayAngle) > 0 ? 0.1 : -0.1;
	intersect.y = floor(plr.y / SQUARE_SIZE + (sin(rayAngle) > 0 ? 1 : 0)) * SQUARE_SIZE;
	intersect.x = tan(rayAngle) ? (intersect.y - plr.y + tan(rayAngle) * plr.x) / tan(rayAngle) : 0;
	intersect.sx = 0;
	intersect.sy = 0;
	next.y = SQUARE_SIZE * pnret(sin(rayAngle), 1, 0, -1);
	next.x = tan(rayAngle) ? next.y / tan(rayAngle) : 0;
	while (max_crd(intersect) && !Awall(intersect.x, intersect.y + of_y, &which1))
	{
		intersect.sx = which1 == '2' && s == 0 ? intersect.x : intersect.sx;
		intersect.sy = which1 == '2' && s == 0 && ++s ? intersect.y : intersect.sy;
		intersect.x += next.x;
		intersect.y += next.y;
	}
	return(intersect);
}

// calculate vertical_intersection
rycrd		v_intersect(float rayAngle, player plr)
{
	rycrd		intersect;
	crd		next;
	float	of_x;
	char	which1;
	int	s;

	s = 0;
	rayAngle *= RADIN;
	of_x = cos(rayAngle) > 0 ? 0.1 : -0.1;
	intersect.x = floor(plr.x / SQUARE_SIZE + (cos(rayAngle) > 0 ? 1 : 0)) * SQUARE_SIZE;
	intersect.y = tan(rayAngle) * (intersect.x - plr.x) + plr.y;
	intersect.sx = 0;
	intersect.sy = 0;
	next.x = SQUARE_SIZE * pnret(cos(rayAngle), 1, 0, -1);
	next.y = next.x * tan(rayAngle);
	while (max_crd(intersect) && !Awall(intersect.x + of_x, intersect.y, &which1))
	{
		intersect.sx = which1 == '2' && s == 0 ? intersect.x : intersect.sx;
		intersect.sy = which1 == '2' && s == 0 && ++s ? intersect.y : intersect.sy;
		intersect.x += next.x;
		intersect.y += next.y;
	}
	return (intersect);
}

// calc the distance between the ray intersect and the player position
float	calc_distance(player plr, rycrd hi, rycrd vi, float rayAngle)
{
	float	res1;
	float	res2;
	float	ret;

	sprite_dst(plr, hi, vi);
	res1 = sqrt(pow(plr.x - hi.x, 2) + pow(plr.y - hi.y, 2));
	res2 = sqrt(pow(plr.x - vi.x, 2) + pow(plr.y - vi.y, 2));
	if (res1 < res2)
	{
		select_texture('h', rayAngle);
		g_offset_x = (int)hi.x % SQUARE_SIZE; // we'll use this value for the texture thing
		ret = res1 * cos((rayAngle - plr.rotationA) * RADIN);
	}
	else
	{
		select_texture('v', rayAngle);
		g_offset_x = (int)vi.y % SQUARE_SIZE;
		ret = res2 * cos((rayAngle - plr.rotationA) * RADIN);
	}
	return (ret);
}

// initial each ray then it goes in a while for a check
void	rays(player plr, data info)
{
	int		rayNum;
	float	rayAngle;
	float	dst;

	rayAngle = plr.rotationA - (FOV_ANGLE / 2);
	rayAngle = normA(rayAngle);
	rayNum = 0;
	g_wall_distance = (float*)malloc(sizeof(float) * info.wx);
	while (rayNum < info.wx)
	{
		dst = calc_distance(plr, h_intersect(rayAngle, plr), v_intersect(rayAngle, plr), rayAngle);
		g_wall_distance[rayNum] = dst;
		wall_rendering(dst, rayNum, info);
		rayAngle += FOV_ANGLE / (float)info.wx;
		rayAngle = normA(rayAngle);
		rayNum++;
	}
}
