/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:34:50 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/09 15:17:50 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void ft_print_hex(unsigned int n, int type)
{
	int	digs;
	int	to_print;

	if (n > 0)
	{
		digs = n % 16;
		if (digs <= 9)
			to_print = '0' + digs;
		else
			to_print = (type - 23) + (digs - 10);
		ft_print_hex((n / 16), type);
		write (1, &to_print, 1);

	}
	
}

int main()
{
	int p = -10000000;
	unsigned int d;
	d = (unsigned int)p;
	ft_print_hex(p, 'x');
	printf("\n%x\n", d);
}