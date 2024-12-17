/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:15:48 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/17 18:02:42 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*temp;
	int		i;

	cmd_path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			break ;
		envp++;
	}
	paths = ft_split(*envp + 5, *":");
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(temp, cmd);
		if (!check11(temp, cmd_path))
			return (error(""), ft_free_arr(paths, arr_size(paths)), NULL);
		free(temp);
		if (access(cmd_path, X_OK) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	ft_free_arr(paths, arr_size(paths));
	return (cmd_path);
}

int	child_process(char **av, int ac, char **envp, int i, int outf)
{
	char	**args;
	char	*path;
	int		pipefd[2];
	int		pid;

	args = ft_split(av[i], *" ");
	path = get_path(envp, args[0]);
	if (!check21(args, path))
		return (error("Error while split or path\n"), 0);
	if (pipe(pipefd) == -1)
		return (error("Error while piping\n"), free(path), 0);
	pid = fork();
	if (pid < 0)
		return (error("Error while forking\n"), free(path), 0);
	if (pid == 0)
	{
		redirect(pipefd, STDOUT_FILENO, 'w');
		if (i == ac - 2)
			dup2(outf, STDOUT_FILENO);
		execve(path, args, envp);
	}
	redirect(pipefd, STDIN_FILENO, 'r');
	ft_free_arr(args, arr_size(args));
	waitpid(pid, NULL, 0);
	return (free(path), 1);
}

void	process(char **av, int ac, char **envp, int i, int outf)
{
	while (i < ac - 1)
	{
		if (!child_process(av, ac, envp, i, outf))
			return (error("Error while child process\n"));
		i++;
	}
}

int	limiter(char *limiter, int ac)
{
	char	*line;
	int		pipefd[2];
	int		pid;

	if (ac < 6)
		return (ft_putstr_fd("Usage: here_doc limiter cmd1 cmd2 file2\n", 1), 0);
	if (pipe(pipefd) == -1)
		return (error("Error while piping\n"), 0);
	pid = fork();
	if (pid < 0)
		return (error("Error while forking\n"), 0);
	if (pid == 0)
	{
		close(pipefd[0]);
		while (get_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(pipefd[1], line, ft_strlen(line));
			free(line);
		}
	}
	else
		redirect(pipefd, STDIN_FILENO, 'r');
	return (waitpid(pid, NULL, 0), 1);
}

int	main(int ac, char **av, char **envp)
{
	int	fds[2];
	int	i;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			open_f(ac, av, fds, 1);
			if (!limiter(av[2], ac))
				return (1);
		}
		else
		{
			i = 2;
			dup2(*(open_f(ac, av, fds, 2)), STDIN_FILENO);
		}
		process(av, ac, envp, i, fds[1]);
		close(fds[0]);
	}
	else
		return (ft_putstr_fd("Usage: file1 cmd1 ... cmdn file2", 2), 1);
}
