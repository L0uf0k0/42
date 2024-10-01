/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:27:53 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/01 13:16:18 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert(int n, int c)
{
	char	*ptr;
	int		buffer[13];
	int		tot;
	int		i;

	i = 0;
	while (n >= 10)
	{
		buffer[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	buffer[i++] = n + 48;
	if (c == '-')
		buffer[i++] = '-';
	tot = i;
	i = 0;
	ptr = malloc(sizeof(char) * (tot + 2));
	if (!ptr)
		return (0);
	while (i++ < tot)
		ptr[i] = buffer[tot - i - 1];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		ptr = ft_insert(-n, '-');
	else
		ptr = ft_insert(n, 'a');
	return (ptr);
}
