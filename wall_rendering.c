/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:04:58 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/15 18:44:14 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_texture(char c, float ray_angle)
{
	t_data	info;

	info = ft_data(NULL);
	if (ray_angle >= 180 && c == 'h')
		g_texture = info.no;
	else if (ray_angle >= 0 && ray_angle <= 180 && c == 'h')
		g_texture = info.so;
	else if (ray_angle >= 90 && ray_angle <= 270 && c == 'v')
		g_texture = info.we;
	else if ((ray_angle > 270 || ray_angle < 90) && c == 'v')
		g_texture = info.ea;
}

/*
** here we are rendering our walls
** 1) w.bottom is the wall's height
** 2) i'm keeping the value of w.bottom since i'll change it later
*/

void	wall_rendering(float ray_d, int x, t_data info)
{
	t_wall	w;
	int		i;
	int		y;
	float	tmp;

	w.dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	w.bottom = (SQ_SZ / ray_d) * w.dpp;
	tmp = w.bottom;
	w.bottom = w.bottom > info.wy ? info.wy : w.bottom;
	w.top = (info.wy - w.bottom) / 2;
	y = w.top;
	i = 0;
	while (i < w.bottom)
	{
		w.dst_ftop = y + (tmp / 2) - (info.wy / 2);
		w.offset_y = w.dst_ftop * (64.0 / tmp);
		g_img_data[x + y * info.wx] = g_texture[64 * w.offset_y + g_offset_x];
		y++;
		i++;
	}
}
