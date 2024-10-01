/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:22:27 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/01 14:48:14 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (c == s[i])
			count++;
		i++;
	}
	return (count);
}

char	*add_word(char *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	len = 0;
	while (*s != c)
	{
		word[len++] = *s;
		s++;
	}
	word[len] = '\0';
	return (word);
}

void	clean_arr(char **arr, int i)
{
	while (i > 0)
		free(arr[i--]);
	free(arr);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;

	if (!s)
		return (0);
	i = 0;
	arr = (char **)malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		arr[i++] = add_word((char *)s, c);
		if (!arr[i])
		{
			clean_arr(arr, i);
			return (0);
		}
		while (*s && *s != c)
			s++;
	}
	arr[i] = 0;
	return (arr);
}
