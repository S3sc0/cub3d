#include "cub3d.h"

float	calc_sp_x_start(t_player plr, t_data info, t_crd t_sprite)
{
	float	x;
	float	sp_angle;
	float	pixel_num;

	sp_angle = norm_a(atan2((t_sprite.y)- plr.y, (t_sprite.x)- plr.x) * (180 / M_PI));
	plr.rotation_a = (int)norm_a(plr.rotation_a - 30);
	sp_angle = sp_angle - plr.rotation_a;
	sp_angle = norm_a(sp_angle);
	pixel_num = FOV_ANGLE / (float)info.wx;
	x = sp_angle / pixel_num;
	return (x);
}

void	draw_sprite_texture(t_sprite g_sprt, t_data info, int i)
{
	int	strip;
	int	tex_x;
	int	tex_y;
	int	y;
	int	d;

	strip = g_sprt.wi_s;
	while (strip < g_sprt.wi_e && g_sprt.wi_s < info.wx)
	{
		tex_x = (256 * (strip - g_sprt.wi_s) * SQUARE_SIZE / g_sprt.height) / 256;
		y = g_sprt.hi_s;
		if (strip >= 0 && strip <= info.wx && g_sprite_distance[i] < g_wall_distance[strip])
		{
			while (y < g_sprt.hi_e)
			{
				d = y + (g_sprt.height / 2) - (info.wy / 2);
				tex_y = d * (64.0 / g_sprt.height);
				if (info.s[64 * tex_y + tex_x] != 0)
					g_img_data[y * info.wx + strip] = info.s[64 * tex_y + tex_x];
				y++;
			}
		}
		strip++;
	}
}
