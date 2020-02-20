/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 08:59:20 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/20 12:24:53 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(char **splited)
{
	int i;

	i = 0;
	while (splited[i] != NULL)
		free(splited[i++]);
	free(splited);
}

// here you'll count how many items in a 2D array
int		count_items(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (0);
}

// this function will check that the resolution data is correct
int		check_resolution(char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_split(s, ' ');
	if (count_items(str) != 3) // should only be 3 arguments
		return (0);
	while (str[1][++i] != '\0') // if it's not int return 0
		if (str[1][i] < '0' || str[1][i] > '9')
			return (0);
	i = -1;
	while (str[2][++i] != '\0')
		if (str[2][i] < '0' || str[2][i] > '9')
			return (0);
	return (1);
}

// this function will redirect the specified information to their functions to be checked
int		check_errors(char *stored_data)
{
	char	**data;
	int		i;
	int		ret;
	i = 0;
	data = ft_split(stored_data, '\n');
	while (data[i] != NULL)
	{
		if (data[i][0] == 'R'i && data[i][1] == ' ')
			ret = check_resolution(data[i]);
		i++;
	}
	return (ret);
}
