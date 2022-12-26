/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:05:29 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/25 16:42:27 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** this function detemines which angle our player will face
*/

int			which_angle(char c)
{
	if (c == 'N')
		return (270);
	else if (c == 'E')
		return (0);
	else if (c == 'S')
		return (90);
	return (180);
}

/*
** initializing the  x and y coordinates of the player
*/

char		coor_xny(t_player *init)
{
	int		i;
	int		j;
	t_data	info;
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
				return (c);
			init->x += SQ_SZ;
			i++;
		}
		init->y += SQ_SZ;
		j++;
	}
	return (c);
}

/*
** initialize the t_player members then we can
** get the structrue anytime
*/

t_player	*my_player(int state)
{
	static	t_player	*init;
	char				c;

	if (state == 1)
	{
		init = malloc(sizeof(int) * 6 + sizeof(double) * 2);
		c = coor_xny(init);
		init->walk_d = 0;
		init->turn_d = 0;
		init->move_s = 15;
		init->rotation_a = which_angle(c);
		init->rotation_s = 10;
		init->m_step = init->walk_d * init->move_s;
	}
	return (init);
}

void		count_sprites(t_data info)
{
	int		x;
	int		y;

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

/*
** initializing all the essential elements of cub3d frame
*/

void		init_frame(int argc)
{
	t_data	info;
	int		a[2];

	if (argc == 2)
		open_window();
	info = ft_data(NULL);
	count_sprites(info);
	g_img_ptr = mlx_new_image(g_mlx_ptr, info.wx, info.wy);
	g_img_data = (int*)mlx_get_data_addr(g_img_ptr, &a[0], &g_line, &a[1]);
	my_player(1);
	frame_render(argc);
}
