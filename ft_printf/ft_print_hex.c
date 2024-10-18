/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:34:50 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/18 21:27:00 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int type, int cond)
{
	int	digs;
	int	to_print;
	int	count;

	count = 0;
	if (n == 0x0 && cond)
		return (ft_putstr("0"));
	if (n > 0)
	{
		digs = n % 16;
		if (digs <= 9)
			to_print = '0' + digs;
		else
			to_print = (type - 23) + (digs - 10);
		count += ft_print_hex((n / 16), type, 0);
		count += write (1, &to_print, 1);
	}
	return (count);
}
/*
int main()
{
	int p = -10000000;
	unsigned int d;
	d = (unsigned int)p;
	ft_print_hex(p, 'x');
	printf("\n%x\n", d);
}
*/
