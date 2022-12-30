/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:41:50 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/23 21:31:27 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buffer
{
	char	*buf;
	size_t	pos;// pos = 0 return buf[pos++]
	size_t	size; // size == BUFFER_SIZE
}	t_buffer;

typedef t_buffer	t_line;
typedef t_buffer	t_read;

char	*get_next_line(int fd);
void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
void	free_buffer(t_read *prb);

#endif
