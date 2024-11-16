# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2024/11/16 18:48:58 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swapi

CC = gcc #-fsanitize=address

AR = ar -crs

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap/main.c\
	push_swap/process.c\
	push_swap/push_swap_utils.c\
	push_swap/push_swap_utils_doubles.c\
	push_swap/calculs.c\
	parser/ft_atoi.c\
	parser/ft_split.c\
	parser/ft_substr.c\
	parser/parser.c\
	parser/parser_utils.c\
	validater/ft_putstr.c\
	validater/validater.c\
	push_swap/show_list.c

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
