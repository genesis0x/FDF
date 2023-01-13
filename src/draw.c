/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:23:54 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/13 15:48:19 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "mlx.h"

void	draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;
	int	dE;
	int	dNE;

	mlx_pixel_put(mlx, win, x1, y1, 0xFFFFFF);
	mlx_pixel_put(mlx, win, x2, y2, 0xFFFFFF);
	dx = x2 - x1;
	dy = y2 - y1;
	x = x1;
	y = y1;
	d = (dy << 1) - dx;
	dE = dy << 1;
	dNE = (dy - dx) << 1;
	while (x < x2)
	{
		if (d < 0)
		{
			d += dE;
			x++;
		}
		else
		{
			d += dNE;
			x++;
			y++;
		}
		mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
	}
}
