/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:07:23 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/28 19:03:36 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{

	if (!s)
		return (NULL);

	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
static char	*ret_null_p(int i)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	joined = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	while (s1 && s1[++i])
		joined[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		joined[len1 + i] = s2[i];
	joined[len1 + i] = '\0';
	return (joined);
}
