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
	if (dup2(fd1, fd2) == -1)
		perror("Error in dup2");
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

int	forking_cmd(int ac, char **av, char **envp, int pipefd1[2], int outfile)
{
	int	pipefd2[2];
	int	*read_pipe = pipefd1;
	int	*write_pipe = pipefd2;
	int	pid;
	int	i;
	char	*cmd_path;

	i = 2;
	while (i < ac - 1)
	{
		// Crée un nouveau pipe pour la commande actuelle
		if (pipe(write_pipe) == -1)
			return (perror("Error creating pipe"), -1);

		pid = fork();
		if (pid < 0)
			return (perror("Error forking process"), -1);
		else if (pid == 0)
		{
			// Processus enfant
			redirect(read_pipe[0], STDIN_FILENO); // Lecture depuis le pipe précédent
			redirect(write_pipe[1], STDOUT_FILENO); // Écriture dans le pipe actuel

			// Récupération et exécution de la commande
			cmd_path = get_path(envp, av[i]);
			if (!cmd_path || pipe_exec(cmd_path, av[i], envp) == -1)
			{
				free(cmd_path);
				perror("Error in command execution");
				exit(EXIT_FAILURE);
			}
		}
		// Parent : fermeture des descripteurs inutilisés
		close(read_pipe[0]); // Ferme la lecture du pipe précédent
		close(write_pipe[1]); // Ferme l'écriture dans le pipe actuel

		// Alterne les pipes
		read_pipe = write_pipe;
		write_pipe = (read_pipe == pipefd1) ? pipefd2 : pipefd1;

		i++;
	}

	// Dernière redirection : dernier pipe -> fichier de sortie
	redirect(read_pipe[0], outfile);
	close(read_pipe[0]);
	return (0);
}

int main(int ac, char **av, char **envp)
{
	int	infile;
	int	outfile;
	int	pipefd1[2];

	if (ac < 5)
		return (ft_putstr_fd("Usage: file1 cmd1 ... cmdn file2", 1), 1);
	infile = open(av[1], O_RDONLY);
	outfile = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	pipe(pipefd1);
	if (infile < 0 || outfile < 0)
		perror("Error opening files\n");//return
	redirect(infile, pipefd1[1]);
	if (forking_cmd(ac, av, envp, pipefd1, outfile) == -1)
		return (ft_putstr_fd("Error in forking", 2), 1);
	close(outfile);
	return (0);
}

