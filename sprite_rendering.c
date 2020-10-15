/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:06:51 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/15 17:20:02 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_sprite_position(t_crd *sprites, t_data info)
{
	int		x;
	int		y;
	int		counter;

	counter = 0;
	y = 0;
	while (info.the_map[y] != NULL)
	{
		x = 0;
		while (info.the_map[y][x] != '\0')
		{
			if (info.the_map[y][x] == '2')
			{
				sprites[counter].x = x * SQUARE_SIZE + 32;
				sprites[counter].y = y * SQUARE_SIZE + 32;
				counter++;
			}
			x++;
		}
		y++;
	}
}

void	initial_sprite_properties(t_crd *sprites, t_player plr)
{
	int		i;

	i = 0;
	g_sprite_distance = (float *)malloc(sizeof(float) * g_sprite_num);
	while (i < g_sprite_num)
	{
		g_sprite_distance[i] = sqrt(pow(plr.x - sprites[i].x, 2) +
				pow(plr.y - sprites[i].y, 2));
		i++;
	}
}

void	sort_sprites(t_crd **sprites)
{
	int		i;
	int		j;
	float	tmp_distance;
	t_crd	tmp_sprites;

	i = 0;
	while (i < g_sprite_num)
	{
		j = i + 1;
		while (j < g_sprite_num)
		{
			if (g_sprite_distance[i] < g_sprite_distance[j])
			{
				tmp_distance = g_sprite_distance[i];
				tmp_sprites = (*sprites)[i];
				g_sprite_distance[i] = g_sprite_distance[j];
				(*sprites)[i] = (*sprites)[j];
				g_sprite_distance[j] = tmp_distance;
				(*sprites)[j] = tmp_sprites;
			}
			j++;
		}
		i++;
	}
}

/*
** here we calc start and end of the sprite both in height & width
*/

void	calc_sprite_info(t_sprite *g_sprt, t_player plr,
		t_data info, t_crd *sprites)
{
	float	dpp;

	dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	g_sprt->height = (SQUARE_SIZE / g_sprite_distance[g_sprt->i]) * dpp;
	g_sprt->hi_s = -g_sprt->height / 2 + info.wy / 2;
	g_sprt->hi_s = g_sprt->hi_s < 0 ? 0 : g_sprt->hi_s;
	g_sprt->hi_e = g_sprt->height / 2 + info.wy / 2;
	g_sprt->hi_e = g_sprt->hi_e > info.wy ? info.wy - 1 : g_sprt->hi_e;
	g_sprt->wi_s = calc_sp_x_start(plr, info, sprites[g_sprt->i]) -
				(g_sprt->height / 2);
	g_sprt->wi_e = g_sprt->wi_s + g_sprt->height;
}

void	draw_sprite(t_player plr, t_data info)
{
	t_sprite	g_sprt;
	t_crd		*sprites;

	sprites = (t_crd *)malloc(sizeof(t_crd) * g_sprite_num);
	store_sprite_position(sprites, info);
	initial_sprite_properties(sprites, plr);
	sort_sprites(&sprites);
	g_sprt.i = 0;
	while (g_sprt.i < g_sprite_num)
	{
		calc_sprite_info(&g_sprt, plr, info, sprites);
		draw_sprite_texture(g_sprt, info, g_sprt.i);
		g_sprt.i++;
	}
	free(g_sprite_distance);
	free(g_wall_distance);
	free(sprites);
}
