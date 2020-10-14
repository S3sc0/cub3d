/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:05 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/14 12:53:25 by aamzouar         ###   ########.fr       */
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
# include "./libft/libft.h"
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

/* ##### KEYS ##### */
#define UP_A 126 
#define DOWN_A 125 
#define LEFT_A 123 
#define RIGHT_A 124
#define W_KEY 13 
#define A_KEY 0
#define S_KEY 1
#define D_KEY 2
#define ESC_KEY 53

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
int	*g_x_len;

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
	int	height;
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
void		frame_render(int argc, char *argv);
void		init_frame(int argc, char *argv);
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
void		sprite_dst(player plr, rycrd hi, rycrd vi);
void		draw_sprite(player plr, data info);
float		calc_sp_x_start(player plr, data info, crd sprite);
void		draw_sprite_texture(sprite sprt, data info, int i);
void		export_bmp(char *flag, int argc, int width, int height);
int		check_start_line(char **lines, int id, int max);
int		check_end_line(char **lines, int id, int max, int ret);
int		horizontal_check(char *line, int id, int max, int ret);
int		vertical_check(char **lines, int max_y, int ret);
int		check_empty_line(char *map_data, int ret);
int		only_nbr(char **rgb);

#endif
