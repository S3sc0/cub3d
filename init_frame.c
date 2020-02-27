/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:05:29 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/27 15:23:01 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// initial x and y coordinates of the player
void	coor_xny(player *init)
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
				return ;
			if (info.the_map[j][i + 1] == '\0')
				break ;
			init->x += SQUARE_SIZE;
			i += 2;
		}
		init->y += SQUARE_SIZE;
		j++;
	}
}

// initial or get the player variable
player	*myPlayer(int state)
{
	static player	*init;

	if (state == 1)
	{
		init = malloc(sizeof(int) * 6 + sizeof(double) * 2);
		coor_xny(init);
		init->walkD = 0;
		init->turnD = 0;
		init->moveS = 10;
		init->rotationA = 270;
		init->rotationS = 10;
		init->mStep = init->walkD * init->moveS;
	}
	return(init);
}

// initializing all the essential elements of cub3d frame
void	init_frame(void)
{
	data	info;
	int		a[2];

	open_window();
	info = ft_data(NULL);
	g_img_ptr = mlx_new_image(g_mlx_ptr, info.wx, info.wy);
	g_img_data = (int*)mlx_get_data_addr(g_img_ptr, &a[0], &g_line, &a[1]);
	myPlayer(1);
	frame_render();
}
