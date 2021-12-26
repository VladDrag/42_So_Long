# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdragomi <vdragomi@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 23:12:40 by vdragomi          #+#    #+#              #
#    Updated: 2021/11/09 00:10:08 by vdragomi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

HEADER = so_long.h

SRCS	=	main.c utils1.c map_check1.c map_check2.c game_init.c map_drawer.c \
			ft_itoa.c game_utils.c memory_utils.c

OBJS	=	${SRCS:.c=.o}

MLX		=	mlx
RM 		=	rm -rf

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):		mlx_all $(OBJS)
				$(CC) -o so_long $(CFLAGS) $(OBJS) mlx/libmlx_Linux.a -L/usr/include/X11/extensions -lX11 -lXext



all:		mlx_all ${NAME}

clean:
			${RM} ${OBJS}
			make -C ${MLX} clean

fclean:		clean
			${RM} ${NAME}
			make -C ${MLX} clean

re:			fclean all

mlx_all:
			cd mlx && ./configure

.PHONY:		all clean fclean re
