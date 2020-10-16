/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:11:48 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/16 19:07:18 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d(char **splited)
{
	int i;

	i = 0;
	while (splited[i] != NULL)
		free(splited[i++]);
	free(splited);
}

/*
** here you'll count how many items in a 2D array
*/

int		count_items(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		check_map_content(char **str, int max)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	while (i < max && ret)
	{
		ret = check_start_line(str, i, max);
		ret = check_end_line(str, i, max, ret);
		ret = horizontal_check(str[i], i, max, ret);
		i++;
	}
	ret = vertical_check(str, max, ret);
	return (ret);
}

/*
** here we check the map's order and it's content if there an empty line
*/

int		check_map_order(char *t_data)
{
	int		i;
	int		ret;

	ret = 2;
	i = 0;
	while (t_data[i] != '\0')
		i++;
	if (t_data[i - 3] != '1')
	{
		ft_putstr_fd("Error: The Map Isn't The Last Element\n", 2);
		ret = 3;
	}
	return (ret);
}

/*
** this function redirects the map to be checked
*/

int		check_map(char **s, char *d)
{
	int		ret;
	int		max;

	max = count_items(s);
	ret = check_map_order(d);
	if (ret == 2)
	{
		ret = check_map_content(s, max);
	}
	if (ret == 0 && ret != 3)
		ft_putstr_fd("Error: Something Wrong With The Map's Content\n", 2);
	if (ret == 3)
		ret = 0;
	return (ret);
}
