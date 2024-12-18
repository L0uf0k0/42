/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:16:26 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/18 15:15:00 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

//pipex_utils
void	error(const char *str);
int		success(void);
int		arr_size(char **arr);
int		check11(char *temp, char *path);
int		check21(char **args, char *path);

//files_helper
void	redirect(int fd1[2], int fd2, int c);
int		find_envp(char **envp);
int		*open_f(int ac, char **av, int fds[2], int nbr);
int		get_line(char **line);

#endif
