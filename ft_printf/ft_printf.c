/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:55:43 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/21 10:46:17 by malapoug         ###   ########.fr       */
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
		count += ft_print_hex(va_arg(args, unsigned int), type, 1);
	else if (type == '%')
		count += write(1, "%", 1);
	else
		return (-12);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int	count;
	int	temp;

	va_list(args);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			temp = print_cases(*(format + 1), args);
			if (temp == -12)
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
    ft_printf("Hello %s! Your score is %u%%.\n", "", -1);
    printf("%d\n", ft_printf("Hex: %x, Pointer: %p\n", 0x0, (void *)0x0));
    printf("Hello %s! Your score is %u%%.\n", "", -1);
    printf("%d\n", printf("Hex: %x, Pointer: %p\n", 0x0, (void *)0x0));
    return 0;

}
*/
