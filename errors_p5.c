/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 14:50:37 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/21 13:25:16 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		commas(char *s)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			res++;
		i++;
	}
	return (res);
}

int		map_not_found(char *map_data, int i, int ret)
{
	if (map_data[i] == '\0')
	{
		ft_putstr_fd("Error\nThe Map Doesn't Exist\n", 2);
		ret = 0;
	}
	return (ret);
}

int		check_line_of_zeros(char *line, int ret)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && ret)
	{
		if (line[i] == '0')
		{
			if (i == 0 || line[i - 1] == ' ')
				ret = 0;
			while ((line[i] == '0' || line[i] == '\0') && ret)
			{
				if (line[i] == ' ' || line[i] == '\0')
					ret = 0;
				i++;
			}
		}
		else
			i++;
	}
	return (ret);
}