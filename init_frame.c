/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:05:29 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/11 14:06:20 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function detemines which angle our player will face 
int		which_angle(char c)
{
	if (c == 'N')
		return (270);
	else if (c == 'E')
		return (0);
	else if (c == 'S')
		return (90);
	return (180);
}

// initial x and y coordinates of the player
char	coor_xny(player *init)
{
	int		i;
	int		j;
	data	info;
	char	c;

	j = 0;
	info = ft_data(NULL);
	init->y = 0;
	while (info.the_map[j] != NULL)
	{
		i = 0;
		init->x = 0;
		while (info.the_map[j][i] != '\0')
		{
			c = info.the_map[j][i];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				return(c);
			init->x += SQUARE_SIZE;
			i++;
		}
		init->y += SQUARE_SIZE;
		j++;
	}
	return (c);
}

// initial or get the player variable
player	*myPlayer(int state)
{
	static player	*init;
	char			c;

	if (state == 1)
	{
		init = malloc(sizeof(int) * 6 + sizeof(double) * 2);
		c = coor_xny(init);
		init->walkD = 0;
		init->turnD = 0;
		init->moveS = 15;
		init->rotationA = which_angle(c);
		init->rotationS = 10;
		init->mStep = init->walkD * init->moveS;
	}
	return(init);
}


void	count_sprites(data info)
{
	int	x;
	int	y;

	y = 0;
	g_sprite_num = 0;
	while (info.the_map[y] != NULL)
	{
		x = 0;
		while (info.the_map[y][x] != '\0')
		{
			if (info.the_map[y][x] == '2')
				g_sprite_num++;
			x++;
		}
		y++;
	}
}

// initializing all the essential elements of cub3d frame
void	init_frame(int argc, char *argv)
{
	data	info;
	int		a[2];

	open_window();
	info = ft_data(NULL);
	count_sprites(info);
	g_img_ptr = mlx_new_image(g_mlx_ptr, info.wx, info.wy);
	g_img_data = (int*)mlx_get_data_addr(g_img_ptr, &a[0], &g_line, &a[1]);
	myPlayer(1);
	frame_render();
	export_bmp(argv, argc, info.wx, info.wy);
}
