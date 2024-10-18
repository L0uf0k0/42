/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:55:43 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/17 16:08:11 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_cases(char type, va_list args)
{
	char	c;
	int		count;

	count = 0;
	if (type == 'c')
	{
		c = (char)va_arg(args, int);
		count += write(1, &c, 1);
	}
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'p')
		count += ft_print_p(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (type == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += write(1, "%", 1);
	else
		return (0);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	temp;
	int	count;

	va_list(args);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			temp = print_cases(*(format + 1), args);
			if (temp == 0)
				return (0);
			count += temp;
			format += 2;
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (count);
}
/*
int main() {
    ft_printf("Hello %s! Your score is %u%%.\n", "Alice", -1);
    printf("%d", ft_printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed));
    printf("Hello %s! Your score is %u%%.\n", "Alice", -1);
    printf("%d", printf("Hex: %x, Pointer: %p\n", 255, (void *)0x7ffeed));
    return 0;

}
*/