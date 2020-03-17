/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:21:29 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 16:50:25 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// here we calc the distence between the player and sprite
int	sprite_dst(player plr, rycrd hi, rycrd vi, float ray_angle)
{
	float	res1;
	float	res2;

	sprt.x = 0;
	sprt.y = 0;
	if (hi.sx == 0 && hi.sy == 0 && vi.sx == 0 && vi.sy == 0)
		return (0);
	res1 = sqrt(pow(plr.x - hi.sx, 2) + pow(plr.y - hi.sy, 2));
	res2 = sqrt(pow(plr.x - vi.sx, 2) + pow(plr.y - vi.sy, 2));
	if (res1 < res2)
	{
		sprt.x = hi.sx;
		sprt.y = hi.sy;
		g_offset_s = (int)hi.x % SQUARE_SIZE;
	}
	else
	{
		sprt.x = vi.sx;
		sprt.y = vi.sy;
		g_offset_s = (int)vi.y % SQUARE_SIZE;
	}
	return (1);
}

// just calc the distance between two points
float	mini_dst(player plr, float ray_angle, crd cntr)
{
	float	res;

	res = sqrt(pow(plr.x - cntr.x, 2) + pow(plr.y - cntr.y, 2));
	res *= cos((ray_angle - plr.rotationA) * RADIN);
	return (res);
}

// it calcs the final destance of between the player and the sprite
float	dst_to_sprite(player plr, float ray_angle)
{
	crd	point;
	float	r;
	float	dst;

	// calc sprite center
	point.x = ((int)(sprt.x / SQUARE_SIZE) * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	point.y = ((int)(sprt.y / SQUARE_SIZE) * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	put_pixel_img(point.x, point.y, 0xFFFFFF);
	// calc the destance between the player and the center
	r = mini_dst(plr, ray_angle, point);
	// calc the intersection points
	point.x = plr.x - (cos(ray_angle * RADIN) * r);
	point.y = plr.y + (sin(ray_angle * RADIN) * r);
	// calc the wanted destance, voala !!!
	dst = mini_dst(plr, ray_angle, point);
	return (dst);
}

// this function will render my sprite
void	sprite_rendering(player plr, float ray_angle, data info, int x)
{
	float	dst;
	wall	s;
	float	tmp;
	int	y;
	int	i;

	dst = dst_to_sprite(plr, ray_angle);
	s.dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	s.bottom = (SQUARE_SIZE / dst) * s.dpp;
	tmp = s.bottom;
	s.bottom = s.bottom > info.wy ? info.wy : s.bottom;
	s.top = (info.wy - s.bottom) / 2;
	y = s.top;
	i = 0;
	while (i < s.bottom)
	{
		s.dst_ftop = y + (tmp / 2) - (info.wy / 2);
		s.offset_y = s.dst_ftop * (64.0 / tmp);
		//if (info.S[64 * s.offset_y + g_offset_s] != 0)
		//g_img_data[x + y * info.wx] = info.S[64 * s.offset_y + g_offset_s];
		y++;
		i++;
	}
}
