/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:23 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/13 15:55:27 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	key_handler(int key, t_data *data)
{
	printf("key: %d\n", key);
	if (key == K_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == K_A) // y translation
	{
		data->main.cam.tr.y -= 1;
		printf("translate y : %f\n", data->main.cam.tr.y);
		start_fdf(data);
	}
	if (key == K_S) //rotation
	{
		data->main.cam.ro.z += 0.05;
		printf("angle => %f\n", data->main.cam.ro.z);
		start_fdf(data);
	}
	if (key == K_D) // x translation 
	{
		data->main.cam.tr.x += 1;
		start_fdf(data);
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	register_events(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, key_handler, data);
	mlx_hook(data->win, ON_DESTROY, 0, close_window, data);
}
