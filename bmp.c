#include "cub3d.h"

void	check_bmp_errors(int fd, char *flag)
{
	int	length;

	length = ft_strlen(flag);	
	if (fd < 0 || ft_memcmp(flag, "--save", length) != 0)
	{
		ft_putstr_fd("Something wrong can't export the bmp image\n", 1);
		exit(1);
	}
}

void	write_header(int fd, int width, int height)
{
	unsigned int size;
	unsigned int first_pixel;

	first_pixel = 54;
	size = (height * width) * 3 + 54;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pixel, 4);
}

void	write_info_header(int fd, int width, int height)
{
	unsigned int	headersize;
	unsigned short	plane;
	unsigned short	bits_per_pixel;

	headersize = 40;
	plane = 1;
	bits_per_pixel = 24;
	write(fd, &headersize, 4);
	write(fd, &width, 4);
	write(fd, &height, 4);
	write(fd, &plane, 2);
	write(fd, &bits_per_pixel, 2);
	while (plane <= 24)
	{
		write(fd, "\0", 1);
		plane++;
	}
}

void	write_pixel_color(int fd, int width, int height)
{
	int	x;
	int	y;

	y = height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < width)
		{
			write(fd, &g_img_data[x + y * (g_line / 4)], 3);
			x++;
		}
		y--;
	}
}

void	export_bmp(char *flag, int argc, int width, int height)
{
	int	fd;

	if (argc == 3)
	{
		fd = open("image.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
		check_bmp_errors(fd, flag);
		write_header(fd, width, height);
		write_info_header(fd, width, height);
		write_pixel_color(fd, width, height);
		close(fd);
		exit(0);
	}
}
