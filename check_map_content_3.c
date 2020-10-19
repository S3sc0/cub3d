/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:11:53 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/19 17:23:36 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_the_rest(int origin, int line_len, char **lines, int id)
{
	int		ret;
	int		j;

	j = origin;
	ret = 1;
	while (j <= line_len && lines[id][j] != '\0' && ret)
	{
		if (j < line_len && j == origin)
			j += 1;
		if (lines[id][j] != '1')
			ret = 0;
		j++;
	}
	return (ret);
}
