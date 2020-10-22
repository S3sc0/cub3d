/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_from_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:33:28 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/22 16:58:16 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**free_split(char **str, int b)
{
	while (b >= 0)
		free(str[b--]);
	free(str);
	return (NULL);
}

int		identifier_length(char *s)
{
	int		length;

	length = 0;
	if (*s == 'R' || (*s == 'S' && s[1] != 'O') || *s == 'C' || *s == 'F')
		length = 1;
	else
		length = 2;
	return (length);
}

int		path_starts(char *s)
{
	int		i;

	i = identifier_length(s);
	while (s[i] == ' ')
		i++;
	return (i);
}

char	**split_from_identifier(char *s)
{
	char	**idn_data;
	int		i;
	int		j;
	int		len;

	i = path_starts(s);
	j = identifier_length(s);
	len = ft_strlen((s + i));
	if (!(idn_data = (char**)malloc(sizeof(char*) * 3)))
		return (NULL);
	idn_data[2] = NULL;
	if (!(idn_data[0] = (char*)malloc(sizeof(char) * (j + 1))))
		return (free_split(idn_data, 0));
	if (!(idn_data[1] = (char*)malloc(sizeof(char) * (len + 1))))
		return (free_split(idn_data, 1));
	idn_data[0] = ft_memcpy(idn_data[0], s, j);
	idn_data[0][j] = '\0';
	idn_data[1] = ft_memcpy(idn_data[1], (s + i), len);
	idn_data[1][len] = '\0';
	return (idn_data);
}
