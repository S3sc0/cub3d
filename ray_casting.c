/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:32:11 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/03 22:37:12 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	pnret(float x, float a, float b, float c)
{
	if (x > 0)
		return (a);
	else if (x == 0)
		return (b);
	return (c);
}

int		max_crd(crd intersect)
{
	data	info;
	int		i;
	int		j;

	i = 0;
	j = 0;
	info = ft_data(NULL);
	while (info.the_map[j] != NULL)
		j++;
	while (info.the_map[0][i] != '\0')
		i++;
	j *= SQUARE_SIZE;
	i *= SQUARE_SIZE;
	if (intersect.x > i || intersect.y > j || intersect.x < 0 || intersect.y < 0)
		return (0);
	return (1);
}

crd		horizantal_intersect(float rayAngle, player plr)
{
	crd		intersect;
	crd		next;

	rayAngle *= RADIN;
	intersect.y = floor(plr.y / SQUARE_SIZE + (sin(rayAngle) > 0 ? 1 : 0)) * SQUARE_SIZE - 1;
	intersect.x = (intersect.y - plr.y + tan(rayAngle) * plr.x) / tan(rayAngle);
	next.y = SQUARE_SIZE * pnret(sin(rayAngle), 1, 0, -1);
	next.x = tan(rayAngle) ? next.y / tan(rayAngle) : 0;
	printf("%f\t%f\n", rayAngle, tan(rayAngle));
	while (max_crd(intersect) &&  !Awall(intersect.x, intersect.y))
	{
		intersect.x += next.x;
		intersect.y += next.y;
		put_pixel_img(intersect.x, intersect.y, 0xFFFFFF);
	}
	return(intersect);
}

// initial each ray then it goes in a while for a check
void	rays(player plr, data info)
{
	int		rayNum;
	float	rayAngle;
	crd		point;

	rayAngle = plr.rotationA - (FOV_ANGLE / 2);
	rayNum = 0;
	while (rayNum < info.wx)
	{
		point = horizantal_intersect(rayAngle, plr);
		rayAngle += FOV_ANGLE / (float)info.wx;
		rayNum++;
	}
}
