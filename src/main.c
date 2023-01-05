/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:06:10 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/05 13:05:17 by ysalmi           ###   ########.fr       */
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
				(t_point){.x = i, .y = j, .z = data->main.map.coords[j][i]});
			if (p->y > data->main.cam.d)
				data->main.cam.d = p->y;
		}
	}
}

void	plot(t_data *d)
{
	size_t	i;
	size_t	j;
	double	ru, xx, yy, zz, dst, x, y;
	int		xoff, yoff;

	xoff = d->main.canvas.w / 2;
	yoff = d->main.canvas.h / 2;
	dst = d->main.cam.d;
	printf("dist: %f\n", dst);
	x = -1;
	while (++x < d->main.canvas.w)
		paint_pxl(&d->main.canvas, x, yoff, 0x00ffffff);
	j = -1;
	while (++j < d->main.map.h)
	{
		i = -1;
		while (++i < d->main.map.w)
		{
			xx = d->main.cam.coords[j][i].x;
			yy = d->main.cam.coords[j][i].y;
			zz = d->main.cam.coords[j][i].z;
			x = dst * xx /  yy;
			ru = xx*xx + yy*yy;
			y = (dst*dst + x*x) * zz*zz / ru;
			y = (1 * (zz > 0) -1 * (zz < 0)) * sqrt(y);
			printf("(%zu, %zu) -> (%10f, %10f, %10f) -> (%10f, %10f)\n", i, j, xx, yy, zz, x, y);
			//int i = 0;
			//while (i <= 3 * y)
			//{
			if (x + x + xoff >= 0 && x + x + xoff < xoff + xoff && yoff - y >=0 && yoff - y < yoff + yoff )
				paint_pxl(&d->main.canvas, 2 * x + xoff, yoff - y, 0x00ffffff);
				//i++;
			//}
		}
	}
	
	mlx_put_image_to_window(d->mlx, d->win, d->main.canvas.img, 0, 0);
	mlx_loop(d->mlx);
}

void	start_fdf(t_data *data)
{
	printf("starting...\n");
	data->main.cam.v = calculate_vectors(data);
	calc_transformed_coords(data);
	plot(data);
}

int	main(void)
{
	t_data	data;

	printf("main.\n");
	init(&data, 0, 0);
	//register_events(&data);
	start_fdf(&data);
	return (0);
}
