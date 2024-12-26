/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:24:19 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/26 19:18:54 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	int	scale;
	int	diffX;
	int	diffY;
}	t_vars;


int	update_img(t_vars *vars, int **arr);

//fdf_hook
int		hook_function(t_vars *vars);
int		close_win(t_vars *vars);
int		key_hook(int key, t_vars *vars);

//parser
int		**parser(const char *file);

//parser_utils
void	ft_free_arr_i(int **arr, int i);
int		arr_size(char **arr);
int		arr_size_i(int **arr);

#endif
