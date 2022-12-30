/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:06:10 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/30 18:03:18 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_transformed_coords(t_data *data)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < data->main.map.h)
	{
		i = -1;
		while (++i < data->main.map.w)
		{
			return ;
		}
	}
}

void	start_fdf(t_data *data)
{
	calc_transformed_coords(data);
}

int	main(void)
{
	t_data	data;

	init(&data, 0, 0);
	register_events(&data);
	start_fdf(&data);
	return (0);
}
