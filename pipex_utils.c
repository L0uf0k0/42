/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:33:36 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/18 15:15:16 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	check11(char *temp, char *path)
{
	if (!temp && path)
		free(path);
	if (!path && temp)
		free(temp);
	if (!temp || !path)
		return (0);
	return (1);
}

int	check21(char **args, char *path)
{
	if (!args && path)
		free(path);
	if (!path && args)
		ft_free_arr(args, arr_size(args));
	if (!args || !path)
		return (0);
	return (1);
}

int	success(void)
{
	exit(EXIT_SUCCESS);
}

void	error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
