/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:21:29 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/15 18:44:14 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** here we calc the distence between the player and the sprite
*/

void	sprite_dst(t_player plr, t_rycrd hi, t_rycrd vi)
{
	float	res1;
	float	res2;

	g_asprite = 1;
	if (hi.sx == 0 && hi.sy == 0 && vi.sx == 0 && vi.sy == 0)
	{
		g_asprite = 0;
		return ;
	}
	res1 = sqrt(pow(plr.x - hi.sx, 2) + pow(plr.y - hi.sy, 2));
	res2 = sqrt(pow(plr.x - vi.sx, 2) + pow(plr.y - vi.sy, 2));
	if (((vi.sx == 0 && vi.sy == 0) || res1 < res2) && hi.sx != 0 && hi.sy != 0)
	{
		g_sprt.x = hi.sx;
		g_sprt.y = hi.sy;
		g_vert = 0;
	}
	else
	{
		g_sprt.x = vi.sx;
		g_sprt.y = vi.sy;
		g_vert = 1;
	}
}

/*
** it calcs the final destance of between the t_player and the t_sprite
** 1) calc sprit center
** 2) calc thee destance between the player and the center
** 3) calc the intersection points
** 4) calc the wanted destance and return it
*/

float	dst_to_sprite(t_player plr, float ray_angle)
{
	t_crd	point;
	float	r;
	int		i1;
	int		i2;

	i1 = g_vert == 1 && ray_angle > 90 && ray_angle < 270 ? -1 : 1;
	i2 = g_vert == 0 && ray_angle > 180 && ray_angle < 360 ? -1 : 1;
	point.x = ((int)(g_sprt.x / SQ_SZ) *
			SQ_SZ) + (SQ_SZ / 2) * i1;
	point.y = ((int)(g_sprt.y / SQ_SZ) *
			SQ_SZ) + (SQ_SZ / 2) * i2;
	r = sqrt(pow(plr.x - point.x, 2) + pow(plr.y - point.y, 2));
	g_sprt.x = plr.x + cos(ray_angle * RADIN) * r;
	g_sprt.y = plr.y + sin(ray_angle * RADIN) * r;
	if ((g_vert == 1 && plr.rotation_a > 0 && plr.rotation_a < 180) ||
		g_vert == 0)
		g_offset_s = (int)g_sprt.x % SQ_SZ;
	else
		g_offset_s = (int)g_sprt.y % SQ_SZ;
	return (sqrt(pow(plr.x - g_sprt.x, 2) + pow(plr.y - g_sprt.y, 2)));
}

/*
** this function will render my sprite
*/

void	sprite_rendering(t_player plr, float ray_angle, t_data info, int x)
{
	float		dst;
	t_wall		s;
	float		tmp;
	int			i;

	dst = dst_to_sprite(plr, ray_angle);
	s.dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	s.bottom = (SQ_SZ / dst) * s.dpp;
	tmp = s.bottom;
	s.bottom = s.bottom > info.wy ? info.wy : s.bottom;
	s.top = (info.wy - s.bottom) / 2;
	i = -1;
	if (info.the_map[(int)floor(g_sprt.y / SQ_SZ)]
			[(int)floor(g_sprt.x / SQ_SZ)] == '2')
	{
		while (++i < s.bottom)
		{
			s.dst_ftop = s.top + (tmp / 2) - (info.wy / 2);
			s.offset_y = s.dst_ftop * (64.0 / tmp);
			if (info.s[64 * s.offset_y + g_offset_s] != 0)
				g_img_data[s.top * info.wx + x] =
					info.s[64 * s.offset_y + g_offset_s];
			s.top++;
		}
	}
}
