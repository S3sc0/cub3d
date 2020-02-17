# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 15:56:56 by aamzouar          #+#    #+#              #
#    Updated: 2020/02/17 10:11:26 by aamzouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@clang -I /usr/local/include *.c libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit

cpm:
	@gcc -I /usr/local/include/ *.c libft.a -L /usr/local/lib/ -lmlx -lXext -lX11
