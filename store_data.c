/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 08:09:35 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/08 00:33:39 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// easy just store the resolution x and y in a structure
void	store_resolution(char *s, data *ptr)
{
	char	**str;

	str = ft_split(s, ' ');
	ptr->wx = ft_atoi(str[1]);
	ptr->wy = ft_atoi(str[2]);
	if (ptr->wx > 2560)
		ptr->wx = 2560;
	if (ptr->wy > 1395)
		ptr->wy = 1395;
	free_2D(str);
}

// allocate and store the data to the proper structure
void	store_path(char *s, data *ptr)
{
	char	**str;
	void	*xpm_ptr;
	int		b[3];
	int		res[2];

	str = ft_split(s, ' ');
	xpm_ptr = mlx_xpm_file_to_image(g_mlx_ptr, str[1], &res[0], &res[1]);
	if (xpm_ptr == NULL)
	{
		ft_putstr_fd("The Path Of The XPM File Doesn't Exist\n", 2);
		exit(1);
	}
	if (ft_memcmp(str[0], "NO", 2) == 0)
		ptr->NO = (int*)mlx_get_data_addr(xpm_ptr, &b[0], &b[1], &b[2]);
	else if (ft_memcmp(str[0], "EA", 2) == 0)
		ptr->EA = (int*)mlx_get_data_addr(xpm_ptr, &b[0], &b[1], &b[2]);
	else if (ft_memcmp(str[0], "SO", 2) == 0)
		ptr->SO = (int*)mlx_get_data_addr(xpm_ptr, &b[0], &b[1], &b[2]);
	else if (ft_memcmp(str[0], "WE", 2) == 0)
		ptr->WE = (int*)mlx_get_data_addr(xpm_ptr, &b[0], &b[1], &b[2]);
	else if (ft_memcmp(str[0], "S", 1) == 0)
		ptr->S = (int*)mlx_get_data_addr(xpm_ptr, &b[0], &b[1], &b[2]);
	free_2D(str);
}

// here we store what we call rgb cell and floor colors
void	store_color(char *s, data *ptr)
{
	char	**str;
	char	**rgb;
	int		rgb_color;

	str = ft_split(s, ' ');
	rgb = ft_split(str[1], ',');
	rgb_color = ft_atoi(rgb[0]) * 65536 + ft_atoi(rgb[1]) * 256 + ft_atoi(rgb[2]);
	if (str[0][0] == 'F')
		ptr->floor = rgb_color;
	else if (str[0][0] == 'C')
		ptr->cell = rgb_color;
	free_2D(rgb);
	free_2D(str);
}

// and finally we stored the data about the map
void	store_map(char **s, data *ptr)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] != NULL)
		i++;
	if_fail(ptr->the_map = (char**)malloc(sizeof(char*) * (i + 1)));
	while (j < i)
	{
		ptr->the_map[j]	= custom_strdup(s[j]);
		j++;
	}
	ptr->the_map[j] = NULL;
}

// here this function redirects each element to its function and return a structure
data	ft_data(char *data_file)
{
	static data info;
	int			i;
	char		**s;

	s = ft_split(data_file, '\n');
	i = 0;
	if (data_file != NULL)
	{
		while (i < 9)
		{
			if (s[i][0] == 'R')
				store_resolution(s[i], &info);
			else if (s[i][1] == 'O' || s[i][0] == 'E' || s[i][0] == 'S' || s[i][0] == 'W')
				store_path(s[i], &info);
			else if (s[i][0] == 'F' || s[i][0] == 'C')
				store_color(s[i], &info);
			else if (s[i][0] == '1')
				store_map(s + i, &info);
			i++;
		}
		free_2D(s);
	}
	return (info);
}
