/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/16 11:21:38 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

#define CUB3D_H
#define BUFFER_SIZE 10000

# include <mlx.h>
# include "libft.h"
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct
{
	int		wx;
	int		wy;
	char	*path[5];
	int		floor[3];
	int		cell[3];
	char	**map;
}			info;

int			get_next_line(int fd, char **line);
int			correct_exten(char *name);

#endif
