/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:23:54 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/30 20:20:53 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	alpha_blend(unsigned char *image1, unsigned char *image2,
		unsigned char *output, int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int index = (y * width + x) * 4;         // 4 bytes per pixel (RGBA)
			float alpha = image2[index + 3] / 255.0;
				// alpha value of second image
			// blend the two images using alpha blending
			output[index] = image1[index] * (1 - alpha) + image2[index] * alpha;
			output[index + 1] = image1[index + 1] * (1 - alpha) + image2[index
				+ 1] * alpha;
			output[index + 2] = image1[index + 2] * (1 - alpha) + image2[index
				+ 2] * alpha;
			output[index + 3] = 255; // set alpha to fully opaque
		}
	}
}

void	draw_wu_line(t_data *mlx, t_point p0, t_point p1)
{
	int	x0;

	int dx, dy, sx, sy, err, e2;
	x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		//int alpha = 255 * abs(err - ((dx > dy ? dx : -dy) / 2))
			// (dx > dy ? dx : dy);
		mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, 0xFFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
