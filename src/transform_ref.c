/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ref.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalmi <ysalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:01:28 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/04 16:21:05 by ysalmi           ###   ########.fr       */
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
	c = (t_point){.x = cos(ro.x), .y = cos(ro.y), .z = cos(ro.z)};
	s = (t_point){.x = sin(ro.x), .y = sin(ro.y), .z = sin(ro.z)};
	v = (t_vectors){
		.ex.x = c.y * c.x, .ex.y = -c.y * s.x, .ex.z = s.y, .ey.x = c.z * s.x
			+ s.z * s.y * c.x, .ey.y = c.z * c.x - s.z * s.y * s.x, .ey.z = -s.z
			* s.y, .ez.x = s.z * s.x - c.z * s.y * c.x, .ez.y = s.z * c.x + c.z
			* s.y * s.x, .ez.z = c.z * c.y};
	return (v);
}

t_point	transform_point(t_cam *cam, t_point p)
{
	t_point		transformed_point;
	t_vectors	v;

	v = cam->v;
	transformed_point = (t_point){
		.x = p.x * v.ex.x + p.y * v.ey.x + p.z * v.ez.x + cam->tr.x,
		.y = p.x * v.ex.y + p.y * v.ey.y + p.z * v.ez.y + cam->tr.y,
		.z = p.x * v.ex.z + p.y * v.ey.z + p.z * v.ez.z + cam->tr.z};
	return (transformed_point);
}
