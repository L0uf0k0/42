/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:15:48 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/28 15:34:29 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av)
{
	if (ac < 5 || access(av[1], R_OK) != 0 || access(av[ac - 1], R_OK) != 0)
		return (write(1, "Error main case 1", 17));

}
