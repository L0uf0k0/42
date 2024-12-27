/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:59:04 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/27 10:59:21 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_t_data(t_data *img)
{
	if (img->img)
		free(img->img);
	if (img->addr)
		free(img->addr);
	if (img)
		free(img);
}

void	ft_free_t_vars(t_vars *vars)
{
	if (vars->mlx)
		free(vars->mlx);
	if (vars->win)
		free(vars->win);
	if (vars->img)//destroy
		ft_free_t_data(vars->img);
	if (vars)
		free(vars);
}


