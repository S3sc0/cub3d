/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:54:49 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/17 11:16:51 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	char	**nb;
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Wrong Number Of Arguments\n", 1); // error if there is more or less then required number of arguments
		return (-1);
	}
	nb = get_resolution(argv[1]);
	printf("%-5d%d\n", ft_atoi(nb[1]), ft_atoi(nb[2]));
	return (0);
}
