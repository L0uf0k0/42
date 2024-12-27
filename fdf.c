/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:18:50 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/27 18:21:30 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
}

void update_img(t_vars *vars)
{
	// Nettoyer l'ancienne image si nécessaire
	if (vars->img->img)
		mlx_destroy_image(vars->mlx, vars->img->img);
	// Créer une nouvelle image
	vars->img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img->img)
		error("Failed to create new image\n");
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	// Dessiner et afficher l'image
	full_black(vars); // Efface l'écran avant de redessiner
	drawer(vars);	 // Appelle ta fonction pour dessiner ton schéma
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

int	process(t_vars *vars)
{
	update_img(vars);
	mlx_hook(vars->win, 2, 1L<<0, key_hook, vars); //keyboard
	mlx_hook(vars->win, 17, 1L<<0, close_win, vars); //red cross
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac == 2) // ?
	{
		vars = malloc(sizeof(t_vars));
		if (!vars)
			return (error(""), 1);
		vars->arr = parser(vars, av[1]);
		if (!vars->arr)
			return (free(vars), 1);//faire une f pour free aussi les pointeurs inside
		if (!init(vars))
			return(error("Error in Init\n"), 1);
		if (!process(vars))
			return(error("Error in Process\n"), 1);
		mlx_loop(vars->mlx);
	}
	else
		return(error("Usage: ./fdf <map.fdf>\n"), 1);
	return (ft_free_arr_i(vars->arr, arr_size_i(vars->arr)), free(vars), 0);// a faire
}

