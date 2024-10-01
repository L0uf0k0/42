/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:55:43 by malapoug          #+#    #+#             */
/*   Updated: 2024/09/28 11:26:50 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int arg_count(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i - 1] == '%' && (s[i - 1] || i == 0))
			count++;
	}
	return (count);
}

int print_cases(char type, ...)
{
	va_list arg, arg2;
	va_start(arg, 1);
	va_copy(arg2, arg);
	switch (type)
	{
		case 'c':
			write(1, arg, 1);
		case 's':
			write(1, arg, ft_strlen((char *)arg2));
		//case 'p':
		//case 'd':
		//case 'i':
		//case 'u':
		//case 'x':
		//case 'X':
		//case '%':
	}
	return (1);
}

int ft_printf(const char *str, ...)
{
	int	count;
	int	i;

	count = arg_count((char *)str);
	va_list(args);
	va_start(args, count);
	i = 0;
	while (str[i])
	{
		i += 2;
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}


int main()
{}
