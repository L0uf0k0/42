/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:36:34 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/19 04:19:38 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
}

void	close_win(t_vars *vars)// a completer
{
	//clear imgs ?
	mlx_destroy_window(vars->mlx, vars->win);
}

void	key_hook(int key, t_vars *vars)
{
	if (key == 53)
		return(close_win(vars));
	else
	{
		ft_putstr_fd("key: ", 1);
		ft_putnbr_fd(key, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	hook_function(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, key_hook, &vars); //keyboard
	mlx_hook(vars->win, 17, 1L<<0, close_win, &vars); //red cross
	//mlx_loop_hook(vars->mlx, ?? , &vars); ??
}

int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF by malapoug");
	if (!vars->win)
		return (0);
	return (1);

}

int	process(t_vars *vars, int **arr)
{
	if (!win_init(vars))
		return (0);
	hook_function(vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	int	**arr;

	if (ac == 2) // ?
	{
		vars = malloc(sizeof(t_vars));
		if (!vars)
			return (error(""), 1);
		arr = parser(av[1]);
		if (!arr)
		{
			free(vars);//faire une f pour free aussi les pointeurs inside
			return (1);
		}
		if (!process(vars, arr))
			return(error("Error in Process\n"), 1);
	}
	else
		return(error("Usage: ./fdf <map.fdf>\n"), 1);
	return (free(vars), ft_free_arr(arr, arr_size(arr)), 0);
}

/*
----------MANQUE:----------
img management
drawer()
draw_line()
my_mlx_pixel_put()
ft_free_vars() (a faire)

*/
