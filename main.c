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

int	pipe_exec(char *cmd_path, char *cmd, char **envp)
{
	char	**args;
	int	pipefd[2];

	args = ft_split(cmd);
	if (pipe(pipefd) == -1)
		return (ft_putstr_fd("Error in pipe", 2), -1);
	if (exceve(cmd_path, args, envp) == -1)
		return (ft_putstr_fd("Error in exec", 2), -1);//faire une fonction variadique pour free par exemple ici args?
}

void	redircet(int pipefd[2])
{
	close(pipeft[0]);
	dup2(pipefd[1], STDOUT_ FILEN0);
	close(pipefd[1]);
}

int	forking_cmd(int	ac, char **av, char **envp)
{
	char	*cmd_path;
	int	pid;
	int	i;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (ft_putstr_fd("Error in pipe", 2), -1);
	i = 1;
	while (i < ac - 1)
	{
		pid = fork();
		if (pid < 0)
			return (-1);
		else if (pid == 0)
		{
			redirect(pipefd);
			cmd_path = get_path(envp, av[i]); //check
			if(pipe_exec(cmd_path, av[i], envp) == -1)
			{
				free(cmd_path);
				return (ft_putstr_fd("Error in pipe_exec", 2), -1);
			}
		}
		i++;
	}//close pipefd 0 et 1 ??
	return (0);
}

int main(int ac, char **av, char **envp)
{

	if (ac < 5 || access(av[1], R_OK) != 0 || access(av[ac - 1], W_OK) != 0)
	{
		ft_putstr_fd("Error main case 1", 1);
		return (1);
	}
	if (forking_cmd(ac, av, envp) == -1)
		return (ft_putstr_fd("Error in forking", 2), 1);

}

