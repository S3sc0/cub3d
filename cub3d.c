#include "cub3d.h"

void	rectangle(int color)
{
	int midx;
	int midy;
	int y;
	int x;

	x = 0;
	midx = (wx - rx) / 2;
	midy = (wy - ry) / 2;
	while (x < rx)
	{
		y = 0;
		while (y < ry)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, midx + x, midy + y, color);
			y++;
		}
		x++;
	}
}

int	zome(int key, void *param)
{
	rectangle(0x000000);
	if (key == 65362)
	{
		rx += 10;
		ry += 10;
	}
	else if (key == 65364)
	{
		rx -= 10;
		ry -=10;
	}
	rectangle(0x7C05F2);
	return (0);
}

int		main(void)
{
	rx = 240;
	ry = 240;
	wx = 1024;
	wy = 768;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, wx, wy, "cub3d");
	//draw_lines(0xD95284);
	mlx_key_hook(win_ptr, zome, (void*)0);
	mlx_loop(mlx_ptr);
	return (0);
}
