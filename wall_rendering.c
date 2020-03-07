/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:04:58 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/08 00:53:03 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// here we render our walls
void	wall_rendering(float ray_d, int x, data info)
{
	wall	w;
	int		i;
	int		y;
	int		d_from_top;
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
		d_from_top = y + (tmp / 2) - (info.wx / 2);
		w.offset_y = d_from_top * (64.0 / tmp);
		g_img_data[x + y * (g_line / 4)] = info.NO[64 * w.offset_y + g_offset_x];
		y++;
		i++;
	}
}
