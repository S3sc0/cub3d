/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:39:49 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/25 11:56:11 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function just draws rectangles
void	rec(int x, int y, char fill)
{
	int		i;
	int		j;

	i = 0;
	if (fill == '1' || fill == '2')
	{
		while (i < SQUARE_SIZE)
		{
			j = 0;
			while (j < SQUARE_SIZE)
			{
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, x + i, y + j, 0xE84D6C);
				j++;
			}
			i++;
		}
	}
}

/*
 * well here we trevel 32 pixel to the right and to the bottom so we can
 * draw rectangles
 */
void	create_map(void)
{
	data	info;
	int		i;
	int		j;
	int		x;
	int		y;

	info = ft_data(NULL);
	y = 0;
	i = 0;
	while (info.the_map[i] != NULL)
	{
		x = 0;
		j = 0;
		while (info.the_map[i][j] != '\0')
		{
			rec(x, y, info.the_map[i][j]);
			x += SQUARE_SIZE;
			if (info.the_map[i][j + 1] == '\0')
				break ;
			j += 2;
		}
		y += SQUARE_SIZE;
		i++;
	}
}
