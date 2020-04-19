#include "cub3d.h"

void	store_sprite_position(crd *sprites, data info)
{
	int	x;
	int	y;

	x = 0;
	g_sprite_num = 0;
	while (info.the_map[x] != NULL)
	{
		y = 0;
		while (info.the_map[x][y] != '\0')
		{
			if (info.the_map[x][y] == '2')
			{
				sprites[g_sprite_num].x = x * SQUARE_SIZE;
				sprites[g_sprite_num].y = y * SQUARE_SIZE;
				g_sprite_num++;
			}
			y++;
		}
		x++;
	}
}

void	initial_sprite_properties(crd *sprites, player plr)
{
	int	i;

	i = 0;
	g_sprite_distance = (float *)malloc(sizeof(float) * g_sprite_num);
	while (i < g_sprite_num)
	{
		g_sprite_distance[i] = sqrt(pow(plr.x - sprites[i].x, 2) + pow(plr.y - sprites[i].y, 2));
		i++;
	}
}

void	sort_sprites(crd **sprites)
{
	int	i;
	int	j;
	float	tmp_distance;
	float	tmp_sprites;

	i = 0;
	while (i < g_sprite_num)
	{
		j = i+1;
		while (j < g_sprite_num)
		{
			if (g_sprite_distance[i] > g_sprite_distance[j])
			{
				tmp_distance = g_sprite_distance[i];
				tmp_sprites = (*sprite)[i];
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

void	calc_sprite_info(sprite *sprt, player plr, data info, crd *sprites)
{
	int	sprite_height;
	float	dpp;
	
	dpp = (info.wx / 2) * tan((FOV_ANGLE / 2) * RADIN);
	sprite_height = (SQUARE_SIZE / g_sprite_distance[sprt->i]) * dpp;
	// initialize Sprite X and Y
	sprt->x = sprites[sprt->i].x - plr.x;
	sprt->y = sprites[sprt->i].y - plr.y;
	// calc where to start and end painting sprite in height
	sprt->hi_s = -sprite_height / 2 + info.wy / 2;
	sprt->hi_s = sprt->hi_s < 0 ? 0 : sprt->hi_s;
	sprt->hi_e = sprite_height / 2 + info.wy / 2;
	sprt->hi_e = sprt->hi_e > info.wy ? info.wy - 1 : sprt->hi_e;
	// calc where to start and end painting sprite in width
	sprt->wi_s = -sprite_height / 2 + info.wx / 2;
	sprt->wi_s = sprt->wi_s < 0 ? 0 : sprt->wi_s;
	sprt->wi_e = sprite_height / 2 + info.wx / 2;
	sprt->wi_e = sprt->wi_e > info.wx ? info.wx - 1 : sprt->wi_e;
}

void	draw_sprite(player plr, data info)
{
	sprite	sprt;
	crd	*sprites;

	sprites = (crd *)malloc(sizeof(crd) * 5);
	store_sprite_position(sprites, info);
	initial_sprite_properties(sprites, plr);
	sort_sprites(&sprites);
	sprt.i = 0;
	while (sprt.i < g_sprite_num)
	{
		calc_sprite_info(&sprt, plr, info, sprites);
		sprt.i++;
	}
}
