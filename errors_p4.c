#include "cub3d.h"

int	check_empty_line(char *map_data, int ret)
{
	int	i;
	int	map_len;

	map_len = ft_strlen(map_data);
	i = 0;
	if (ret)
	{
		while (map_data[i] != '\n' || map_data[i + 1] != '1')
			i++;
		while (map_data[i] != '\0')
		{
			i++;
			if (i + 2 <= (map_len - 2) && map_data[i] == '1' && map_data[i + 1] == '\n'
				&& map_data[i + 2] == '\n')
			{
				ft_putstr_fd("Something Wrong With The Map's Content\n", 2);
				return (0);
			}
		}
	}
	return (ret);
}

int	only_nbr(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (rgb[i][j] < '0' || rgb[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
