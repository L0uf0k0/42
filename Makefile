# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2024/12/03 09:39:41 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

DEBUG = -fsanitize=address

AR = ar -crs

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c\
	process.c\
	process2.c\
	push.c\
	min_max.c\
	hard_sort.c\
	push_swap_utils.c\
	push_swap_utils_doubles.c\
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

SRCSB = bonus/checker.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\
	push_swap_utils.c\
	push_swap_utils_doubles.c\
	ft_atoi.c\
	ft_split.c\
	ft_strjoin.c\
	parser.c\
	parser_utils.c\
	lst_actions.c\
	ft_putstr.c\
	validater.c\

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(NAME)" compiled\n"

debug : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(DEBUG) -o $(NAME)
	@echo $(NAME)" compiled with debug\n"

bonus : $(OBJSB)
	@$(CC) $(CFLAGS) $(OBJSB) -o checker
	@echo $(NAME)" compiled with bonus\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
