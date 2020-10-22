/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:59:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/22 14:07:46 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_resolution(char *s)
{
	char	**str;
	int		i;
	int		ret;

	ret = 1;
	i = -1;
	str = ft_split((s + 1), ' ');
	if (count_items(str) != 3)
		ret = 0;
	if (ret != 0)
	{
		while (str[1][++i] != '\0')
			if ((str[1][i] < '0' || str[1][i] > '9') && (ret = 0))
				break ;
		i = -1;
		while (str[2][++i] != '\0')
			if ((str[2][i] < '0' || str[2][i] > '9') && (ret = 0))
				break ;
	}
	if (ret == 0)
		ft_putstr_fd("Error\nSomething Wrong With The Resolution Element\n", 2);
	free_2d(str);
	return (ret);
}

/*
** this functino checks if the string starts with the right identifier
*/

int		check_name(char *s)
{
	int		ret;

	ret = 0;
	if (ft_memcmp(s, "R", 1) == 0)
		ret = 1;
	else if (ft_memcmp(s, "NO", 2) == 0)
		ret = 2;
	else if (ft_memcmp(s, "EA", 2) == 0)
		ret = 2;
	else if (ft_memcmp(s, "SO", 2) == 0)
		ret = 2;
	else if (ft_memcmp(s, "WE", 2) == 0)
		ret = 2;
	else if (ft_memcmp(s, "S", 1) == 0)
		ret = 2;
	else if (ft_memcmp(s, "F", 1) == 0)
		ret = 3;
	else if (ft_memcmp(s, "C", 1) == 0)
		ret = 3;
	if (ret == 0 && *s != ' ' && *s != '1' && *s != '\t')
	{
		printf("%s\n", s);
		ft_putstr_fd("Error\nWrong Identifier Name\n", 2);
		exit(0);
	}
	return (ret);
}

/*
** this function check if the path contains only two parts
*/

int		check_path(char *s)
{
	char	**str;

	str = split_from_identifier(s);
	if (count_items(str) != 2)
	{
		ft_putstr_fd("Error\nSomething Wrong With The Path Element\n", 2);
	}
	free_2d(str);
	return (1);
}

/*
** this function checks if the RGB color content
** is perfectly correct like cell and floor
*/

int		check_rgb(char *s)
{
	int		ret;
	char	**str;
	char	**rgb;
	int		i;

	i = -1;
	str = split_from_identifier(s);
	rgb = ft_split(str[1], ',');
	ret = 1;
	if (count_items(str) != 2 || count_items(rgb) != 3 || commas(str[1]) > 2)
		ret = 0;
	else if (only_nbr(rgb) == 0)
		ret = 0;
	else
		while (++i < 3)
			if ((ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255) && (ret = 0))
				break ;
	if (ret == 0)
		ft_putstr_fd("Error\nSomething Wrong In The Cell Or Floor Elmnts\n", 2);
	free_2d(rgb);
	free_2d(str);
	return (ret);
}

/*
** this function will redirect the specified
** information to their functions to be checked
*/

int		check_errors(char *stored_data)
{
	char	**data;
	int		i;
	int		ret;

	i = -1;
	ret = 1;
	data = ft_split(stored_data, '\n');
	while (data[++i] != NULL && ret == 1)
	{
		if (check_name(data[i]) == 1)
			ret = check_resolution(data[i]);
		else if (check_name(data[i]) == 2)
			ret = check_path(data[i]);
		else if (check_name(data[i]) == 3)
			ret = check_rgb(data[i]);
		else if (data[i][0] == '1' || data[i][0] == ' ')
		{
			ret = check_map((data + i), stored_data);
			break ;
		}
	}
	ret = check_empty_line(stored_data, ret);
	ret = map_complete(i, ret);
	free_2d(data);
	return (ret);
}
