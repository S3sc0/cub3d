/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:51:34 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/27 14:09:51 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// the function which draws squares
void	rec(int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			put_pixel_img(x + i, y + j, color);
			j++;
		}
		i++;
	}
}

// draw the 2D map
void	map_render(char **map)
{
	int		i;
	int		j;
	int		x;
	int		y;

	j = 0;
	y = 0;
	while (map[j] != NULL)
	{
		i = 0;
		x = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == '1' || map[j][i] == '2')
				rec(x, y, 0xFFFFFF);
			x += SQUARE_SIZE;
			if (map[j][i + 1] == '\0')
				break ;
			i += 2;
		}
		y += SQUARE_SIZE;
		j++;
	}
}

// draw the player
void	player_render(void)
{
	player plr;

	plr = *myPlayer(0);
	rec(plr.x, plr.y, 0xF20505);
}

// this which draws the whole frame in the screen
void	frame_render(void)
{
	data f;

	f = ft_data(NULL);
	map_render(f.the_map);
	player_render();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr, 0, 0);
}
