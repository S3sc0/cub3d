/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:24:06 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/17 11:10:57 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function will get the resolution data but it is not converted to integer yet
char	**get_resolution(char *data_file)
{
	int		fd;
	char	*line;
	char	**window_size;

	fd = open(data_file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_memcmp(line, "R ", 2) == 0)
			break ;
		free(line);
	}
	window_size = ft_split(line, ' ');
	free(line);
	close(fd);
	return (window_size);
}

// this function will bring us the path of the defined texture path
char	**get_path(char *data_file, char *identifier)
{
	int		fd;
	char	*line;
	char	**the_path;

	fd = open(data_file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_memcmp(line, identifier, 2) == 0)
			break ;
		free(line);
	}
	the_path = ft_split(line, ' ');
	free(line);
	close(fd);
	return (the_path); // it is double pointer because we'll be able to free it later
}

int		convert_to_dec(char *line)
{
	char	**rgb;
	int		color;

	rgb = ft_split(line, ',');
	color = ft_atoi(rgb[2]) * 65536 + ft_atoi(rgb[1]) * 256; // applying the equation B * 65536 + G * 256 + R
	color += ft_atoi(rgb[0]); // to get the rgb color in decmal format
	return (0);
}

// this function and with the help of convert_to_dec we can get the rgb color data from the data_file
int		get_color(char *data_file, char *identifier)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		the_color;

	fd = open(data_file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_memcmp(line, identifier, 2) == 0)
			break ;
		free(line);
	}
	tmp = ft_split(line, ' '); // free this please
	the_color = convert_to_dec(tmp[1]);
	free(line);
	close(fd);
	return (the_color);
}

// this function get line by line of the map and the line should start with 1
char	**get_map(char *data_file, int *sign)
{
	int		fd;
	char	*line;
	char	**the_map;
	int		i;

	i = 0;	
	the_map = allocate(data_file); // here we allocate the buffer size >= to the map
	fd = open(data_file, O_RDONLY);
	while ((*sign = get_next_line(fd, &line)) == 1)
	{
		if (ft_memcmp(line, "1", 1) == 0)
			the_map[i++] = line;
		free(line);
	}
	the_map[i] = NULL; // it's like a terminator
	free(line);
	close(fd);
	return (the_map);
}
