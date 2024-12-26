/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 03:36:34 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/26 23:30:33 by malapoug         ###   ########.fr       */
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
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF by malapoug");
	if (!vars->win)
		return (0);//free
	vars->img = malloc(sizeof(t_data));
	if (!vars->img)
		return (0);//free
	return (1);
}

void	init_view(t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bpp, &vars->img->line_length, &vars->img->endian);
}

void	draw_line(t_vars *vars, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	e;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 < x2)
	{
		put_pxl(vars->img, (x1 + vars->diffX) * vars->scale, y1 + vars->diffY, color);
		x1++;
		e -= dy;
		if (e <= 0)
		{
			y1++;
			e += dx;
		}
	}
}

t_data	*drawer(t_vars *vars, int **arr)
{
	t_data	*img;
	int		x;
	int		y;

	img = vars->img;
	y = 0;
	while (arr[y])
	{
		x = 0;
		while (arr[y][x])
		{
			if (arr[y][x + 1])
				draw_line(vars, x, y, (x + 1), y, trgb(256, 0, 100, 200));
			if (arr[y + 1][x])
				draw_line(vars, x, y, x, (y + 1), trgb(256, 0, 100, 200));
			x++;
		}
		y++;
	}
	return (img);
}

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

void	full_black(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			put_pxl(vars->img, x, y, trgb(256, 256, 256, 256));
			y++;
		}
		x++;
	}
}

int	update_img(t_vars *vars, int **arr)
{

	//full_black(vars);
	drawer(vars, arr);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);// check?
	return (1);
}

void	init(t_vars *vars)
{
	vars->scale = 2;
	vars->diffX = WIDTH / 4;
	vars->diffY = HEIGHT / 4;
}

int	process(t_vars *vars, int **arr)
{
	if (!win_init(vars))
		return (0);
	init(vars);
	init_view(vars);
	hook_function(vars);
	update_img(vars, arr);
	if (!vars->img)
		return (ft_free_t_vars(vars), 0);
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
	return (free(vars), ft_free_arr_i(arr, arr_size_i(arr)), 0);// a faire
}

/*
----------MANQUE:----------
drawer()
draw_line()
my_mlx_pixel_put()
ft_free_vars() (a faire)

*/
