/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/17 10:03:43 by aamzouar         ###   ########.fr       */
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

int			get_next_line(int fd, char **line);
char		**get_resolution(char *data_file);
char		**get_path(char *data_file, char *identifier);
int			get_color(char *data_file, char *identifier);
char		**get_map(char *data_file, int *sign);
char		**allocate(char	*data_file);

#endif
