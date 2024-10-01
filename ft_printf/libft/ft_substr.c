/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:39:25 by malapoug          #+#    #+#             */
/*   Updated: 2024/09/28 00:42:12 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	int		i;

	//if (start >= (unsigned int)ft_strlen((char *)s))
	//	return (0);
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (!dup)
		return (0);
	i = 0;
	i += start;
	while (s[i] && i - start < len)
	{
		dup[i - start] = s[i];
		i++;
	}
	dup[i - start] = '\0';
	return (dup);
}
