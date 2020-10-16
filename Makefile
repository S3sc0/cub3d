# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/16 17:00:07 by aamzouar          #+#    #+#              #
#    Updated: 2020/10/16 17:00:12 by aamzouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wextra -Werror -Wall

all:
	@cd libft && make
	@clang $(FLAG) -I /usr/local/include *.c ./libft/libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit -o cub3D


clean:
	@cd libft && make clean

fclean: clean
	@cd libft && make fclean
	rm -f cub3D

re: fclean all

.PHONY: all clean fclean re
