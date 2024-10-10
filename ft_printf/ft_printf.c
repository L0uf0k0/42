/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:55:43 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/10 12:30:39 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_cases(char type, va_list args)
{
	char	c;
	switch (type)
	{
		case 'c':
			c = (char)va_arg(args, int);
			write(1, &c, 1);
			break;
		case 's':
			ft_putstr(va_arg(args, char *));
			break;
		case 'p':
			ft_print_p(va_arg(args, void *));
			break;
		case 'd':
			ft_putnbr(va_arg(args, int));
			break;
		case 'i':
			ft_putnbr(va_arg(args, int));
			break;
		//case 'u':
		case 'x':
			ft_print_hex(va_arg(args, unsigned int), type);
			break;
		case 'X':
			ft_print_hex(va_arg(args, unsigned int), type);
			break;
		case '%':
			write(1, "%", 1);
			break;
		default:
			return (0);
	}
	return (1);
}

int ft_printf(const char *format, ...)
{
	int	i;

	//count = arg_count((char *)str);
	va_list(args);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (!print_cases(format[i + 1], args))
				return (0);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (1);//total de char imprimes
}
/*
int main() {
    ft_printf("Hello %s! Your score is %d%%.\n", "Alice", 95);
    ft_printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed);
    printf("Hello %s! Your score is %d%%.\n", "Alice", 95);
    printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed);
    return 0;

}
*/
