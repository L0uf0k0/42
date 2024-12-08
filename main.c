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

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			break ;
		(*envp)++;
	}
	paths = ft_split(*envp + 5, *":");//check
	while (*paths)
	{

		cmd_path = ft_strjoin(*paths, cmd);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		paths++;
	}
	return (cmd_path);
}

int main(int ac, char **av, char **envp)
{
	char	*cmd_path;
	int		i;
	int		pid;

	if (ac < 5 || access(av[1], R_OK) != 0 || access(av[ac - 1], W_OK) != 0)
	{
		ft_putstr_fd("Error main case 1", 1);
		return (1);
	}
	i = 1;
	while (i < ac - 1)
	{
		pid = fork();
		if (pid == 0)
		{
			cmd_path = get_path(envp, av[i]); //check
			if(exceve(cmd_path) == -1)
				??

		}
	}
}

