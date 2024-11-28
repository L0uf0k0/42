/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:05:23 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/08 02:10:25 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ret_null_p(int i)
{
	char	*ptr;

	(void)i;
	ptr = (char *)malloc(1 * sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	str_len;
	char			*dup;
	int				i;

	str_len = ft_strlen((char *)s);
	if (start >= (str_len))
		return (ret_null_p(1));
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
