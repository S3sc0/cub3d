/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:08:12 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/03 22:36:55 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_img(int x, int y, int color)
{
	crd		intersect;

	intersect.x = x;
	intersect.y = y;
	if (max_crd(intersect))
		g_img_data[x + y * (g_line / 4)] = color;
}
