#include "cub3d.h"

int	check_start_line(char **lines, int id, int max)
{
	int		i;
	int		ret;
	static int	sign;
	int		j;
	int		rounds;

	rounds = 1;
	i = 0;
	ret = 1;
	while (lines[id][i] != '1')
		if (lines[id][i++] != ' ')
			ret = 0;
	if (sign == id && id != 0)
		rounds++;
	if (max != id + 1 && lines[id + 1][i] == ' ')
		sign = id + 1;
	while (rounds-- && ret && max != id + 1 && (j = i + 1))
	{
		id += 1;
		while (j-- && ret)
			if (lines[id][j] != ' ' && lines[id][j] != '1')
				ret = 0;
		id -= 3;
	}
	return (ret);
}

int	check_end_line(char **lines, int id, int max, int ret)
{
	int		i;
	static int	sign;
	int		j;
	int		rounds;
	int		second_line_len;

	rounds = 1;
	i = ft_strlen(lines[id]) - 1;
	second_line_len = max != id + 1 ? ft_strlen(lines[id + 1]) : ft_strlen(lines[id]);
	second_line_len--;
	if (sign == id && id != 0)
		rounds++;
	if (max != id + 1 && i > second_line_len)
		sign = id + 1;
	while (rounds-- && ret && max != id + 1 && (j = i))
	{
		id += 1;
		while (j <= second_line_len && lines[id][j] != '\0' && ret)
			if (lines[id][j++] != '1')
				ret = 0;
		if (rounds == 1)
			second_line_len = ft_strlen(lines[id - 2]);
		id -= 3;
	}
	return (ret);
}

int	check_line_horizontally(char *line, int id, int max, int ret)
{
	static	int	players;

	while (*line != '\0' && ret)
	{
		if (*line == 'E' || *line == 's' || *line == 'N' || *line == 'W')
			players++;
		if (*line == ' ')
		{
			if (*(line - 1) != '1')
				ret = 0;
			while (*line != '1' && ret)
			{
				if (*line != ' ')
					ret = 0;
				line++;
			}
		}
		else
			line++;
	}
	if ((id == max - 2 && players == 0) || players > 1)
		ret = 0;
	return (ret);
}

int	horizontal_check(char *line, int id, int max, int ret)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] == ' ')
		i++;
	j = i - 1;
	if (id == 0 || id == max - 1)
	{
		while (line[i] != '\0' && ret)
		{
			if (line[i] != '1' && line[i] != ' ')
				ret = 0;
			i++;
		}
	}
	else
	{
		while (line[++j] != '\0' && ret)
			if (line[j] != ' ' && line[j] != '1' && line[j] != '2'
			&& line[j] != '0' && line[j] != 'E' && line[j] != 's'
			&& line[j] != 'W' && line[j] != 'N')
				ret = 0;
		ret = check_line_horizontally((line + i), id, max, ret);
	}
	return (ret);
}

int	longest_x(char **lines, int max)
{
	int	y;
	int	x;
	int 	tmp;


	y = 1;
	x = ft_strlen(lines[0]);
	g_x_len = (int*)malloc(sizeof(int) * max);
	g_x_len[0] = x;
	while (y < max)
	{
		tmp = x;
		x = ft_strlen(lines[y]);
		g_x_len[y] = x;
		if (tmp > x)
			x = tmp;
		y++;
	}
	return (x);
}

int	space_validating(char **lines, int x, int *y, int max_y)
{
	int	ret;
	int	tmp;

	tmp = *y;
	ret = 1;
	if (*y != 0 && lines[*y - 1][x] != '1')
		ret = 0;
	while (x <= g_x_len[*y] && lines[*y][x] != '1' && *y != max_y && ret)
	{
		if (lines[*y][x] != ' ')
			ret = 0;
		(*y)++;
	}
	if (x > g_x_len[*y] && lines[--(*y)][x] == ' ')
		ret = 0;
	if (ret && tmp == 0 && *y == max_y && lines[*y][x] != 1)
		ret = 0;
	return (ret);
}

int	vertical_check(char **lines, int max_y, int ret)
{
	int	x;
	int	y;
	int	max_x;
	
	x = 0;
	max_x = longest_x(lines, max_y);
	max_y--; // i think it goes over the scope so i minimized it
	while (x < max_x && ret)
	{
		y = 0;
		while (y < max_y && ret)
		{
			if (x <= g_x_len[y])
			{
				if (lines[y][x] == ' ')
					ret = space_validating(lines, x, &y, max_y);
			}
			y++;
		}
		x++;
	}
	free(g_x_len);
	return (ret);
}
