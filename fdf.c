/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:42:25 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/31 01:30:57 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stddef.h>
#include <sys/_types/_size_t.h>

int	key_handler(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	register_events(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, key_handler, data);
	// key down event => esc case
}

void	init_canvas(void *mlx, t_canvas *c)
{
	c->img = mlx_new_image(mlx, c->w, c->h);
	// check if imgage is not NULL
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_len, &c->endian);
}

void	init_map(t_data *data)
{
	printf("initializing...\n");
	data->main.map_path = "map.fdf";
	data->main.map = process_map(data->main.map_path);
}

void	get_coords(t_data *data)
{
	t_cam	*cam;
	t_map	*map;
	t_point	p;
	t_vectors	v;

	size_t x, y;
	double _teta, _phi, ru, r, z;
	map = &data->main.map;
	cam = &data->main.cam;
	x = -1;
	cam->coords = malloc(map->h * sizeof(t_point *));
	while (++x < map->h)
		cam->coords[x] = malloc(map->w * sizeof(t_point));
	x = -1;
	v.ex.x = 0;
	v = calculate_vectors(data, v);
	printf("%zu, %zu\n", map->w, map->h);
	while (++x < map->w)
	{
		y = -1;
		while (++y < map->h)
		{
			z = map->coords[y][x];
			r = sqrt(x * x + y * y + z * z);
			if (r == 0)
				_teta = cam->mu + 0;
			else
				_teta = cam->mu + asin(z / r);
			if (x == 0)
				_phi = M_PI / 2 + cam->alpha;
			else
				_phi = atan((double)y / (double)x) + cam->alpha;
			ru = r * cos(_teta);
			/*cam->coords[y][x] = (t_point){.x = ru * cos(_phi),
											.y = ru * sin(_phi),
											.z = r * sin(_teta)};*/
			//cam->coords[y][x] = (t_point) {.x = }
			cam->coords[y][x] = (t_point) {.x = x * v.ex.x + y * v.ey.x + z * v.ez.x + cam->tr.x, 
									.y = x * v.ex.y + y * v.ey.y + z * v.ez.y + cam->tr.y,
									.z = x * v.ex.z + y * v.ey.z + z * v.ez.z + cam->tr.z};
			p = cam->coords[y][x];
			printf("phi: %f \t- teta: %f \t- r: %f  ", _phi, _teta, r);
			printf("{%zu, %zu, %.0f} => {%f, %f, %f}\n", x, y, z, p.x, p.y,
					p.z);
		}
	}
}

t_vectors	calculate_vectors(t_data *data, t_vectors v)
{
	t_point	c;
	t_point	s;

	/*Calculate the sin and cos to avoid calculate them every time */
	c.x = cos(data->main.cam.ro.x);
	c.y = cos(data->main.cam.ro.y);
	c.z = cos(data->main.cam.ro.z);
	s.x = cos(data->main.cam.ro.x);
	s.y = cos(data->main.cam.ro.y);
	s.z = cos(data->main.cam.ro.z);
	/* calcul ex */
	v.ex.x = c.y * c.x;
	v.ex.y = -c.y * s.x;
	v.ex.z = s.y;
	/* calcul ey*/
	v.ey.x = c.z * s.x + s.z * s.y * c.x;
	v.ey.y = c.z * c.x - s.z * s.y * s.x;
	v.ey.z = -s.z * s.y;
	/* calcul ez*/
	v.ez.x = s.z * s.x - c.z * s.y * s.x;
	v.ez.y = s.z * c.x + c.z * s.y * s.x;
	v.ez.z = c.z * c.y;
	/* calcul coords */
	// data->cam.coords[y][x] = (t_point) {.x = x * v->ex.x + y * ey.x + z * ez.x + tr.x, 
	// 								.y = x * ex.y + y * ey.y + z * ez.y + tr.y,
	// 								.z = x * ex.z + y * ey.z + z * ez.z + tr.z};
	return (v);
}

void	init(t_data *data, char **v, int c)
{
	(void)v;
	(void)c;
	init_map(data);
	if (!data->main.map.coords)
		exit(1); // error map
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->win = mlx_new_window(data->mlx, W, H, TITLE);
	if (!data->win)
	{
		free(data->mlx);
		exit(1);
	}
	data->main.canvas.w = W;
	data->main.canvas.h = H;
	init_canvas(data->mlx, &data->main.canvas);
	data->main.cam.mu = M_PI / 4;
	data->main.cam.alpha = 0 * M_PI / 4;
	data->main.cam.tr = (t_point){.x = 0, .y = 0, .z = 0};
	data->main.cam.ro = (t_point){.x = M_PI / 4, .y = 0, .z = 0};
	get_coords(data);
}
