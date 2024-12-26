/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:14:28 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/26 23:33:29 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_vars *vars)
{
	if (vars && vars->mlx && vars->img && vars->img->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	if (vars && vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	return (1);
}

void	up(t_vars *vars)
{
	vars->diffY+=10;
}

void	zoom(t_vars *vars)
{
	vars->scale++;
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 53)
		close_win(vars);
	if (key == 53)
		return (1);
	if (key == 32)
		zoom(vars);
	else
	{
		ft_putstr_fd("key: ", 1);
		ft_putnbr_fd(key, 1);
		ft_putstr_fd("\n", 1);
	}
	mlx_destroy_image(vars->mlx, vars->img->img);// pourquoiiiiiiiiiiiiiiiiiii?
	init_view(vars);
	return (1);
}

int	hook_function(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, key_hook, &vars); //keyboard
	mlx_hook(vars->win, 17, 1L<<0, close_win, &vars); //red cross
	//mlx_loop_hook(vars->mlx ,update_img, &vars); //comment ??
	return (1);
}
