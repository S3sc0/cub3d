/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/01 14:39:56 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define BUFFER_SIZE 10000
#define SQUARE_SIZE 32 
#define RADIN (M_PI / 180)
#define FOV_ANGLE 60
#define WALL_WIDTH 1
#define Ystep -SQUARE_SIZE

# include <mlx.h>
# include "libft.h"
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

void	*g_mlx_ptr;
void	*g_win_ptr;
void	*g_img_ptr;
int		*g_img_data;
int		g_line;

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
	float	x;
	float	y;
	int		walkD;
	int		turnD;
	int		moveS;
	int		rotationA;
	int		rotationS;
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
void		frame_render(void);
void		init_frame(void);
void		put_pixel_img(int x, int y, int color);
player		*myPlayer(int state);
void		turn_frame_black(void);
void		update_player(int key);
int			Awall(float x, float y);
void		rays(player plr, data info);
char		*custom_strdup(char *str);

#endif
