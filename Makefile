# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2024/12/18 15:12:46 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

SRCS =	pipex.c\
	pipex_utils.c\
	files_helper.c\

SRCSB =	pipex_bonus.c\
	pipex_utils.c\
	files_helper.c\

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo $(NAME)" compiled\n"

bonus: $(OBJSB)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJSB) libft/libft.a -o $(NAME)
	@echo $(NAME)" compiled with bonus\n"

debug : $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJS) $(DEBUG) libft/libft.a -o $(NAME)
	@echo $(NAME)" compiled with debug\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft/
	@$(RM) $(OBJS)
	@$(RM) $(OBJSB)

fclean: clean
	@make fclean -C libft/
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re












































