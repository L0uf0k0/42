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

void	error(char *str)
{
//free all
	perror(str);
	exit(EXIT_FAILURE);
}

void	redirect(int fd1[2], int fd2, int c)
{
	if (c == 'w' )
	{
		close(fd1[0]);
		dup2(fd1[1], fd2);
		close(fd1[1]);//?
	}
	if (c == 'r')
	{
		close(fd1[1]);
		dup2(fd1[0], fd2);
		close(fd1[0]);//?
	}

}

void	process(char **av, int ac, char **envp, int i, int ouf)
{
	char	**args;
	int	pipefd[2];
	int	pid;

	while (i < ac - 1)
	{
		args = ft_split(av[i], *" ");//check
		if (pipe(pipefd) == -1)
			return(error("Error while piping\n"));
		pid = fork();
		if (pid < 0)
			return(error("Error while forking\n"));
		if (pid == 0)
		{
			redirect(pipefd, STDOUT_FILENO, 'w');
			if (i == ac - 2)
				dup2(ouf, STDOUT_FILENO);
			execve(get_path(envp, args[0]), args, envp);
		}
		else
		{
			redirect(pipefd, STDIN_FILENO, 'r');
			waitpid(pid, NULL, 0);
		}
		i++;
	}
}

int	get_line(char **line)
{
	char	*buffer;
	int		i;
	int	bytes;
	char	c;

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

void	limiter(char *limiter, int ac)
{
	char	*line;
	int	pipefd[2];
	int	pid;

	if (ac < 6)
		return (ft_putstr_fd("Usage: here_doc limiter cmd1 ... cmdn file2", 1));
	if (pipe(pipefd) == -1)
		return(error("Error while piping\n"));
	pid = fork();
	if (pid < 0)
		return(error("Error while forking\n"));
	if (pid == 0)
	{
		close(pipefd[0]);
		while(get_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(pipefd[1], line, ft_strlen(line));
		}
	}
	else
		redirect(pipefd, STDIN_FILENO, 'r');
}

int	*open_f(int ac ,char **av, int fds[2], int nbr)
{
	if (nbr == 2)
	{
		fds[0] = open(av[1], O_RDONLY);
		fds[1] = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
		if (fds[0] < 0 || fds[1] < 0)
			return(error("Error opening files\n"), NULL);
	}
	else
	{
		fds[0] = 0;
		fds[1] = open(av[ac - 1], O_CREAT | O_APPEND | O_WRONLY, 0777);
		if (fds[1] < 0)
			return(error("Error opening files\n"), NULL);
	}
	return (fds);
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
			limiter(av[2], ac);
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
