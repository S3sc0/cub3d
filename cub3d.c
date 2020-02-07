#include "cub3d.h"

int		rectangle(int key, int color)
{
	int midx;
	int midy;

	midx = (wx - rx) / 2;
	midy = (wy - ry) / 2;
}

int		main(void)
{
	rx = 240;
	ry = 240;
	wx = 1024;
	wy = 768;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, wx, wy, "cub3d");
	mlx_key_hook(win_ptr, rectangle, 0xD95284);
	draw_lines(0xD95284);
	mlx_loop(mlx_ptr);
	return (0);
}
