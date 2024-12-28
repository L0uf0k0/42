/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:14:28 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/28 15:58:53 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_vars *vars)
{
	ft_free_t_vars(vars);
	exit(EXIT_SUCCESS);
}

void	reset(t_vars *vars)
{
	vars->scale = 10;
	vars->z_scale = 1;
	vars->diff_x = WIDTH / 2;
	vars->diff_y = 0;
	vars->ang_y = 0.866;
	vars->ang_x = 0.5;
}

int	key_hook2(int key, t_vars *vars)
{
	if (key == 65363)
	{
		vars->diff_x -= 8;
		vars->diff_y += 8;
	}
	else if (key == 65364)
	{
		vars->diff_x -= 12;
		vars->diff_y -= 12;
	}
	else if (key == 119 && vars->ang_x > 0.2)
		vars->ang_x -= 0.1;
	else if (key == 115 && vars->ang_x < 1)
		vars->ang_x += 0.1;
	else if (key == 114)
		reset(vars);
	else if (key == 101 && vars->z_scale < 20)
		vars->z_scale += 0.2;
	else if (key == 100 && vars->z_scale > -20)
		vars->z_scale -= 0.2;
	ft_putstr_fd("\nkey: ", 1);
	ft_putnbr_fd(key, 1);
	if (vars->img->img)
		update_img(vars);
	return (1);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 53)
		close_win(vars);
	if (key == 65451)
	{
		vars->scale++;
		vars->z_scale += 0.1;
	}
	else if (key == 65453 && vars->scale > 0)
	{
		vars->scale--;
		vars->z_scale -= 0.1;
	}
	else if (key == 65361)
	{
		vars->diff_x += 8;
		vars->diff_y -= 8;
	}
	else if (key == 65362)
	{
		vars->diff_x += 12;
		vars->diff_y += 12;
	}
	return (key_hook2(key, vars));
}
