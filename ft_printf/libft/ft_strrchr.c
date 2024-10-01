/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:06:06 by malapoug          #+#    #+#             */
/*   Updated: 2024/09/27 12:17:18 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == c)
			ptr = (unsigned char *)s;
		s++;
	}
        if (c == '\0')
		ptr++;
        return ((char *)ptr);
}
