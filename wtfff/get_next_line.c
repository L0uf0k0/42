/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:52:37 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/11 23:29:15 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		count;
	ssize_t		i;

	i = 0;
	buffer = (void *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	*buffer = '\0';
	while (*buffer != '\n' && i < BUFFER_SIZE)
	{
		count = read (fd, buffer, 1);
		buffer++;
		i++;
		if (*(buffer - 1) == '\n' || count < 1)
			break ;
	}
	*buffer = '\0';
	return (buffer - i);
}
