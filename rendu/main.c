/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:30:38 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/22 21:37:11 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int main(int argc, char **argv)
{
	int fd;
	char *line;
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	// Ouvre le fichier en lecture seule
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	// Lire et afficher chaque ligne jusqu'à la fin du fichier
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	// Fermer le fichier après utilisation
	close(fd);
	return (0);
}
