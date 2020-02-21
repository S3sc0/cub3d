/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:59:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/21 16:09:00 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function frees all 2D arrays
void	free_2D(char **splited)
{
	int i;

	i = 0;
	while (splited[i] != NULL)
		free(splited[i++]);
	free(splited);
}

// here you'll count how many items in a 2D array
int		count_items(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

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
	while (str[1][++i] != '\0') // if it's not number return 0
		if ((str[1][i] < '0' || str[1][i] > '9') && (ret = 0))
			break ;
	i = -1;
	while (str[2][++i] != '\0')
		if ((str[2][i] < '0' || str[2][i] > '9') && (ret = 0))
			break ;
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

int		check_map(char **s)
{
	int		ret;
	int		i;
	int		j;

	i = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (i == 0 && )
			j++;
		}
		i++;
	}
	return (ret);
}

// this function will redirect the specified information to their functions to be checked
int		check_errors(char *stored_data)
{
	char	**data;
	int		i;
	int		ret;
	int		sn;

	sn = 0;
	i = 0;
	ret = 0;
	data = ft_split(stored_data, '\n');
	while (data[i] != NULL && ret != 0)
	{
		if (data[i][0] == 'R' && data[i][1] == ' ' && ++sn)
			ret = check_resolution(data[i]);
		else if (check_name(data[i]) == 1 && ++sn)
			ret = check_path(data[i]);
		else if (check_name(data[i]) == 2 && ++sn)
			ret = check_rgb(data[i]);
		else if (data[i][0] == '1' && ++sn)
			ret = check_map((data + i));
		i++;
	}
	if (sn != 9)
		ft_putstr_fd("The Map's Element Are Not Complete", 2);
	return (ret);
}
