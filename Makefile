# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2024/11/30 16:23:42 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

DEBUG = -fsanitize=address

AR = ar -crs

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c\
	process.c\
	hard_sort.c\
	push_swap_utils.c\
	calculs.c\
	ft_atoi.c\
	ft_split.c\
	ft_substr.c\
	ft_strjoin.c\
	parser.c\
	parser_utils.c\
	lst_actions.c\
	ft_putstr.c\
	validater.c\
	show_list.c

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
