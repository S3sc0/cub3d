/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:54:49 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/21 11:39:23 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// In this function we'll store data in a variable called "data" so we can use it later
char	*store_data(char *data_file)
{
	int		fd;
	char	*line;
	char	*data;
	char	*tmp;
	int		state;

	data = ft_strdup("");
	fd = open(data_file, O_RDONLY);
	while ((state = get_next_line(fd, &line)) >= 0)
	{
		tmp = data;
		data = ft_strjoin(data, line);
		free(tmp);
		tmp = data;
		data = ft_strjoin(data, "\n");
		free(tmp);
		free(line);
		if (state == 0)
			break ;
	}
	return (data);
}

int		main(int argc, char *argv[])
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Wrong Number Of Arguments\n", 2); // error if there is more or less then required number of arguments
		return (-1);
	}
	if(!(check_errors(store_data(argv[1]))))
		exit(1);
	return (0);
}
