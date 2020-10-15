/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:28:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/15 10:00:03 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// turn the color of the screen to black to refill it with a new frame
void	turn_frame_black(void)
{
	t_data	info;
	int		x;
	int		y;

	info = ft_data(NULL);
	y = 0;
	while (y < info.wy)
	{
		x = 0;
		while (x < info.wx)
		{
			put_pixel_img(x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img_ptr, 0 , 0);
}

// checks if the current x and y are a well
int		a_wall(float x, float y, char *which1)
{
	int		i;
	int		j;
	t_data	info;

	info = ft_data(NULL);
	i = floor(x / SQUARE_SIZE);
	y = y < 0 ? 0 : y;
	j = floor(y / SQUARE_SIZE);
	if (which1)
		*which1 = info.the_map[j][i];
	else if (info.the_map[j][i] == '2')
		return (1);
	if (info.the_map[j][i] == '1')
		return (1);
	return (0);
}

// here we update x and y of the t_player
void	update_walk(int key, t_player *plr)
{
	float	wanted_x;
	float	wanted_y;

	if (key == UP_A || key == W_KEY)
		plr->walk_d = 1;
	else if (key == DOWN_A || key == S_KEY)
		plr->walk_d = -1;
	plr->m_step = plr->walk_d * plr->move_s;
	wanted_x = plr->x + cos(plr->rotation_a * RADIN) * plr->m_step;
	wanted_y = plr->y + sin(plr->rotation_a * RADIN) * plr->m_step;
	if (a_wall(wanted_x, wanted_y, NULL) == 0)
	{
		plr->x = wanted_x;
		plr->y = wanted_y;
	}
}

// here we update the t_player's view angle
void	update_turn(int key, t_player *plr)
{
	if (key == LEFT_A || key == A_KEY)
		plr->turn_d = -1;
	else if (key == RIGHT_A || key == D_KEY)
		plr->turn_d = 1;
	plr->rotation_a += plr->turn_d * plr->rotation_s;
	plr->rotation_a = (int)norm_a(plr->rotation_a);
}

// this function just redirects to the correct function depends on key
void	update_player(int key)
{
	t_player *plr;

	plr = my_player(0);
	if (key == UP_A || key == DOWN_A || key == W_KEY || key == S_KEY)
		update_walk(key, plr);
	else if (key == RIGHT_A || key == LEFT_A || key == A_KEY || key == D_KEY)
		update_turn(key, plr);
}
