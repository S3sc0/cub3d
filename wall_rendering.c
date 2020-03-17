/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:04:58 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/09 17:04:22 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_texture(char c, float ray_angle)
{
	data	info;

	info = ft_data(NULL);
	if (ray_angle >= 180 && c == 'h')
		g_texture = info.NO;
	else if (ray_angle >= 0 && ray_angle <= 180 && c == 'h')
		g_texture = info.SO;
	else if (ray_angle >= 90 && ray_angle <= 270 && c == 'v')
		g_texture = info.WE;
	else if ((ray_angle > 270 || ray_angle < 90) && c == 'v')
		g_texture = info.EA;
}

// here we render our walls
void	wall_rendering(float ray_d, int x, data info)
{
	wall	w;
	int		i;
	int		y;
	float	tmp;

	w.dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	w.bottom  = (SQUARE_SIZE / ray_d) * w.dpp; // this is my wall height 
	tmp = w.bottom; // keeping this value before resizing it to fix texture bug
	w.bottom = w.bottom > info.wy ? info.wy: w.bottom;
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
