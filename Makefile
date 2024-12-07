# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2024/12/07 13:03:39 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAMEB = checker

CC = cc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

SRCS =	process.c\
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
	bonus/checker_utils.c\
	$(SRCS)\
	bonus/get_next_line.c\

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) main.c $(OBJS) -o $(NAME)
	@echo $(NAME)" compiled\n"

debug : $(OBJS)
	@$(CC) $(CFLAGS) main.c $(OBJS) $(DEBUG) -o $(NAME)
	@echo $(NAME)" compiled with debug\n"

bonus : $(OBJSB)
	@$(CC) $(CFLAGS) $(OBJSB) -o $(NAMEB)
	@echo $(NAME)" compiled with bonus\n"

bonusd : $(OBJSB)
	@$(CC) $(CFLAGS) $(OBJSB) $(DEBUG) -o $(NAMEB)
	@echo $(NAME)" compiled with bonus debug\n"
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJSB)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re
