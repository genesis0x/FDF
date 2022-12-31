/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:12 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/31 17:09:33 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*b;

	p = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (!p && !b)
		return (0);
	i = -1;
	while (++i < n)
		if (p[i] != b[i])
			return (p[i] - b[i]);
	return (0);
}
