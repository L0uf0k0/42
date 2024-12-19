/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:36:34 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/19 16:06:57 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
}

void	put_pxl(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	close_win(t_vars *vars, t_data *img)
{
	mlx_destroy_image(vars->mlx, img->img);
	mlx_destroy_window(vars->mlx, vars->win);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 53)
		close_win(vars, img);
	if (key == 53)
		return ;
	else
	{
		ft_putstr_fd("key: ", 1);
		ft_putnbr_fd(key, 1);
		ft_putstr_fd("\n", 1);
	}
	return (1);
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

void	draw_line(t_vars *vars, t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	e;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 < x2)
	{
		put_pxl(img, x1, y1 * vars->scale, color);
		x1++;
		e -= dy;
		if (e <= 0)
		{
			y1++;
			e += dx;
		}
	}
}

int	update_img(t_vars *vars, t_data *img)
{
	mlx_destroy_img(vars->mlx, img->img);
	//drawer
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);// check?
	return (1);
}

int	handle_img(t_vars *vars)
{
	t_data *img;
	// if differemt ?
	img = malloc(sizeof(t_data));
	if (!img)
		return (0);
	if (!update_img(vars, img))
		return (ft_free_t_data(img), 0);
	return (1);
}

int	process(t_vars *vars, int **arr)
{
	if (!win_init(vars))
		return (0);
	handle_img(vars);
	hook_function(vars);
	mlx_loop(vars->mlx);
	return (1);
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
	return (free(vars), ft_free_arr_i(arr, arr_size(arr)), 0);// a faire
}

/*
----------MANQUE:----------
drawer()
draw_line()
my_mlx_pixel_put()
ft_free_vars() (a faire)

*/
