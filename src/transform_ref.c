/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:01:28 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/21 19:40:08 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vectors	calculate_vectors(t_data *data)
{
	t_vectors	v;
	t_point		c;
	t_point		s;
	t_point		ro;

	ro = data->main.cam.ro;
	c = (t_point){.x = cos(ro.x), .y = cos(ro.y), .z = 0};
	s = (t_point){.x = sin(ro.x), .y = sin(ro.y), .z = 0};
	v = (t_vectors){
		.ex.x = c.x, .ex.y = s.x * c.y, .ex.z = -s.x * s.y,
		.ey.x = -s.x, .ey.y = c.x * c.y, .ey.z = -c.x * s.y,
		.ez.x = 0, .ez.y = s.y, .ez.z = c.y};
	return (v);
}

t_point	transform_point(t_cam *cam, t_point p)
{
	t_point		transformed_point;
	t_vectors	v;

	v = cam->v;
	transformed_point = (t_point){
		.x = p.x * v.ex.x + p.y * v.ey.x + p.z * v.ez.x - cam->tr.x,
		.y = p.x * v.ex.y + p.y * v.ey.y + p.z * v.ez.y - cam->tr.y,
		.z = p.x * v.ex.z + p.y * v.ey.z + p.z * v.ez.z - cam->tr.z};
	return (transformed_point);
}
