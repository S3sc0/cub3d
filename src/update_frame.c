/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:28:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/18 20:29:55 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** checks if the current x and y are a well
*/

int		a_wall(float x, float y, char *which1)
{
	int		i;
	int		j;
	t_data	info;

	info = ft_data(NULL);
	i = floor(x / SQ_SZ);
	y = y < 0 ? 0 : y;
	j = floor(y / SQ_SZ);
	if (which1)
		*which1 = info.the_map[j][i];
	if (info.the_map[j][i] == '1')
		return (1);
	return (0);
}

/*
** here we update x and y of the player
*/

void	update_walk(int key, t_player *plr)
{
	float	wanted_x;
	float	wanted_y;
	int		move_angle;

	if (key == UP_A || key == W_KEY || key == D_KEY)
		plr->walk_d = 1;
	else if (key == DOWN_A || key == S_KEY || key == A_KEY)
		plr->walk_d = -1;
	plr->m_step = plr->walk_d * plr->move_s;
	if (key == A_KEY || key == D_KEY)
		move_angle = norm_a(plr->rotation_a + 90);
	else
		move_angle = plr->rotation_a;
	wanted_x = plr->x + cos(move_angle * RADIN) * plr->m_step;
	wanted_y = plr->y + sin(move_angle * RADIN) * plr->m_step;
	if (a_wall(wanted_x, wanted_y, NULL) == 0)
	{
		plr->x = wanted_x;
		plr->y = wanted_y;
	}
}

/*
** here we update the player's view angle
*/

void	update_turn(int key, t_player *plr)
{
	if (key == LEFT_A)
		plr->turn_d = -1;
	else if (key == RIGHT_A)
		plr->turn_d = 1;
	plr->rotation_a += plr->turn_d * plr->rotation_s;
	plr->rotation_a = (int)norm_a(plr->rotation_a);
}

/*
** this function just redirects to the correct function depends on key
*/

void	update_player(int key)
{
	t_player *plr;

	plr = my_player(0);
	if (key == UP_A || key == DOWN_A || key == W_KEY || key == S_KEY ||
		key == A_KEY || key == D_KEY)
		update_walk(key, plr);
	else if (key == RIGHT_A || key == LEFT_A)
		update_turn(key, plr);
}
