/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:19:44 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/18 14:35:47 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function allocates the 2D arrays but actuall specified for get_the_map
char	**allocate(char *data_file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 20;
	fd = open(data_file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_memcmp(line, "1", 1) == 0) // this function would help in error handling if there 1111\n\n1111
			i++;
		free(line);
	}
	free(line);
	close(fd);
	if (!(map = (char **)malloc(sizeof(char*) * i + 1))) // + one for the NULL terminator
		return (NULL);
	return (map);
}

// this function frees only 2D arrays that ft_split returns for example
void	free_2D(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}
