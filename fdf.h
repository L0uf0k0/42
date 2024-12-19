/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:24:19 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/19 03:55:52 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef HEIGHT
#  define HEIGHT 800
# endif

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int	scale;
}	t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

//parser
int	**parser(const char *file);

//parser_utils
void	ft_free_arr_i(int **arr, int i);
int	arr_size(char **arr);
int	arr_size_i(int **arr);

#endif
