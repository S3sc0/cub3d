/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:28:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/27 14:59:22 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_frame_black(void)
{
	data	info;
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

// here we update x and y of the player
void	update_walk(int key, player *plr)
{
	if (key == 126)
		plr->walkD = 1;
	else if (key == 125)
		plr->walkD = -1;
	plr->mStep = plr->walkD * plr->moveS;
	plr->x += cos(plr->rotationA * RADIN) * plr->mStep;
	plr->y += sin(plr->rotationA * RADIN) * plr->mStep;
}

// here we update the player's view angle
void	update_turn(int key, player *plr)
{
	if (key == 123)
		plr->turnD = -1;
	else if (key == 124)
		plr->turnD = 1;
	plr->rotationA += plr->turnD * plr->rotationS;
}

// this function just redirects to the correct function depends on key
void	update_player(int key)
{
	player *plr;

	plr = myPlayer(0);
	if (key == 126 || key == 125)
		update_walk(key, plr);
	else if (key == 124 || key == 123)
		update_turn(key, plr);
}
