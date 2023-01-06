/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 22:42:25 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/06 16:30:36 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_canvas(void *mlx, t_canvas *c)
{
	c->img = mlx_new_image(mlx, c->w, c->h);
	// check if imgage is not NULL
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_len, &c->endian);
}

int	init_map(t_data *data)
{
	data->main.map_path = "maps/map.fdf"; //strdup(av[1]);
	data->main.map = parse_map(data->main.map_path);
	if (data->main.map.coords)
		return (0);
	return (1);
}

int	init_cam_coords(t_data *data)
{
	t_cam	*cam;
	t_map	*map;
	size_t	x;

	//t_point	p;
	map = &data->main.map;
	cam = &data->main.cam;
	x = -1;
	cam->coords = malloc(map->h * sizeof(t_point *));
	if (cam->coords == NULL)
		return (1);
	while (++x < map->h)
	{
		cam->coords[x] = malloc(map->w * sizeof(t_point));
		if (cam->coords[x] == NULL)
		{
			// free up to x and return (null);
			return (1);
		}
	}
	return (0);
}

void	init(t_data *data, int ac, char **av)
{
	(void)av;
	(void)ac;
	printf("init.\n");
	if (init_map(data))
	{
		// map error;
		exit(1);
	}
	if (init_cam_coords(data))
	{
		// free map data->main.map?
		// printf "ALLOCATION ERROR\n";
		exit(1);
	}
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
	data->main.cam.tr = (t_point){.x = 0, .y = 10, .z = -10};
	data->main.cam.ro = (t_point){.x = -M_PI_4, .y = 0, .z = 0};
	printf("end init.\n");
}
