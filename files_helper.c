/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:46:29 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/17 17:50:17 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect(int fd1[2], int fd2, int c)
{
	if (c == 'w')
	{
		close(fd1[0]);
		dup2(fd1[1], fd2);
		close(fd1[1]);
	}
	if (c == 'r')
	{
		close(fd1[1]);
		dup2(fd1[0], fd2);
		close(fd1[0]);
	}
}

int	get_line(char **line)
{
	char	*buffer;
	char	c;
	int		bytes;
	int		i;

	i = 0;
	buffer = (char *)malloc(1000);
	if (!buffer)
		return (-1);
	bytes = read(0, &c, 1);
	while (bytes && c != '\n')
	{
		if (c != '\n')
			buffer[i] = c;
		i++;
		bytes = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	return (bytes);
}

int	*open_f(int ac, char **av, int fds[2], int nbr)
{
	if (nbr == 2)
	{
		fds[0] = open(av[1], O_RDONLY);
		fds[1] = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
		if (fds[0] < 0 || fds[1] < 0)
			return (error("Error opening files\n"), NULL);
	}
	else
	{
		fds[0] = 0;
		fds[1] = open(av[ac - 1], O_CREAT | O_APPEND | O_WRONLY, 0777);
		if (fds[1] < 0)
			return (error("Error opening files\n"), NULL);
	}
	return (fds);
}
