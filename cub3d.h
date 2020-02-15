/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/15 16:14:02 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

#define CUB3D_H

#include "get_next_line.h"
#include <mlx.h>
#include "libft.h"

typedef static
{
	int		wx;
	int		wy;
	char	*path[5];
	int		floor[3];
	int		cell[3];
	char	**map;
}			info;

#endif
