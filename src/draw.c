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

static void init_vars(t_point *p1, t_point *p2, t_point *dir, t_point *dis)
{
	p1.x = 0 * (begin.x < 0) + ((W - 1) * (begin.x >= W) + begin.x * (begin.x <= W));
	p1.y = 0 * (begin.y < 0) + ((H - 1) * (begin.y >= H) + begin.y * (begin.y <= H));
	p2.x = 0 * (end.x < 0) + ((W - 1) * (end.x >= W) + end.x * (end.x <= W));
	p2.y = 0 * (end.y < 0) + ((H - 1) * (end.y >= H) + end.y * (end.y <= H));
	dir.x = 1 * (p1.x < p2.x) + -1 * (p1.x > p2.x);
	dir.y = 1 * (p1.y < p2.y) + -1 * (p1.y > p2.y);
	dis.x = abs(p2.x - p1.x);
	dis.y = abs(p2.y - p1.y);
}

void	draw_line(t_data *data, t_point begin, t_point end)
{
	t_point p1;
	t_point p2;
	t_point dir;
	t_point dis;
	int	err;
	int e2;

	init_canvas(data->mlx, &data->main.canvas);
	init_vars(&p1, &p2, &dir, &dis);
	// p1.x = 0 * (begin.x < 0) + ((W - 1) * (begin.x >= W) + begin.x * (begin.x <= W));
	// p1.y = 0 * (begin.y < 0) + ((H - 1) * (begin.y >= H) + begin.y * (begin.y <= H));
	// p2.x = 0 * (end.x < 0) + ((W - 1) * (end.x >= W) + end.x * (end.x <= W));
	// p2.y = 0 * (end.y < 0) + ((H - 1) * (end.y >= H) + end.y * (end.y <= H));
	// dir.x = 1 * (p1.x < p2.x) + -1 * (p1.x > p2.x);
	// dir.y = 1 * (p1.y < p2.y) + -1 * (p1.y > p2.y);
	// dis.x = abs(p2.x - p1.x);
	// dis.y = abs(p2.y - p1.y);
	err = (dis.x * (dis.x > dis.y) + -dis.y * (dis.x < dis.y)) / 2;
	while (1)
	{
		paint_pxl(&data->main.canvas, p1.x, p1.y, 0xFFFFFF);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -dis.x)
		{
			err -= dis.y;
			p1.x += dir.x;
		}
		if (e2 < dis.y)
		{
			err += dis.x;
			p1.y += dir.y;
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.canvas.img, 0, 0);
	mlx_loop(data->mlx);
}


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
