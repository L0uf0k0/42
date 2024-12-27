/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:14:28 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/27 13:19:32 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_vars *vars)
{
	if (vars && vars->mlx && vars->img && vars->img->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	if (vars && vars->mlx && vars->win)
		mlx_destroy_window(&(vars->mlx), &(vars->win));
	return (1);
}

void	up(t_vars *vars)
{
	vars->diffY+=10;
}

void	zoom(t_vars *vars)
{
	//mlx_string_put(vars->mlx, vars->win, 10, 10, trgb(45, 45, 45, 45), "Espace Appuyé!");
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
	return (1);
}
