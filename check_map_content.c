/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:09:41 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/19 17:34:12 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_start_line(char **lines, int id, int max)
{
	int			i;
	int			ret;
	static int	sign;
	int			j;
	int			rounds;

	rounds = 1;
	i = 0;
	ret = 1;
	while (lines[id][i] != '1' && ret)
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

int		check_end_line(char **lines, int id, int max, int ret)
{
	int			i;
	static int	sign;
	int			rounds;
	int			line_len;

	rounds = 1;
	i = ft_strlen(lines[id]) - 1;
	line_len = max != id + 1 ? ft_strlen(lines[id + 1]) : ft_strlen(lines[id]);
	line_len--;
	if (sign == id && id != 0)
		rounds++;
	if (max != id + 1 && i > line_len)
		sign = id + 1;
	while (rounds-- && ret && max != id + 1)
	{
		id += 1;
		ret = check_the_rest(i, line_len, lines, id);
		if (rounds == 1)
			line_len = ft_strlen(lines[id - 2]);
		id -= 3;
	}
	return (ret);
}

int		check_line_horizontally(char *line, int id, int max, int ret)
{
	static	int	players;

	while (*line != '\0' && ret)
	{
		if (*line == 'E' || *line == 'S' || *line == 'N' || *line == 'W')
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

int		horizontal_check(char *line, int id, int max, int ret)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] == ' ')
		i++;
	j = i - 1;
	if (id == 0 || id == max - 1)
	{
		while (line[i] != '\0' && ret)
		{
			if (line[i] != '1' && line[i] != ' ')
				return (0);
			i++;
		}
	}
	else
	{
		while (line[++j] != '\0' && ret)
			if (line[j] != ' ' && line[j] != '1' && line[j] != '2'
			&& line[j] != '0' && line[j] != 'E' && line[j] != 'S'
			&& line[j] != 'W' && line[j] != 'N')
				return (0);
	}
	return (check_line_horizontally((line + i), id, max, ret));
}

int		longest_x(char **lines, int max)
{
	int		y;
	int		x;
	int		tmp;

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
