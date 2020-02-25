/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/02/25 15:53:24 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define BUFFER_SIZE 10000
#define SQUARE_SIZE 32

# include <mlx.h>
# include "libft.h"
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

void	*g_mlx_ptr;
void	*g_win_ptr;

typedef struct
{
	int		wx;
	int		wy;
	char 	*NO;
	char 	*EA;
	char 	*SO;
	char 	*WE;
	char	*S;
	int		floor;
	int		cell;
	char	**the_map;
}			data;

typedef struct
{
	int		x;
	int		y;
	int		walkD;
	int		turnD;
	int		moveS;
	float	rotationA;
	float	rotationS;
	int		mStep;
}			player;

int			get_next_line(int fd, char **line);
int			check_errors(char *stored_data);
void		free_2D(char **splited);
int			count_items(char **str);
int			check_map(char **s, char *d);
int			extension_check(char *file_name);
int			file_existence(int fd);
void		if_fail(void *state);
data		ft_data(char *data_file);
void		open_window(void);
void		create_map(void);
void		rec(int x, int y, char fill, int sym);
void		player2D(char sym, int x, int y);
#endif
