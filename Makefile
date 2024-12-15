# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2024/12/14 16:57:22 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

SRCS =	fdf.c\

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	#@make -C mlx/
	@$(CC) $(CFLAGS) $(OBJS) mlx/libmlx_Linux.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

debug: $(OBJS)
	@make -C libft/
	#@make -C mlx/
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) mlx/libmlx_Linux.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx -O3  mlx/libmlx_Linux.a -c $< -o $@


clean:
	@make clean -C libft/
	#@make clean -C mlx/
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft/
	#@make clean -C mlx/
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

