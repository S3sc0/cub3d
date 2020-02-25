/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:39:49 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/25 15:07:51 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function just draws rectangles
void	rec(int x, int y, char sym, int color)
{
	int		i;
	int		j;

	i = 0;
	if (sym == '1' || sym == '2')
	{
		while (i < SQUARE_SIZE)
		{
			j = 0;
			while (j < SQUARE_SIZE)
			{
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, x + i, y + j, color);
				j++;
			}
			i++;
		}
	}
}

// here we just go through x raw and redirect to "rec" function
void	check_2Dmap(int i, int y, data info)
{
	int		j;
	int		x;

	j = 0;
	x = 0;
	while (info.the_map[i][j] != '\0')
	{
		rec(x, y, info.the_map[i][j], 0xE84D6C);
		x += SQUARE_SIZE;
		player2D(info.the_map[i][j], x, y);
		if (info.the_map[i][j + 1] == '\0')
			break ;
		j += 2;
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
	int		y;

	info = ft_data(NULL);
	y = 0;
	i = 0;
	while (info.the_map[i] != NULL)
	{
		check_2Dmap(i, y, info);
		y += SQUARE_SIZE;
		i++;
	}
}
