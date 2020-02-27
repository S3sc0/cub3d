/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:00:19 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/26 21:54:01 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// and this function exits the program when it encounters 53 meaning ESC and k 
int		close_program(int key, int state)
{
	if ((char)state == 'k' || key == 53)
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
	mlx_key_hook(g_win_ptr, close_program, (int*)1);
	mlx_hook(g_win_ptr, 17, 0, close_program, (int*)2);
}
