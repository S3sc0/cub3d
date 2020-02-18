/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:52:12 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/18 11:25:42 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// when ever i'll call this function for the second time after i initialize it, it'll give me the resolution
int		size_xy(char *data_file, char id)
{
	char static	*size[2];

	if (data_file != NULL)
	{
		size[0] = get_resolution(data_file)[1];
		size[1] = get_resolution(data_file)[2];
	}
	if (id == 'x')
		return (ft_atoi(size[0]));
	else if (id == 'y')
		return (ft_atoi(size[1]));
	return (-1);
}

// this function returns the path specified in the parameter ID and i used a way to
// navigate the structure using a while loop
char	*path(char *data_file, int id)
{
	data static	texture;
	int			i;
	char		***p;

	i = 0;
	p = (char***)&texture;
	if (data_file != NULL)
	{
		texture.NO = get_path(data_file, "NO"); // id = 1
		texture.EA = get_path(data_file, "EA"); // id = 2
		texture.SO = get_path(data_file, "SO"); // id = 3
		texture.WE = get_path(data_file, "WE"); // id = 4
		texture.S = get_path(data_file, "S ");  // id = 5
	}
	while (i < id - 1)
		i++;
	return ((*(p+i))[1]); // after i got the memeber of the structure i've taken the content of the index specified
}

// easy it's just store data in both static variables
int		rgb_color(char *data_file, char id)
{
	int	static	floor;
	int	static	cell;

	if (data_file != NULL)
	{
		floor = get_color(data_file, "F ");
		cell = get_color(data_file, "C ");
	}
	if (id == 'f')
		return (floor);
	return (cell);
}

// really simple returns the map but without call get_map everytime
char	**the_map(char *data_file)
{
	char static	**map;
	int			state;

	if (data_file != NULL)
		map = get_map(data_file, &state);
	return (map);
}

// here i initialize it so everytime i call these functions i get what in the static variables
void	initialize_data(char *data_file)
{
	size_xy(data_file, '\0');
	path(data_file, 1);
	rgb_color(data_file, 'f');
	the_map(data_file);
}
