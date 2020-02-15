/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:54:49 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/15 17:00:41 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	redirection(char *data_file)
{
	int		fd;
	char	*line;

	if ((fd = open(data_file, O_RDONLY) == -1)
			ft_putstr_fd(strerror(errno), 1);
}

int		main(int argc, char *argv[])
{
	if (argc != 2 || argc != 3)
	{
		ft_putstr_fd("Wrong Number Of Arguments", 1);
		return (-1);
	}
	redirection(argv[1]);
	return (0);
}
