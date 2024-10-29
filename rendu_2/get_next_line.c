/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:04:52 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/29 14:14:32 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	 *extract_line(char **buffer)
{
	char	*newline;
	char	*temp;
	int		 len;

	temp = NULL;
	if (!*buffer || !**buffer)
		return (NULL);
	len = 0;
	while ((*buffer)[len] && (*buffer)[len] != '\n')
		len++;
	newline = ft_strdup(*buffer);
	if (!newline)
		return (NULL);
	if (ft_strchr(*buffer, '\n'))
		newline[len + 1] = '\0';
	if ((*buffer)[len] == '\n')
		len++;
	temp = ft_strdup(*buffer + len);
	if (!temp)
		return (NULL);
	free(*buffer);
	*buffer = temp;
	return (newline);
}

static int	  read_to_buffer(int fd, char **buffer)
{
	char	*temp;
	char	*read_buffer;
	ssize_t read_size;

	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (-1);
	read_size = read(fd, read_buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		read_buffer[read_size] = '\0';
		temp = ft_strjoin(*buffer, read_buffer);
		free(*buffer);
		*buffer = temp;
		if (ft_strchr(read_buffer, '\n'))
			break ;
		read_size = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
	return (read_size < 0);
}

char	*get_next_line(int fd)
{
	static char	 *buffer;
	int			 result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		buffer = ft_strdup("");
	result = read_to_buffer(fd, &buffer);
	if (result == -1 || !buffer)
	{
		if (result)
			free(buffer);
		return (NULL);
	}
	return (extract_line(&buffer));
}

/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("get_next_line.c", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}
*/
