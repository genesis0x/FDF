/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:53 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/02 12:55:38 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	print_point(t_point p)
{
	printf("\t[%10.5f]\t[%10.5f]\t[%10.5f]\n", p.x, p.y, p.z);
}
