/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:59:04 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/29 18:47:24 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_t_data(void *mlx, t_data *img)
{
	if (img->img)
		mlx_destroy_image(mlx, img->img);
	if (img->addr)
		img->addr = NULL;
	if (img)
		free(img);
}

void	ft_free_t_vars(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->img)
		ft_free_t_data(vars->mlx, vars->img);
	if (vars->arr)
		ft_free_arr_i(vars->arr, arr_size_i(vars->arr));
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		free(vars->mlx);
	if (vars)
		free(vars);
}
