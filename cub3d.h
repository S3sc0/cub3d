/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:12:08 by aamzouar          #+#    #+#             */
/*   Updated: 2020/10/20 13:52:26 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB3D_H

#define CUB3D_H
#define BUFFER_SIZE 10000
#define SQ_SZ 64
#define RADIN (M_PI / 180)
#define FOV_ANGLE 60
#define WALL_WIDTH 1
#define YSTEP -SQ_SZ

#include <mlx.h>
#include "./libft/libft.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>

#define UP_A 126
#define DOWN_A 125
#define LEFT_A 123
#define RIGHT_A 124
#define W_KEY 13
#define A_KEY 0
#define S_KEY 1
#define D_KEY 2
#define ESC_KEY 53

void		*g_mlx_ptr;
void		*g_win_ptr;
void		*g_img_ptr;
int			*g_img_data;
int			g_line;
int			g_offset_x;
int			g_offset_s;
int			*g_texture;
int			g_vert;
int			g_asprite;
float		*g_wall_distance;
int			g_sprite_num;
float		*g_sprite_distance;
int			*g_x_len;

typedef	struct
{
	int		wx;
	int		wy;
	int		*no;
	int		*ea;
	int		*so;
	int		*we;
	int		*s;
	int		floor;
	int		cell;
	char	**the_map;
}			t_data;

typedef struct
{
	float	x;
	float	y;
	int		walk_d;
	int		turn_d;
	int		move_s;
	int		rotation_a;
	int		rotation_s;
	int		m_step;
}			t_player;

typedef struct
{
	int		height;
	int		hi_s;
	int		hi_e;
	int		wi_s;
	int		wi_e;
	int		i;
}			t_sprite;

typedef struct
{
	float	x;
	float	y;
}			t_crd;

t_crd		g_sprt;

typedef struct
{
	float	x;
	float	y;
	float	sx;
	float	sy;
}			t_rycrd;

typedef struct
{
	float	dpp;
	float	bottom;
	int		top;
	int		offset_y;
	int		dst_ftop;
}			t_wall;

int			get_next_line(int fd, char **line);
int			check_errors(char *stored_data);
void		free_2d(char **splited);
int			count_items(char **str);
int			check_map(char **s, char *d);
int			extension_check(char *file_name);
int			file_existence(int fd);
void		if_fail(void *state);
t_data		ft_data(char *data_file);
void		open_window(void);
void		frame_render(int argc, char *argv);
void		init_frame(int argc, char *argv);
void		put_pixel_img(int x, int y, int color);
t_player	*my_player(int state);
void		update_player(int key);
int			a_wall(float x, float y, char *which1);
void		rays(t_player plr, t_data info);
char		*custom_strdup(char *str);
int			map_complete(int i, int ret);
float		norm_a(float angle);
int			max_crd(t_rycrd intersect);
void		wall_rendering(float ray_d, int x, t_data info);
void		select_texture(char c, float ray_angle);
void		sprite_rendering(t_player plr, float ray_angle, t_data info, int x);
void		sprite_dst(t_player plr, t_rycrd hi, t_rycrd vi);
void		draw_sprite(t_player plr, t_data info);
float		calc_sp_x_start(t_player plr, t_data info, t_crd sprite);
void		draw_sprite_texture(t_sprite sprt, t_data info, int i);
void		export_bmp(char *flag, int argc, int width, int height);
int			check_start_line(char **lines, int id, int max);
int			check_end_line(char **lines, int id, int max, int ret);
int			horizontal_check(char *line, int id, int max, int ret);
int			vertical_check(char **lines, int max_y, int ret);
int			check_empty_line(char *map_data, int ret);
int			only_nbr(char **rgb);
int			space_validating(char **lines, int x, int *y, int max_y);
int			vertical_check(char **lines, int max_y, int ret);
int			longest_x(char **lines, int max);
float		pnret(float x, float a, float b, float c);
int			check_the_rest(int origin, int line_len, char **lines, int id);
int			unallowd_elements_check(char *map);
int			printf_error_message(int ret, int number_of_paths);

#	endif
