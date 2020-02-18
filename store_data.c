/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:52:12 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/18 08:55:50 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// when ever i'll call this function for the second time after i initialize it, it'll give me the resolution
int		size_xy(char *data_file, char id, int state)
{
	data static	size;

	if (data_file != NULL && id == '\0')
		size.fre = get_resolution(data_file);
	if (id == 'x')
		return (ft_atoi(size.fre[1]));
	else if (id == 'y')
		return (ft_atoi(size.fre[2]));
	if (state == 1)
		free_2D(size.fre);
	return (-1);
}

// this function returns the path specified in the parameter ID and i used a way to
// navigate the structure using a while loop
char	*path(char *data_file, int id, int state)
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
	if (state == 1)
		free_2D(*(p+i));
	return ((*(p+i))[1]); // after i got the memeber of the structure i've taken the content of the index specified
}
