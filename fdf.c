/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:24:10 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/14 17:37:19 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *img, double x1, double y1, double x2, double y2, int color)
{
	double	dist;
	double	diffX;
	double	diffY;


	diffX = x2 - x1;
	diffY = y2 - y1;
	dist = sqrt((diffX * diffX) + (diffY * diffY));
	diffX /= dist;
	diffY /= dist;
	while (dist > 0)
	{
		my_mlx_pixel_put(img, x1, y1, color);
		x1 += diffX;
		y1 += diffY;
		dist--;
	}
}

int	main()
{
	t_data	*img;
	void	*mlx;
	void	*mlx_win;

	img = malloc(sizeof(t_data));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "42 FDF by malapoug");
	img->img = mlx_new_image(mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	draw_line(img, 1, 1, 1000, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
}

