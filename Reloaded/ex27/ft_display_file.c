/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:01:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/09/13 22:37:50 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char *argv[])
{
	char	buffer[2000000];
	int		i;
	int		f;
	int		fr;

	i = 1;
	while (i < argc)
	{
		f = open(argv[i], O_RDONLY);
		if (f == -1)
			return (0);
		fr = read(f, buffer, sizeof(buffer));
		if (fr == -1)
			return (0);
		ft_putstr(buffer);
		i++;
		close(f);
	}
}
