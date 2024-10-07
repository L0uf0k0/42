NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = libft/ft_atoi.c libft/ft_itoa.c libft/ft_memset.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_putstr.c libft/ft_striteri.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_tolower.c libft/ft_toupper.c ft_print_p.c printf.h
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
