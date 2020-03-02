/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:32:11 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/02 11:18:07 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// initial each ray then it goes in a while for a check
void	rays(player plr, data info)
{
	float		x;
	float		y;
	float		nextX;
	float		nextY;
	int			db;

	db = plr.rotationA > 0 && plr.rotationA < 180 ? SQUARE_SIZE : -1;
	y = floor(plr.y / SQUARE_SIZE) * SQUARE_SIZE + db;
	if (plr.rotationA == 0 || plr.rotationA == 180 || plr.rotationA == 360)
	{
		x = 0;
		nextX = 0;
	}
	else
	{
		x = plr.x + (plr.y - y) / tan(plr.rotationA * RADIN);
		nextX = SQUARE_SIZE / tan(plr.rotationA * RADIN);
	}
	nextY = plr.rotationA > 0 && plr.rotationA < 180 ? SQUARE_SIZE : SQUARE_SIZE * -1;
	while (x >= 0 && x < info.wx && y >= 0 && y < info.wy && Awall(x, y) == 0)
	{
		x += nextX;
		y += nextY;
		put_pixel_img(x, y, 0xFFFFFF);
		printf("%f %d\n", nextY, plr.rotationA);
	}
}
