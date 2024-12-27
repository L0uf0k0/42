/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:14:28 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/27 22:08:47 by malapoug         ###   ########.fr       */
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

void	reset(t_vars *vars)
{
	vars->scale = 10;
	vars->z_scale = 10;
	vars->diffX = WIDTH / 2;
	vars->diffY = 0;
	vars->ang_y = 0.866;
	vars->ang_x = 0.5;
}

int	key_hook2(int key, t_vars *vars)
{
	if (key == 65363)
	{
		vars->diffX += 8;
		vars->diffY -= 8;
	}
	else if (key == 65364)
	{
		vars->diffX += 12;
		vars->diffY += 12;
	}
	else if (key == 119 && vars->ang_x > 0.2)
		vars->ang_x -= 0.1;
	else if (key == 115 && vars->ang_x < 1)
		vars->ang_x += 0.1;
	else if (key == 97 && vars->ang_y > 0.2)
		vars->ang_y -= 0.1;
	else if (key == 100 && vars->ang_y < 1.3)
		vars->ang_y += 0.1;
	else if (key == 114)
		reset(vars);
	ft_putstr_fd("\nkey: ", 1);
	ft_putnbr_fd(key, 1);
	update_img(vars);
	return(1);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 53)
		close_win(vars);
	if (key == 65451)
	{
		vars->scale++;
		vars->z_scale++;
	}
	else if (key == 65453)
	{
		vars->scale--;
		vars->z_scale--;
	}
	else if (key == 65361)
	{
		vars->diffX -= 8;
		vars->diffY += 8;
	}
	else if (key == 65362)
	{
		vars->diffX -= 12;
		vars->diffY -= 12;
	}
	return(key_hook2(key, vars));
}
