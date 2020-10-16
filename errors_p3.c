/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_p3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 07:30:15 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/16 19:07:45 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		extension_check(char *file_name)
{
	int		i;
	int		j;
	char	*set;

	j = 0;
	set = ".cub";
	i = 0;
	while (file_name[i] != '.')
		i++;
	while (file_name[i] != '\0' || set[j] != '\0')
	{
		if (file_name[i] != set[j])
		{
			ft_putstr_fd("Error: Wrong File Extension\n", 2);
			return (0);
		}
		j++;
		i++;
	}
	return (1);
}

int		file_existence(int fd)
{
	if (fd < 0)
	{
		perror("Error ");
		return (0);
	}
	return (1);
}

/*
** if the allocation fails then exit and return an erron message
*/

void	if_fail(void *state)
{
	if (state == NULL)
	{
		perror("Error ");
		mlx_destroy_window(g_mlx_ptr, g_win_ptr);
		exit(1);
	}
}

/*
** here we are checking either if the map is not complete
** or it is more than complete duuuh
*/

int		map_complete(int i, int ret)
{
	if (i != 8 && ret != 0)
	{
		if (i < 8)
			ft_putstr_fd("Error: The Map's Elements Are Not Complete\n", 2);
		else if (i > 8)
			ft_putstr_fd("Error: There's More Than Required Number Of Elements\n", 2);
		return (0);
	}
	return (ret);
}
