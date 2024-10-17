/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:38:49 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:52 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_line(char *arr)
{
	char	*line;
	int		i;

	i = 0;
	while (arr[i] && arr[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		line[i] = arr[i];
		i++;
	}
	if (arr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_line(int fd, char *arr)
{
	char	*new_line;
	char	*temp;
	int		count;

	count = 1;
	new_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (!ft_strchr(arr, '\n') && count != 0)
	{
		count = read(fd, new_line, BUFFER_SIZE);
		if (count < 0)
			return (NULL);
		new_line[count] = '\0';
		temp = ft_strjoin(arr, new_line);
		if (!temp)
		{
			free(new_line);
			return (NULL);
		}
		arr = temp;
	}
	free(new_line);
	return (arr);
}

char	*update_arr(char *arr)
{
	char	*new;
	int		i;

	i = 0;
	while (*arr && *arr != '\n')
		arr++;
	while (arr[i] && arr[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 1));
	ft_strlcpy(new, arr, i);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*arr;
	char		*temp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	arr = get_line(fd, arr);
	if (!arr)
		return (NULL);
	temp = cut_line(arr);
	arr = update_arr(arr);
	return (temp);
}
