/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:34:50 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/22 13:31:59 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *p)
{
	uintptr_t	add;
	int			buffer[20];
	int			i;
	int			digs;
	int			count;

	if (!p)
		return (ft_putstr("0x0"));
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
	count = (18 - i) + write(1, "0x", 2);
	while (buffer[++i])
		write(1, &buffer[i], 1);
	return (count);
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
