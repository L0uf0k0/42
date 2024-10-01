/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:55:38 by malapoug          #+#    #+#             */
/*   Updated: 2024/09/27 16:18:26 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_set(char const *set, int c)
{
        while (*set)
        {
                if (*set == c)
                        return (1);
                set++;
        }
        return (0);
}
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	char	*ptr;

	if (!s1 || !set)
        	return (0);
	ptr = malloc(ft_strlen((char *)s1) * sizeof(char) + 1);
	if (!ptr)
		return (0);
	start = 0;
	while (s1[start] && ft_is_in_set(set, s1[start]))
		start++;
	if (s1[start] == '\0')
	{
		*ptr = '\0';
		return (ptr);
	}
	end = ft_strlen((char *)s1) - 1;
	while (end > start && ft_is_in_set(set, s1[end]))
		end--;
	size = end - start + 1;
	ft_strlcpy(ptr, s1 + start, size + 1);
	ptr[size] = '\0';
	return (ptr);
}
