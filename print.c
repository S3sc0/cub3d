/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:16:27 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/18 12:05:17 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print(void)
{
	int i;
	char **map;

	i = 0;
	printf("%d\n%d\n", size_xy(NULL, 'x'), size_xy(NULL, 'y'));
	while (i++ < 5)
		printf("%s\n", path(NULL, i));
	printf("%d\n%d\n", rgb_color(NULL, 'f'), rgb_color(NULL, 'c'));
	i = 0;
	map = the_map(NULL);
	while (map[i] != NULL)
		printf("%s\n", map[i++]);
}
