# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 15:56:56 by aamzouar          #+#    #+#              #
#    Updated: 2020/10/14 14:45:50 by aamzouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wextra -Werror -Wall

all:
	@cd libft && make
	@clang $(FLAG) -I /usr/local/include *.c ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -o cub3D

clean:
	@cd libft && make clean
	@rm *.bmp

fclean: clean
	rm -f Cub3d
	
re: fclean all

.PHONY: all clean fclean re
