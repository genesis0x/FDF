/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:06:10 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/21 20:11:48 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	calc_transformed_coords(t_data *data)
{
	size_t	x;
	size_t	y;
	t_point	*p;

	data->main.cam.d = 0;
	y = -1;
	while (++y < data->main.map.h)
	{
		x = -1;
		while (++x < data->main.map.w)
		{
			p = &data->main.cam.coords[y][x];
			*p = transform_point(&data->main.cam,
									(t_point){.x = x, .y = y,
										.z = data->main.map.coords[y][x]});
            print_point(*p);
			if (p->y > data->main.cam.d)
				data->main.cam.d = p->y;
		}
	}
    printf("----------------------------------------------------\n\n\n");
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
			if (x + x + xoff >= 0 && x + x + xoff < xoff + xoff && yoff - y >= 0
				&& yoff - y < yoff + yoff)
				paint_pxl(&data->main.canvas, 2 * x + xoff, yoff - y,
						0x00ffffff);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->main.canvas.img, 0, 0);
	mlx_loop(data->mlx);
}

// void plot(t_data *data)
// {
//     size_t i, j;
//     double x, y, z, x_rot, y_rot, z_rot;
//     int xoff, yoff;

//     xoff = data->main.canvas.w / 2;
//     yoff = data->main.canvas.h / 2;
//     z = data->main.cam.d;
//     x_rot = data->main.cam.ro.x;
//     y_rot = data->main.cam.ro.y;
//     z_rot = data->main.cam.ro.z;

// 	double p = -1;
//  	while (++p < data->main.canvas.w)
//  		paint_pxl(&data->main.canvas, p, yoff, 0x000000);
//     for (j = 0; j < data->main.map.h; j++)
//     {
//         for (i = 0; i < data->main.map.w; i++)
//         {
//             x = data->main.cam.coords[j][i].x;
//             y = data->main.cam.coords[j][i].y;
//             z = data->main.cam.coords[j][i].z;
//             x = x * cos(y_rot) + z * sin(y_rot);
//             z = -x * sin(y_rot) + z * cos(y_rot);
//             y = y * cos(x_rot) - z * sin(x_rot);
//             z = y * sin(x_rot) + z * cos(x_rot);
//             x = x * cos(z_rot) - y * sin(z_rot);
//             y = x * sin(z_rot) + y * cos(z_rot);

//             x = x - data->main.cam.tr.x;
//             y = y - data->main.cam.tr.y;
//             z = z - data->main.cam.tr.z;

//             x = z * x / y;
//             y = z * z / y;

//             if (x + x + xoff >= 0 && x + x + xoff < xoff + xoff && yoff - y >= 0 && yoff - y < yoff + yoff)
//                 paint_pxl(&data->main.canvas, 2 * x + xoff, yoff - y, 0x00ffffff);
//         }
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->main.canvas.img, 0, 0);
//     mlx_loop(data->mlx);
// }

void	start_fdf(t_data *data)
{
	for (size_t i = 0; i < data->main.canvas.w; i++)
		for (size_t j = 0; j < data->main.canvas.h; j++)
			paint_pxl(&data->main.canvas, i, j, 0x36454F);
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
