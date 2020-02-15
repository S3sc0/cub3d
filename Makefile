# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 15:56:56 by aamzouar          #+#    #+#              #
#    Updated: 2020/02/15 16:15:07 by aamzouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -I /usr/local/include *.c libft.a -L /usr/local/lib -lmlx -framework OpenGl -framework Appkit
