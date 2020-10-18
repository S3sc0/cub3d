# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 17:00:07 by aamzouar          #+#    #+#              #
#    Updated: 2020/10/18 16:56:46 by aamzouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wextra -Werror -Wall

SRC = bmp.c check_map_content.c check_map_content_2.c cub3d.c custom_strdup.c errors.c errors_p2.c errors_p3.c errors_p4.c frame_rendering.c get_next_line.c \
	  init_frame.c normalize_angle.c put_pixel_img.c ray_casting.c sp_render.c sprite_rendering.c sprite_tools.c store_data.c update_frame.c wall_rendering.c \
	  window.c

NAME = cub3D

all: $(NAME)

$(NAME):
	@cd libft && make
	@clang $(FLAG) -I /usr/local/include $(SRC) ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -o $(NAME)  


clean:
	@cd libft && make clean

fclean: clean
	@cd libft && make fclean
	rm -f cub3D

re: fclean all

.PHONY: all $(NAME) clean fclean re
