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
		cmd_path = ft_strjoin(ft_strjoin(*paths, "/"), cmd);//check
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		paths++;
	}
	return (cmd_path);
}

int	redirect(int pipefd[2], int fd)
{
	int	pipefd2[2];

	if (fd == -1)
	{
		if (pipe(pipefd2) == -1)
			return (ft_putstr_fd("Error in pipe", 2), -1);
		close(pipefd2[0]);
		dup2(pipefd[1], pipefd2[0]);//check
		close(pipefd2[1]);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], fd);//check
		close(pipefd[1]);
	}
	return (1);
}

int	pipe_exec(char *cmd_path, char *cmd, char **envp, int	pipefd[2])
{
	char	**args;

	redirect(pipefd, -1);
	args = ft_split(cmd, *" ");
	if (execve(cmd_path, args, envp) == -1)
		return (ft_putstr_fd("Error in exec", 2), -1);//faire une fonction variadique pour free par exemple ici args?
	return (1);
}

int	forking_cmd(int	ac, char **av, char **envp, int pipefd[2])
{
	char	*cmd_path;
	int	pid;
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		pid = fork();
		if (pid < 0)
			return (-1);
		else if (pid == 0)
		{
			cmd_path = get_path(envp, av[i]); //check
			if (pipe_exec(cmd_path, av[i], envp, pipefd) == -1)
			{
				free(cmd_path);
				return (ft_putstr_fd("Error in pipe_exec", 2), -1);
			}
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av, char **envp)
{
	int	pipefd1[2];
	int	infile;
	int	outfile;

	if (ac < 5)
		return (ft_putstr_fd("Usage: file1 cmd1 ... cmd2 file2", 1), 1);
	infile = open(av[1], O_RDONLY);
	outfile = open(av[ac], O_WRONLY);
	if (infile < 0 || outfile < 0)
		ft_putnbr_fd(outfile, 2);
	return (ft_putstr_fd("Error opening files\n", 2), 1);
	redirect(pipefd1, infile);//check
	if (forking_cmd(ac, av, envp, pipefd1) == -1)
		return (ft_putstr_fd("Error in forking", 2), 1);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

