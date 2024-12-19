/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:24:10 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/19 03:57:58 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
		my_mlx_pixel_put(img, x1, y1 * vars->scale, color);
		x1++;
		e -= dy;
		if (e <= 0)
		{
			y1++;
			e += dx;
		}
	}
}

void	zoom(t_vars *vars)
{
	(void)vars;
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 53)
	{
		//clear imgs
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		return (1);
	}
	else if (key == 45)
		zoom(vars);
	else ft_putnbr_fd(key, 1);
	return (0);
}

t_data	*drawer(t_vars *vars, int **arr)
{
	t_data	*img;
	int	x;
	int	y;

	y = 0;
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			ft_putnbr_fd(arr[y][x], 1);
			if (arr[y][x + 1])
				draw_line(vars, img, x, y, (x + 1), (y), create_trgb(256, 0, 100, 200));
			if (arr[y + 1][x])
				draw_line(vars, img, x, y, (x), (y + 1), create_trgb(256, 0, 100, 200));
			x++;
		}
		y++;
	}
	return (img);
}

void	windows_managment(t_vars *vars, int **arr)
{
	t_data	*img;

	img = drawer(vars, arr);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_vars	*vars;
	int	**arr;

	(void)ac;
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return(0);
	arr = parser(av[1]);
	if (!arr)
	{
		free(vars);
		return (0);
	}
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "42 FDF by malapoug");
	vars->scale = (WIDTH * arr_size_i(arr)) / 100;
	windows_managment(vars, arr);
	mlx_hook(vars->mlx_win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars->mlx);
}

/*

     // Here I will be declaring the hooks, see below for their implementation.
     mlx_hook(env.win, 4, 0, mouse_handler, &env);
     // mouse_handler will be called everytime a mouse down event is emitted
     mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
     // key_handler will be called everytime a key is pressed
     mlx_hook(env.win, 17, 1L << 0, close_window, &env);
     // close_window is called when we click on the red cross to close the window
     mlx_loop_hook(env.mlx, render, &env);
     // Since MXL loops over and over again, we can use the mlx_loop_hook
     // to execute a function everytime MLX loops over.


destination.x=source.x∗cos(a)+source.y∗cos(a+2)+source.z∗cos(a−2)
destination.y=source.x∗sin(a)+source.y∗sin(a+2)+source.z∗sin(a−2)
     destination.x = source.x + cos(angle) * source.z
     destination.y = source.y + sin(angle) * source.z
*/
