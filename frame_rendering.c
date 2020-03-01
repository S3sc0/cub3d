/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:51:34 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/01 15:54:43 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// draw a line which show our player point of view
void	line(player plr, int color)
{
	int i;
	double x;
	double y;

	x = plr.x;
	y = plr.y;
	i = 0;
	while (i < 25)
	{
		x += cos(plr.rotationA * RADIN);
		y += sin(plr.rotationA * RADIN);
		put_pixel_img(x, y, color);
		i++;
	}
}

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
				rec(x, y, 0x6F04D9);
			x += SQUARE_SIZE;
			i++;
		}
		y += SQUARE_SIZE;
		j++;
	}
}

// draw the player
void	player_render(player plr)
{
	line(plr, 0xF20505);
}

// this which draws the whole frame in the screen
void	frame_render(void)
{
	data	f;
	player	plr;

	f = ft_data(NULL);
	plr = *myPlayer(0);
	map_render(f.the_map);
	player_render(plr);
	rays(plr, f);
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr, 0, 0);
}
