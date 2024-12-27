/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:24:19 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/27 13:37:29 by malapoug         ###   ########.fr       */
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
	int	**arr;
	int	arr_w;
	int	arr_h;
	t_data	*img;
	int	scale;
	int	diffX;
	int	diffY;
}	t_vars;


int	trgb(int t, int r, int g, int b);

//fdf_hook
int		close_win(t_vars *vars);
int		key_hook(int key, t_vars *vars);

//parser
int		**parser(t_vars *vars, const char *file);

//parser_utils
void	ft_free_arr_i(int **arr, int i);
int		arr_size(char **arr);
int		arr_size_i(int **arr);

//fdf_draw
t_data	*drawer(t_vars *vars);
void	put_pxl(t_data *img, int x, int y, int color);
void	draw_line(t_vars *vars, int x1, int y1, int x2, int y2, int color);
void	full_black(t_vars *vars);
int		trgb(int t, int r, int g, int b);

//fdf_clean
void	ft_free_t_data(t_data *img);
void	ft_free_t_vars(t_vars *vars);









void	init_view(t_vars *vars);
void	put_pxl(t_data *img, int x, int y, int color);
void	full_black(t_vars *vars);

#endif
