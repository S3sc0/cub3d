/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:24:28 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/20 14:40:46 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_empty_line(char *map_data, int ret)
{
	int		i;
	int		map_len;

	map_len = ft_strlen(map_data);
	i = 0;
	if (ret)
	{
		while ((map_data[i] != '\n' && map_data[i] != '\0') || 
			(map_data[i + 1] != '1' && map_data[i + 1] != ' '))
			i++;
		if (map_data[i] == '\0')
		{
			ft_putstr_fd("Error\nThe Map Doesn't Exist\n", 2);
			ret = 0;
		}
		while (map_data[i++] != '\0')
		{
			if (i + 2 <= (map_len - 2) && map_data[i] == '1'
				&& map_data[i + 1] == '\n' && map_data[i + 2] == '\n')
			{
				ft_putstr_fd("Error\nMap's Content Is Wrong !\n", 2);
				return (0);
			}
		}
	}
	return (ret);
}

int		only_nbr(char **rgb)
{
	int		i;
	int		j;

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

/*
** So In This Function We Check These Errors:
** 1. Repetitive Elements
** 2. Not Allowed Characters In The Whole File
** 3. If There A Space But It Isn't Ended With One
*/

int		check_repetative_paths(char *map, int i, int ret)
{
	static	int	path_counter[5];
	int			j;
	int			res;

	j = 0;
	res = 0;
	if (ret == 1)
	{
		if (!ft_memcmp((map + i), "NO", 2))
			path_counter[0] += 1;
		else if (!ft_memcmp((map + i), "SO", 2))
			path_counter[1] += 1;
		else if (!ft_memcmp((map + i), "WE", 2))
			path_counter[2] += 1;
		else if (!ft_memcmp((map + i), "EA", 2))
			path_counter[3] += 1;
		else if (map[i] == 'S')
			path_counter[4] += 1;
	}
	while (j < 5)
		res += path_counter[j++];
	return (res);
}

int		check_after_newline(char *map, int *i, int ret)
{
	if (map[*i] != 'R' && map[*i] != 'C' && map[*i] != 'F' && map[*i] != 'S'
		&& map[*i] != '\n' && map[*i] != ' ' && map[*i] != '1' &&
		ft_memcmp((map + *i), "NO", 2) && ft_memcmp((map + *i), "SO", 2) &&
		ft_memcmp((map + *i), "WE", 2) && ft_memcmp((map + *i), "EA", 2))
		ret = 2;
	check_repetative_paths(map, *i, ret);
	if (ret == 1 && map[*i] == ' ')
	{
		while (map[*i] != '1' && map[*i] != '\n')
			(*i)++;
		if (map[*i] != '1')
			ret = 3;
	}
	while (map[*i] != '\n')
		(*i)++;
	while (map[*i] == '\n')
		(*i)++;
	return (ret);
}

int		unallowd_elements_check(char *map)
{
	int		ret;
	int		i;

	ret = 1;
	i = 0;
	if (map[i] != 'R' && map[i] != 'C' && map[i] != 'F' && map[i] != 'S' &&
		map[i] != '\n' && ft_memcmp(map, "NO", 2) && ft_memcmp(map, "SO", 2)
		&& ft_memcmp(map, "WE", 2) && ft_memcmp(map, "EA", 2))
		ret = 2;
	check_repetative_paths(map, i, ret);
	while (map[i] != '\n')
		i++;
	while (map[i] == '\n')
		i++;
	while (map[i] != '\0' && ret == 1)
		ret = check_after_newline(map, &i, ret);
	ret = printf_error_message(ret, check_repetative_paths(map, i, 0));
	return (ret);
}
