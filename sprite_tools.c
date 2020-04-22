#include "cub3d.h"

void	norm_player_angle(void)
{
	if (g_player_angle >= 330)
		g_player_angle -= 360;
	else if (g_player_angle <= -330)
		g_player_angle += 360;
}

float	calc_sp_x_start(player plr, data info, crd sprite)
{
	float	x;
	float	sp_angle;
	float	pixel_num;

	sp_angle = atan2((sprite.y)- plr.y, (sprite.x)- plr.x) * (180 / M_PI);
	norm_player_angle();
	sp_angle = sp_angle - (g_player_angle - 30);
	printf("%d %d\n", plr.rotationA, g_player_angle);
	pixel_num = FOV_ANGLE / (float)info.wx;
	x = sp_angle / pixel_num;
	return (x);
}

void	draw_sprite_texture(sprite sprt, data info, int i)
{
	int	strip;
	int	tex_x;
	int	tex_y;
	int	y;
	int	d;

	strip = sprt.wi_s;
	while (strip < sprt.wi_e && sprt.wi_s < info.wx)
	{
		tex_x = (256 * (strip - sprt.wi_s) * SQUARE_SIZE / sprt.height) / 256;
		y = sprt.hi_s;
		if (strip >= 0 && strip <= info.wx && g_sprite_distance[i] < g_wall_distance[strip])
		{
			while (y < sprt.hi_e)
			{
				d = y + (sprt.height / 2) - (info.wy / 2);
				tex_y = d * (64.0 / sprt.height);
				if (info.S[64 * tex_y + tex_x] != 0)
					g_img_data[y * info.wx + strip] = info.S[64 * tex_y + tex_x];
				y++;
			}
		}
		strip++;
	}
}
