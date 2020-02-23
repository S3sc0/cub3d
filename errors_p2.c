/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:11:48 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/23 16:22:58 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// this function frees all 2D arrays
void	free_2D(char **splited)
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
	return (i);
}

// here we check if it's surrounded by 1 and it contains only
// 1, 2 or 0 and one of N, S, W, E
int		map_check_tail(char *s, int i, int max, int *sn)
{
	int		j;
	int		len;

	len = ft_strlen(s);
	j = 0;
	while (j < len)
	{
		if (i == 0 || i == max || j == 0 || s[j + 1] == '\0')
		{
			if (s[j] != '1' && (s[j + 1] != ' ' || s[j + 1] != '\0'))
				return (0);
		}
		else if ((s[j] == 'N' || s[j] == 'S' || s[j] == 'W' ||
					s[j] == 'E') && s[j + 1] == ' ')
			(*sn)++;
		else if (s[j] != '1' && s[j] != '2' && s[j] != '0' &&
				(s[j + 1] != ' ' || s[j + 1] != '\0'))
			return (0);
		j += 2;
	}
	return (2);
}

// here we check the map's order and it's content if there an empty line
int		check_map_order(char *data)
{
	int		i;
	int		sn;
	int		ret;

	ret = 2;
	i = 0;
	sn = 0;
	while (data[i] != '\0')
	{
		if (data[i] == '1' && sn == 0 && data[i - 1] == '\n')
			sn = 1;
		if (sn == 1 && ft_memcmp((data + i), "\n\n", 2) == 0)
			ret = 0;
		i++;
	}
	if (data[i - 2] != '1') // so we arrived to the end and move to steps back \0 \n then check
	{
		ft_putstr_fd("The Map Isn't The Last Element\n", 2);
		ret = 3;
	}
	return (ret);
}

// this function redirects the map to be checked
int		check_map(char **s, char *d)
{
	int		ret;
	int		i;
	int		max;
	int		sn;

	sn = 0;
	max = count_items(s);
	ret = 2;
	i = 0;
	ret = check_map_order(d);
	while (s[i] != NULL && ret == 2)
	{
		ret = map_check_tail(s[i], i, max - 1, &sn);
		i++;
	}
	if (ret == 0 || sn != 1)
		ft_putstr_fd("Something Wrong With The Map's Content\n", 2);
	return (ret);
}
