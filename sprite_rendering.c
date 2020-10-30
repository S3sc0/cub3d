/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:06:51 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/30 10:11:32 by aamzouar         ###   ########.fr       */
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
				sprites[counter].x = x * SQ_SZ + 32;
				sprites[counter].y = y * SQ_SZ + 32;
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

void	calc_sprite_info(t_sprite *sprt, t_player plr,
		t_data info, t_crd *sprites)
{
	float	dpp;

	dpp = (info.wx / 2) / tan((FOV_ANGLE * RADIN) / 2);
	sprt->height = (SQ_SZ / g_sprite_distance[sprt->i]) * dpp;
	sprt->hi_s = -sprt->height / 2 + info.wy / 2;
	sprt->hi_s = sprt->hi_s < 0 ? 0 : sprt->hi_s;
	sprt->hi_e = sprt->height / 2 + info.wy / 2;
	sprt->hi_e = sprt->hi_e > info.wy ? info.wy - 1 : sprt->hi_e;
	sprt->wi_s = calc_sp_x_start(plr, info, sprites[sprt->i]) -
				(sprt->height / 2);
	sprt->wi_e = sprt->wi_s + sprt->height;
}

void	draw_sprite(t_player plr, t_data info)
{
	t_sprite	sprt;
	t_crd		*sprites;

	sprites = (t_crd *)malloc(sizeof(t_crd) * g_sprite_num);
	store_sprite_position(sprites, info);
	initial_sprite_properties(sprites, plr);
	sort_sprites(&sprites);
	sprt.i = 0;
	while (sprt.i < g_sprite_num)
	{
		calc_sprite_info(&sprt, plr, info, sprites);
		draw_sprite_texture(sprt, info, sprt.i);
		sprt.i++;
	}
	free(g_sprite_distance);
	free(g_wall_distance);
	free(sprites);
}
