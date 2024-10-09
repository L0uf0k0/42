/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:55:43 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/09 15:21:18 by malapoug         ###   ########.fr       */
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

int print_cases(char type, void *ptr)
{
	if (!ptr)
		return (NULL);
	switch (type)
	{
		case 'c':
			write(1, ptr, 1);
		case 's':
			write(1, ptr, ft_strlen((char *)ptr);
		case 'p':
			ft_print_p(ptr); 
		case 'd':
			ft_putnbr((int)ptr);
		case 'i':
			ft_putnbr((int)ptr);
		//case 'u':
		case 'x':
			ft_print_hex((int)ptr);
		case 'X':
			ft_print_hex((int)ptr);
		case '%':
			write(1, "%", 1);
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
		if (str[i] == %)
		{
			if (!print_case(str[i + 1], va_arg(args, void *)))
				return (NULL);
		i += 2;
		write(1, &str[i], 1);
		i++;
	}
	return (1);//total de char imprimes
}

int main()
{
	printf("Originale: %d", 123);
	ft_printf("Mienne: %d", 123);
}
