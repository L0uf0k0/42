/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:00:59 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/27 13:39:29 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		put_pxl(vars->img, x1, y1 , color);
		x1++;
		e -= dy;
		if (e <= 0)
		{
			y1++;
			e += dx;
		}
	}
}

t_data	*drawer(t_vars *vars)
{
	t_data	*img;
	int	**arr;
	int		x;
	int		y;

	img = vars->img;
	arr = vars->arr;
	y = 0;
	while (arr[y] != NULL)
	{
		x = 0;
		while (x < vars->arr_w)
		{
			put_pxl(vars->img, x * vars->scale, y * vars->scale, trgb(256, 0, 100, 200));
			//if (arr[y][x + 1])
			//	draw_line(vars, x, y, (x + 1), y, trgb(256, 0, 100, 200));
			//if (arr[y + 1][x])
			//	draw_line(vars, x, y, x, (y + 1), trgb(256, 0, 100, 200));
			x++;
		}
		y++;
	}
	return (img);
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


