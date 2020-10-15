/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:51:34 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/15 10:00:03 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// draw a line which show our t_player point of view
void	line(t_player plr, int color)
{
	int i;
	double x;
	double y;

	x = plr.x;
	y = plr.y;
	i = 0;
	while (i < 25)
	{
		x += cos(plr.rotation_a * RADIN);
		y += sin(plr.rotation_a * RADIN);
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

// draw the t_player
void	player_render(t_player plr)
{
	line(plr, 0xF20505);
}

// draw the cell and floor
void	draw_background(t_data info)
{
	int		x;
	int		y;

	y = 0;
	while (y < info.wy / 2)
	{
		x = 0;
		while (x < info.wx)
		{
			put_pixel_img(x, y, info.cell);
			x++;
		}
		y++;
	}
	while (y < info.wy)
	{
		x = 0;
		while (x < info.wx)
		{
			put_pixel_img(x, y, info.floor);
			x++;
		}
		y++;
	}
}

// this which draws the whole frame in the screen
void	frame_render(int argc, char *argv)
{
	t_data	f;
	t_player	plr;

	f = ft_data(NULL);
	plr = *my_player(0);
	//map_render(f.the_map);
	//player_render(plr);
	draw_background(f);
	rays(plr, f);
	draw_sprite(plr, f);
	if (argc == 3)
		export_bmp(argv, argc, f.wx, f.wy);
	else
		mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr, 0, 0);
}
