/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/03/13 16:30:00 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define BUFFER_SIZE 10000
#define SQUARE_SIZE 64 
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
# include <limits.h>

/* ##### KEYS ##### */
#define UP_A 65362
#define DOWN_A 65364
#define LEFT_A 65361
#define RIGHT_A 65363

void	*g_mlx_ptr;
void	*g_win_ptr;
void	*g_img_ptr;
int		*g_img_data;
int		g_line;
int		g_offset_x;
int		g_offset_s;
int		*g_texture;
int	g_vert;
int	g_asprite;
float	*g_wall_distance;
int	g_sprite_num;
float	*g_sprite_distance;

typedef struct
{
	int		wx;
	int		wy;
	int 	*NO;
	int 	*EA;
	int 	*SO;
	int 	*WE;
	int		*S;
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

typedef struct
{
	float	x;
	float	y;
	int	hi_s;
	int	hi_e;
	int	wi_s;
	int	wi_e;
	int	i;
}	sprite;

typedef struct
{
	float	x;
	float	y;
}			crd;

crd		sprt;
crd	g_triangle_crnr1;
crd	g_triangle_crnr2;

typedef struct
{
	float 	x;
	float	y;
	float	sx;
	float	sy;
}		rycrd;

typedef	struct
{
	float	dpp;
	float	bottom;
	int		top;
	int		offset_y;
	int	dst_ftop;
}			wall;

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
int			Awall(float x, float y, char *which1);
void		rays(player plr, data info);
char		*custom_strdup(char *str);
int			map_complete(int i, int ret);
float		normA(float angle);
int			max_crd(rycrd intersect);
void		wall_rendering(float ray_d, int x, data info);
void		select_texture(char c, float ray_angle);
void		sprite_rendering(player plr, float ray_angle, data info, int x);
void		sprite_dst(player plr, rycrd hi, rycrd vi, float ray_angle);
void		initialize_triangle_points(player plr, data info);
void		draw_sprite(player plr, data info);

#endif
