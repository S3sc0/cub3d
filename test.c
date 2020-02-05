#include <stdio.h>
#include <mlx.h>

void	rectangle(void *mlx_ptr, void *win_ptr, int color, int x, int y)
{
	int tmpY;
	int tmpX;

	tmpY = y;
	tmpX = x;
	while (x < tmpX + 240)
	{
		y = tmpY;
		while (y < tmpY + 240)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			y++;
		}
		x++;
	}
}

int		main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1024, 768, "Windows 10");
	rectangle(mlx_ptr, win_ptr, 0xF2BE22, 783 / 2, 528 / 2);
	mlx_loop(mlx_ptr);
	return (0);
}
