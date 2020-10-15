/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:32:11 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/15 18:50:47 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** when checking x and y coordinates don't go out of the map
*/

int			max_crd(t_rycrd intsct)
{
	t_data		info;
	static int	*x;
	static int	y;
	int			i;

	if (x == NULL || y == 0)
	{
		i = -1;
		info = ft_data(NULL);
		y = count_items(info.the_map);
		x = (int *)malloc(sizeof(int) * y);
		while (++i < y)
			x[i] = ft_strlen(info.the_map[i]) * SQ_SZ;
		y *= SQ_SZ;
	}
	i = (int)(intsct.y / SQ_SZ);
	if (intsct.y > y || intsct.y < 0
		|| intsct.x > x[i] || intsct.x < 0)
		return (0);
	return (1);
}

/*
** calculate horizantal_intsction
*/

t_rycrd		h_intsct(float ray_angle, t_player plr)
{
	t_rycrd		intsct;
	t_crd		next;
	float		of_y;
	char		which1;
	int			s;

	s = 0;
	ray_angle *= RADIN;
	of_y = sin(ray_angle) > 0 ? 0.1 : -0.1;
	intsct.y = floor(plr.y / SQ_SZ + (sin(ray_angle) > 0 ? 1 : 0)) * SQ_SZ;
	intsct.x = tan(ray_angle) ? (intsct.y - plr.y +
			tan(ray_angle) * plr.x) / tan(ray_angle) : 0;
	intsct.sx = 0;
	intsct.sy = 0;
	next.y = SQ_SZ * pnret(sin(ray_angle), 1, 0, -1);
	next.x = tan(ray_angle) ? next.y / tan(ray_angle) : 0;
	while (max_crd(intsct) &&
		!a_wall(intsct.x, intsct.y + of_y, &which1))
	{
		intsct.sx = which1 == '2' && s == 0 ? intsct.x : intsct.sx;
		intsct.sy = which1 == '2' && s == 0 && ++s ? intsct.y : intsct.sy;
		intsct.x += next.x;
		intsct.y += next.y;
	}
	return (intsct);
}

/*
** calculate vertical_intsction
*/

t_rycrd		v_intsct(float ray_angle, t_player plr)
{
	t_rycrd		intsct;
	t_crd		next;
	float		of_x;
	char		which1;
	int			s;

	s = 0;
	ray_angle *= RADIN;
	of_x = cos(ray_angle) > 0 ? 0.1 : -0.1;
	intsct.x = floor(plr.x / SQ_SZ + (cos(ray_angle) > 0 ? 1 : 0)) * SQ_SZ;
	intsct.y = tan(ray_angle) * (intsct.x - plr.x) + plr.y;
	intsct.sx = 0;
	intsct.sy = 0;
	next.x = SQ_SZ * pnret(cos(ray_angle), 1, 0, -1);
	next.y = next.x * tan(ray_angle);
	while (max_crd(intsct) &&
		!a_wall(intsct.x + of_x, intsct.y, &which1))
	{
		intsct.sx = which1 == '2' && s == 0 ? intsct.x : intsct.sx;
		intsct.sy = which1 == '2' && s == 0 && ++s ?
					intsct.y : intsct.sy;
		intsct.x += next.x;
		intsct.y += next.y;
	}
	return (intsct);
}

/*
** calc the distance between the ray intsct and the player position
*/

float		calc_distance(t_player plr, t_rycrd hi, t_rycrd vi, float ray_angle)
{
	float	res1;
	float	res2;
	float	ret;

	sprite_dst(plr, hi, vi);
	res1 = sqrt(pow(plr.x - hi.x, 2) + pow(plr.y - hi.y, 2));
	res2 = sqrt(pow(plr.x - vi.x, 2) + pow(plr.y - vi.y, 2));
	if (res1 < res2)
	{
		select_texture('h', ray_angle);
		g_offset_x = (int)hi.x % SQ_SZ;
		ret = res1 * cos((ray_angle - plr.rotation_a) * RADIN);
	}
	else
	{
		select_texture('v', ray_angle);
		g_offset_x = (int)vi.y % SQ_SZ;
		ret = res2 * cos((ray_angle - plr.rotation_a) * RADIN);
	}
	return (ret);
}

/*
** initial each ray then it goes in a while for a check
*/

void		rays(t_player plr, t_data info)
{
	int		ray_num;
	float	ray_angle;
	float	dst;

	ray_angle = plr.rotation_a - (FOV_ANGLE / 2);
	ray_angle = norm_a(ray_angle);
	ray_num = 0;
	g_wall_distance = (float*)malloc(sizeof(float) * info.wx);
	while (ray_num < info.wx)
	{
		dst = calc_distance(plr, h_intsct(ray_angle, plr),
			v_intsct(ray_angle, plr), ray_angle);
		g_wall_distance[ray_num] = dst;
		wall_rendering(dst, ray_num, info);
		ray_angle += FOV_ANGLE / (float)info.wx;
		ray_angle = norm_a(ray_angle);
		ray_num++;
	}
}
