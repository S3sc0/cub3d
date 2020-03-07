/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:04:58 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/07 18:55:48 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// here we render our walls
void	wall_rendering(float ray_d, int x, data info)
{
	wall	w;
	int		i;
	int		y;

	w.dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	w.bottom  = (SQUARE_SIZE / ray_d) * w.dpp;
	w.bottom = w.bottom > info.wy ? info.wy : w.bottom;
	w.top = (info.wy - w.bottom) / 2;
	y = w.top;
	i = 0;
	while (i < w.bottom)
	{
		w.offset_y = (y - w.top) * (64.0 / w.bottom);
		g_img_data[x + y * (g_line / 4)] = info.NO[64 * w.offset_y + g_offset_x];
		y++;
		i++;
	}
}
