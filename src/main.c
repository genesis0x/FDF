/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:06:10 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/13 17:37:10 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	calc_transformed_coords(t_data *data)
{
	size_t	i;
	size_t	j;
	t_point	*p;

	data->main.cam.d = 0;
	j = -1;
	while (++j < data->main.map.h)
	{
		i = -1;
		while (++i < data->main.map.w)
		{
			p = &data->main.cam.coords[j][i];
			*p = transform_point(&data->main.cam,
									(t_point){.x = i, .y = j,
										.z = data->main.map.coords[j][i]});
			if (p->y > data->main.cam.d)
				data->main.cam.d = p->y;
		}
	}
}

void	plot(t_data *data)
{
	size_t	i;
	size_t	j;

	double ru, px, py, pz, dst, x, y;
	int xoff, yoff;
	xoff = data->main.canvas.w / 2;
	yoff = data->main.canvas.h / 2;
	dst = data->main.cam.d;
	x = -1;
	while (++x < data->main.canvas.w)
		paint_pxl(&data->main.canvas, x, yoff, 0x000000);
	j = -1;
	while (++j < data->main.map.h)
	{
		i = -1;
		while (++i < data->main.map.w)
		{
			px = data->main.cam.coords[j][i].x;
			py = data->main.cam.coords[j][i].y;
			pz = data->main.cam.coords[j][i].z;
			x = dst * px / py;
			ru = px * px + py * py;
			y = (dst * dst + x * x) * pz * pz / ru;
			y = (1 * (pz > 0) - 1 * (pz < 0)) * sqrt(y);
			//printf("(%zu, %zu) -> (%10f, %10f, %10f) -> (%10f, %10f)\n", i, j,
			//		px, py, pz, x, y);
			//int i = 0;
			//while (i <= 3 * y)
			//{
			if (x + x + xoff >= 0 && x + x + xoff < xoff + xoff && yoff - y >= 0
				&& yoff - y < yoff + yoff)
				paint_pxl(&data->main.canvas, 2 * x + xoff, yoff - y,
						0x00ffffff);
			//i++;
			//}
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.canvas.img, 0, 0);
	mlx_loop(data->mlx);
}

void	start_fdf(t_data *data)
{
	for (size_t i = 0; i < data->main.canvas.w; i++)
		for (size_t j = 0; j < data->main.canvas.h; j++)
			paint_pxl(&data->main.canvas, i, j, 0x808080);
	data->main.cam.v = calculate_vectors(data);
	calc_transformed_coords(data);
	plot(data);
}

int	main(void)
{
	t_data	data;

	printf("main.\n");
	init(&data, 0, 0);
	register_events(&data);
	start_fdf(&data);
	return (0);
}
