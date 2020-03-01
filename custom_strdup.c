/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:28:44 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/01 15:54:31 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function is ft_strdup but custom for the map content
char	*custom_strdup(char *str)
{
	int		i;
	char	*s;
	int		j;

	j = 0;
	i = 0;
	while (str[j] != '\0')
	{
		if (str[j] != ' ')
			i++;
		j++;
	}
	if (!(s = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			s[j++] = str[i];
		i++;
	}
	s[j] = '\0';
	return (s);
}
