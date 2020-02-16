/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:24:06 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/16 16:52:52 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.c"

int		**get_resolution(char *data_file)
{
	int			fd;
	char		*line;
	char		**tmp;
	int static	**window_size;

	if (window_size == 0)
	{
		fd = open(data_file, O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			if (ft_memcmp(line, "R ", 2) == 0)
				break ;
		}
		tmp = ft_split(line, ' ');
		free(line);
		if (!(window_size = malloc(sizeof(int) * 2)))
			return (NULL);
		if (!(window_size[0] = malloc(sizeof(int))))
			return (NULL);
		if (!(window_size[1] = malloc(sizeof(int))))
			return (NULL);
		window_size[0] = ft_atoi(tmp[0]);
		window_size[1] = ft_atoi(tmp[1]);
	}
	return (window_size);
}
