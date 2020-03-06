/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 20:04:58 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/06 12:03:17 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// here we render our walls
void	wall_rendering(float ray_d, int x, data info)
{
	float	dpp;
	float	wall_h;
	float	i;
	int		start_h;

	i = 0;
	dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	wall_h = (SQUARE_SIZE / ray_d) * dpp;
	wall_h = wall_h > info.wy ? info.wy : wall_h;
	start_h = (info.wy - wall_h) / 2;
	while (i < wall_h)
	{
		put_pixel_img(x, start_h, 0xFFFFFF);
		start_h++;
		i++;
	}
}
