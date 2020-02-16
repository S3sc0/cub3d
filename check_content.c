/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 11:02:55 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/16 11:23:06 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// the aim of this function is to check if the file has the correct extension

int		correct_exten(char *name)
{
	int i;

	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] == '.')
			if (ft_memcmp(&name[++i], "cub", 3) == 0)
				return (1);
			else
				break ;
		i++;
	}
	return (0);
}
