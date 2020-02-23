/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:59:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/23 16:25:53 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function will check that the resolution data if it's correct
int		check_resolution(char *s)
{
	char	**str;
	int		i;
	int		ret;

	ret = 1;
	i = -1;
	str = ft_split(s, ' ');
	if (count_items(str) != 3) // should only be 3 arguments
		ret = 0;
	if (ret != 0)
	{
		while (str[1][++i] != '\0') // if it's not number return 0
			if ((str[1][i] < '0' || str[1][i] > '9') && (ret = 0))
				break ;
		i = -1;
		while (str[2][++i] != '\0')
			if ((str[2][i] < '0' || str[2][i] > '9') && (ret = 0))
				break ;
	}
	if (ret == 0)
		ft_putstr_fd("Something Wrong With The Resolution Element\n", 2);
	free_2D(str);
	return (ret);
}

// this functino checks if this string starts with the right identifier
int		check_name(char *s)
{
	if (ft_memcmp(s, "NO", 2) == 0)
		return (1);
	else if (ft_memcmp(s, "EA", 2) == 0)
		return (1);
	else if (ft_memcmp(s, "SO", 2) == 0)
		return (1);
	else if (ft_memcmp(s, "WE", 2) == 0)
		return (1);
	else if (ft_memcmp(s, "S ", 2) == 0)
		return (1);
	else if (ft_memcmp(s, "F ", 2) == 0)
		return (2);
	else if (ft_memcmp(s, "C ", 2) == 0)
		return (2);
	return (0);
}

// this function check if the path contains only two parts
int		check_path(char *s)
{
	int		ret;
	char	**str;

	ret = 1;
	str = ft_split(s, ' ');
	if (count_items(str) != 2)
	{
		ret = 0;
		ft_putstr_fd("Something Wrong With The Path Elements", 2);
	}
	free_2D(str);
	return (1);
}

// this function checks that the rgb color content is perfectly correct like cell and floor
int		check_rgb(char *s)
{
	int		ret;
	char	**str;
	char	**rgb;
	int 	i;

	i = -1;
	str = ft_split(s, ' ');
	rgb = ft_split(str[1], ',');
	ret = 1;
	if (count_items(str) != 2 || count_items(rgb) != 3)
		ret = 0;
	else
		while (++i < 3)
			if ((ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255) && (ret = 0))
				break ;
	if (ret == 0)
		ft_putstr_fd("Something Wrong With The Cell Or Floor Element\n", 2);
	free_2D(rgb);
	free_2D(str);
	return (ret);
}

// this function will redirect the specified information to their functions to be checked
int		check_errors(char *stored_data)
{
	char	**data;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	data = ft_split(stored_data, '\n');
	while (data[i] != NULL && ret == 1)
	{
		if (data[i][0] == 'R' && data[i][1] == ' ')
			ret = check_resolution(data[i]);
		else if (check_name(data[i]) == 1)
			ret = check_path(data[i]);
		else if (check_name(data[i]) == 2)
			ret = check_rgb(data[i]);
		else if (data[i][0] == '1')
			ret = check_map((data + i), stored_data);
		else
			break ;
		i++;
	}
	if (i != 9 && ret != 0)
		ft_putstr_fd("The Map's File Is Not Complete\n", 2);
	free_2D(data);
	return (ret);
}
