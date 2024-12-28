/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:00:59 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/28 16:05:28 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pxl(t_vars *vars, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = vars->img->addr + (y * vars->img->line_length + x * (vars->img->bpp / 8));
	*(unsigned int*)dst = trgb(2, 120, 25, 150);
}


/*
void	draw_line(t_vars *vars, int x1, int y1, int x2, int y2)
{
	int	tx1;
	int	tx2;
	int	dx;
	int	dy;
	int	e;

	tx1 = transf_x(vars, x1, y1);
	y1 = transf_y(vars, x1, y1, vars->arr[y1][x1]);
	tx2 = transf_x(vars, x2, y2);
	y2 = transf_y(vars, x2, y2, vars->arr[y2][x2]);
	e = tx2 - tx1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (tx1 <= tx2 || y1 <= y2)
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
	int	tx1;
	int	tx2;
	int	dx;
	int	dy;
	int	e, step_x, step_y;

	tx1 = transf_x(vars, x1, y1);
	y1 = transf_y(vars, x1, y1, vars->arr[y1][x1]);
	tx2 = transf_x(vars, x2, y2);
	y2 = transf_y(vars, x2, y2, vars->arr[y2][x2]);
	dx = abs(tx2 - tx1);
	dy = abs(y2 - y1);
	step_x = (tx1 < tx2) ? 1 : -1;
	step_y = (y1 < y2) ? 1 : -1;
	e = (dx > dy ? dx : -dy) / 2;
	while (tx1 != tx2 || y1 != y2)
	{
		put_pxl(vars, tx1, y1);
		int e2 = e;
		if (e2 > -dx)
		{
			e -= dy;
			tx1 += step_x;
		}
		if (e2 < dy)
		{
			e += dx;
			y1 += step_y;
		}
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
				draw_line(vars, x, y, x, y + 1);
			x++;
		}
		y++;
	}
	return (img);
}
