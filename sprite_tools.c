#include "cub3d.h"

float	calc_sp_x_start(sprite **sprt, player plr, data info, crd sprite)
{
	float	x;
	float	sp_angle;
	float	pixel_num;

	sp_angle = normA(atan((sprite.y - plr.y) / (sprite.x - plr.x)) * (180 / M_PI));
	sp_angle = normA(sp_angle - (plr.rotationA - 30));
	pixel_num = FOV_ANGLE / (float)info.wx;
	x = sp_angle / pixel_num;
	return (x);
}

void	put_texture_img(int strip, int y, data info, sprite sprt)
{
	int	tex_x;
	int	tex_y;
	int	d;
	int	tmp;

	d = strip - (info.wx / 2);
	tex_x = d * (64.0 / sprt.height);
	tex_x *= tex_x < 0 ? -1 : 1;
	tmp = sprt.height;
	sprt.height = sprt.height > info.wy ? info.wy : sprt.height;
	while (y < sprt.hi_e)
	{
		d = y + (tmp / 2) - (info.wy / 2);
		tex_y = d * (64.0 / tmp);
		if (info.S[64 * tex_y + tex_x] != 0)
			g_img_data[y * info.wx + strip] = info.S[64 * tex_y + tex_x];
		y++;
	}
}

void	draw_sprite_texture(sprite sprt, data info, int i)
{
	int	strip;
	int	tex_x;
	int	tex_y;
	int	y;

	strip = sprt.wi_s;
	while (strip < sprt.wi_e)
	{
		tex_x = strip % SQUARE_SIZE;
		y = sprt.hi_s;
		if (strip > 0 && strip < info.wx && g_sprite_distance[i] < g_wall_distance[strip])
		{
			while (y < sprt.hi_e)
			{
				put_texture_img(strip, y, info, sprt);
				y++;
			}
		}
		strip++;
	}
}
