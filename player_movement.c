/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:13:45 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/25 16:10:12 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// here on this function we implement player movement
int		movement(int key, player *init)
{
	if (key == 123 || key == 124)
	{
		if (key == 123)
			init->turnD = -1;
		else
			init->turnD = 1;
		init->rotationA += init->turnD * init->rotationS;
	}
	else if (key == 126 || key == 125)
	{
		rec(init->x, init->y, '1', 0x000000);
		if (key == 126)
			init->walkD = -1;
		else
			init->walkD = 1;
		init->mStep = init->walkD * init->moveS;
		init->x += cos(init->rotationA) * init->mStep;
		init->y += sin(init->rotationA) * init->mStep;
		rec(init->x, init->y, '1', 0x51358C);
	}
	return (0);
}

// this function just initialize the variable of type player
void	player2D(char sym, int x, int y)
{
	player *init;

	init = malloc(sizeof(player));
	if (sym == 'N' || sym == 'S' || sym == 'E' || sym == 'W')
	{
		init->x = x;
		init->y = y;
		init->walkD = 0;
		init->turnD = 0;
		init->rotationA = M_PI / 2;
		init->rotationS = 5 * (M_PI / 180);
		init->moveS = 5;
		rec(init->x, init->y, '1', 0x51358C);
		mlx_hook(g_win_ptr, 2, 0, &movement, init);
	}
}
