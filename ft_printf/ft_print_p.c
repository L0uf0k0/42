/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:34:50 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/10 12:03:34 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void ft_print_p(void *p)
{
	uintptr_t	add;
	int		buffer[20];
	int		i;
	int		digs;

	add = (uintptr_t)p;
	i = 19;
	buffer[i--] = '\0';
	while (i >= 0 && add > 0)
	{
		digs = add % 16;
		if (digs <= 9)
			buffer[i--] = '0' + digs;
		else
			buffer[i--] = ('a' + (digs - 10));
		add /= 16;
	}
	buffer[i--] = 'x';
	buffer[i] = '0';
	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		i++;
	}
	
}
/*
int main()
{
	int *p;
	p = malloc(12);
	ft_print_p(p);
	printf("\n%p\n", p);
}
*/
