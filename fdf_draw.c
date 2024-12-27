/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:00:59 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/27 21:12:25 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	transfX(t_vars *vars, int x, int y)
{
	return (int)(vars->ang_y * ((x * vars->scale + vars->diffX) - (y * vars->scale + vars->diffY)));
}

int	transfY(t_vars *vars, int x, int y, int z)
{
	return (int)(vars->ang_x * ((x * vars->scale + vars->diffX) + (y * vars->scale + vars->diffY)) - (z * vars->z_scale));
}

int	color(t_vars *vars, int x, int y)
{
	int z;

	z = vars->ang_x * (((x * vars->scale + vars->diffX) + (y * vars->scale + vars->diffY)) - y) / vars->z_scale;
	return ((255 * (vars->max_z - vars->min_z)) / z);
}

void	put_pxl(t_vars *vars, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	dst = vars->img->addr + (y * vars->img->line_length + x * (vars->img->bpp / 8));
	*(unsigned int*)dst = trgb(25, 115, 25, 255);
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
/*
void	draw_line(t_vars *vars, int x1, int y1, int x2, int y2)
{
	int	tx1;
	int	tx2;
	int	dx;
	int	dy;
	int	e;

	tx1 = transfX(vars, x1, y1);
	y1 = transfY(vars, x1, y1, vars->arr[y1][x1]);
	tx2 = transfX(vars, x2, y2);
	y2 = transfY(vars, x2, y2, vars->arr[y2][x2]);
	e = tx2 - tx1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (tx1 < tx2)
	{
		put_pxl(vars, tx1, y1);
		tx1++;
		e -= dy;
		if (e <= 0)
		{
			y1++;
			e += dx;
		}
	}
}
*/

void	draw_line(t_vars *vars, int x1, int y1, int x2, int y2)
{
	int	tx1, ty1, tx2, ty2;
	int	dx, dy, e, step_x, step_y;

	// Calculer les coordonnées projetées pour les deux points
	tx1 = transfX(vars, x1, y1);
	ty1 = transfY(vars, x1, y1, vars->arr[y1][x1]);
	tx2 = transfX(vars, x2, y2);
	ty2 = transfY(vars, x2, y2, vars->arr[y2][x2]);

	// Calculer les différences
	dx = abs(tx2 - tx1);
	dy = abs(ty2 - ty1);
	step_x = (tx1 < tx2) ? 1 : -1;
	step_y = (ty1 < ty2) ? 1 : -1;

	// Algorithme de Bresenham
	e = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		put_pxl(vars, tx1, ty1);
		if (tx1 == tx2 && ty1 == ty2)
			break;
		int e2 = e;
		if (e2 > -dx) { e -= dy; tx1 += step_x; }
		if (e2 < dy) { e += dx; ty1 += step_y; }
	}
}


t_data	*drawer(t_vars *vars)
{
	t_data	*img;
	int		x;
	int		y;

	img = vars->img;
	y = 0;
	while (y < vars->arr_h)
	{
		x = 0;
		while (x < vars->arr_w)
		{
			if (vars->arr[y] != NULL && x + 1 < vars->arr_w)
				draw_line(vars, x, y, x + 1, y);
			if (y + 1 < vars->arr_h)
				draw_line(vars, x, y, x, y + 1); //pourquoi ?
			x++;
		}
		y++;
	}
	return (img);
}

void	full_black(t_vars *vars)
{
	ft_memset(vars->img->addr, 0, WIDTH * HEIGHT * (vars->img->bpp / 8));
}
