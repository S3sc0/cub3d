/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:36:03 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/21 16:50:15 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		space_validating(char **lines, int x, int *y, int max_y)
{
	int		ret;
	int		tmp;

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
	return (ret);
}

int		vertical_check(char **lines, int max_y, int ret)
{
	int		x;
	int		y;
	int		max_x;

	x = 0;
	max_x = longest_x(lines, max_y);
	max_y--;
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

int		check_the_rest(int origin, int line_len, char **lines, int id)
{
	int		ret;
	int		j;

	j = origin;
	ret = 1;
	while (j <= line_len && lines[id][j] != '\0' && ret)
	{
		if (j < line_len && j == origin)
			j += 1;
		if (lines[id][j] != '1')
			ret = 0;
		j++;
	}
	return (ret);
}

int		print_error_message(int ret, int number_of_paths)
{
	if (ret != 1)
	{
		if (ret == 2)
			ft_putstr_fd("Error\nLine Starts With An Unallowed Character\n", 2);
		else if (ret == 3)
			ft_putstr_fd("Error\nThere's An Invalid Line\n", 2);
		ret = 0;
	}
	else if (number_of_paths > 5 || number_of_paths < 5)
	{
		ft_putstr_fd("Error\nSomething Wrong With The Path Element\n", 2);
		ret = 0;
	}
	return (ret);
}
