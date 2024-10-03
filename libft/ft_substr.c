/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:39:25 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/02 20:19:35 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	int		i;
	unsigned int	str_len;

	str_len = ft_strlen((char *)s);
	if (start >= (str_len))
        {
		dup = (char *)malloc(1 * sizeof(char)); // Allocate memory for an empty string
		if (!dup)
			return (0);
		dup[0] = '\0'; // Set the first character as null terminator
		return (dup);
	}
	if (len > str_len - start)
		len = str_len - start;
	dup = (char *)malloc((len + 1) * sizeof(char));
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
