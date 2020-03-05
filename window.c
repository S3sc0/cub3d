/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:00:19 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/05 22:14:41 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// close whenever I've touched the red dot close button
int		red_dot(int key)
{
	mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	exit(0);
}

// close the window whenever i press esc 
int		e_s_c(int key)
{
	if (key == 53)
	{
		mlx_destroy_window(g_mlx_ptr, g_win_ptr);
		exit(0);
	}
	return (0);
}

// this function opens a window but before checks the wx and wy just to fit the full size
void	open_window(void)
{
	data info;

	info = ft_data(NULL);
	if (info.wx > 2560)
		info.wx = 2560;
	if (info.wy > 1395)
		info.wy = 1395;
	if_fail(g_win_ptr = mlx_new_window(g_mlx_ptr, info.wx, info.wy, "Cub3D"));
	mlx_key_hook(g_win_ptr, e_s_c, (void*)0);
	mlx_hook(g_win_ptr, 17, 0, red_dot, (void*)0);
}
