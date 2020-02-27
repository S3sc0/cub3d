/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:54:49 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/26 21:54:46 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// In this function we'll store data in a variable called "data" so we can use it later
char	*get_data(char *data_file)
{
	int		fd;
	char	*line;
	char	*data;
	char	*tmp;
	int		state;

	fd = open(data_file, O_RDONLY);
	if (!file_existence(fd) || !extension_check(data_file))
		exit(1);
	data = ft_strdup("");
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
	close(fd);
	return (data);
}

int		main(int argc, char *argv[])
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Wrong Number Of Arguments\n", 2); // error if there is more or less then required number of arguments
		return (-1);
	}
	if(!(check_errors(get_data(argv[1])))) // if there an error just exit
		exit(1);
	ft_data(get_data(argv[1]));
	if_fail(g_mlx_ptr = mlx_init());
	open_window();
	mlx_loop(g_mlx_ptr);
	return (0);
}
