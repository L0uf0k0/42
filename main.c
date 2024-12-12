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
		envp++;
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
	//free
	return (cmd_path);
}

void	redirect(int fd1, int fd2)
{
	dup2(fd1, fd2);//check
	close(fd1);
}

int	pipe_exec(char *cmd_path, char *cmd, char **envp)
{
	char	**args;

	args = ft_split(cmd, *" ");
	free(args[0]);
	args[0] = cmd_path;
	if (execve(cmd_path, args, envp) == -1)
		return (perror("Error in exec"), -1);//faire une fonction variadique pour free par exemple ici args?
	return (1);
}

int	forking_cmd(int	ac, char **av, char **envp)
{
	char	*cmd_path;
	int	pipefd[2];
	int	pid;
	int	i;

	i = 2;
	while (i < ac - 1)
	{
		pipe(pipefd);
		redirect(STDOUT_FILENO, pipefd[1]);
		pid = fork();
		if (pid < 0)
			return (-1);
		else if (pid == 0)
		{
			cmd_path = get_path(envp, av[i]); //check
			if (pipe_exec(cmd_path, av[i], envp) == -1)
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
	int	infile;
	int	outfile;

	if (ac < 5)
		return (ft_putstr_fd("Usage: file1 cmd1 ... cmdn file2", 1), 1);
	infile = open(av[1], O_RDONLY);
	outfile = open(av[ac - 1], O_WRONLY);
	if (infile < 0 || outfile < 0)
		perror("Error opening files\n");
	redirect(infile, STDOUT_FILENO);
	if (forking_cmd(ac, av, envp) == -1)
		return (ft_putstr_fd("Error in forking", 2), 1);
	redirect(STDOUT_FILENO, outfile);
	close(outfile);
	return (1);
}

