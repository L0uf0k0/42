/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:05:23 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/03 00:54:07 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	str_len;
	char			*dup;
	int				i;

	str_len = ft_strlen((char *)s);
	if (start >= (str_len))
		return (NULL);
	if (len > str_len - start)
		len = str_len - start;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = start;
	while (s[i] && i - start < len)
	{
		dup[i - start] = s[i];
		i++;
	}
	dup[i - start] = '\0';
	return (dup);
}
