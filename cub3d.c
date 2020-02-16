/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:54:49 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/16 11:54:17 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function is willing to redirect the given line to the right function which will store it in the right buffer

void	redirection(char *data_file)
{
	int		fd;
	char	*line;

	if (correct_exten(data_file) == 0 || (fd = open(data_file, O_RDONLY) == -1))
	{
		perror("Error: "); // if file's extension is not correct get out
		exit(0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_memcmp(line, "R ", 2) == 0) // checks resolution data
			store_resolution(line);
		else if (ft_memcmp(line, "F ", 2) == 0 || ft_memcmp(line, "C ", 2) == 2) // checks floor and cell data
			store_rgb_color(line);
		else if (check_path == 1) // check the path of the texture
			store_path(line);
		else if (ft_memcmp(line, "\n", 1) == 1) // check if there a new line
			continue ;
		else	
		free(line);
	}
}

int		main(int argc, char *argv[])
{
	if (argc != 2 || argc != 3)
	{
		ft_putstr_fd("Wrong Number Of Arguments", 1); // error if there is more or less then required number of arguments
		return (-1);
	}
	redirection(argv[1]);
	return (0);
}
