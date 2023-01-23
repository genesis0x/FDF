/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:23:54 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/22 15:10:33 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_canvas(void *mlx, t_canvas *canvas)
{
	canvas->img = mlx_new_image(mlx, 1000, 1000);
	canvas->addr = mlx_get_data_addr(canvas->img, &canvas->bpp, &canvas->line_len, &canvas->endian);
}

void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int width, int height)
{
	int	x1_in_range;
	int	y1_in_range;
	int	x2_in_range;
	int	y2_in_range;
	int dx;
	int dy;
	int	err;
	int e2;
	int sx;
	int sy;

	init_canvas(data->mlx, &data->main.canvas);
	x1_in_range = 0 * (x1 < 0) + ((width - 1) * (x1 >= width) + x1 * (x1 <= width));
	y1_in_range = 0 * (y1 < 0) + ((height - 1) * (y1 >= height) + y1 * (y1 <= height));
	x2_in_range = 0 * (x2 < 0) + ((width - 1) * (x2 >= width) + x2 * (x2 <= width));
	y2_in_range = 0 * (y2 < 0) + ((height - 1) * (y2 >= height) + y2 * (y2 <= height));
	
	sx = 1 * (x1_in_range < x2_in_range) + -1 * (x1_in_range > x2_in_range);
	sy = 1 * (y1_in_range < y2_in_range) + -1 * (y1_in_range > y2_in_range);
	
	dx = abs(x2_in_range - x1_in_range);
	dy = abs(y2_in_range - y1_in_range);
	err = (dx * (dx > dy) + -dy * (dx < dy)) / 2;
	
	while (1)
	{
		paint_pxl(&data->main.canvas, x1_in_range, y1_in_range, 0xFFFFFF);
		if (x1_in_range == x2_in_range && y1_in_range == y2_in_range)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x1_in_range += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1_in_range += sy;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.canvas.img, 0, 0);
	mlx_loop(data->mlx);
}

/*void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int width,
		int height)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	x1 = 0 * (x1 < 0) + x1 * (x1 > 0);
	x1 = (width - 1) * (x1 >= width) + x1 * (x1 <= width);
	y1 = 0 * (y1 < 0) + y1 * (x1 > 0);
	y1 = (height - 1) * (y1 >= height) + y1 * (y1 <= height);
	x2 = 0 * (x2 < 0) + x2 * (x2 > 0);
	x2 = (width - 1) * (x2 >= width) + x2 * (x2 <= width);
	y2 = 0 * (y2 < 0) + y2 * (y2 > 0);
	y2 = (height - 1) * (y2 >= height) + y2 * (y2 <= height);
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = 1 * (x1 < 2) + -1 * (x1 > 2);
	sy = 1 * (y1 < 2) + -1 * (y1 > 2);
	err = (dx * (dx > dy) + -dy * (dx < dy)) / 2;
	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, x1, y1, 0xFFFFFF);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y1 += sy;
		}
	}
}*/

int	key_handler(int key, t_data *data)
{
	printf("key: %d\n", key);
	if (key == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1000, 1000, "Draw Line");
	mlx_hook(data.win, ON_KEYDOWN, 0, key_handler, &data);
	draw_line(&data, 1560, 1870, 1600, 1600, 1000, 1000);
	// t_point p0 = {.x=500, .y=500};
	// t_point p1 = {.x=1000, .y=0};
	// draw_line(&data, p0, p1, 0x00FF00);
	// p0.x=500, p1.y=200;
	// p1.x=0, p1.y=500;
	// draw_line(&data, p0, p1, 0x00FF00);
	//mlx_loop(data.mlx);
	return (0);
}
