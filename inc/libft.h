/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:38:40 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/20 15:47:28 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buffer	t_line;
typedef struct s_buffer	t_read;
typedef struct s_list	t_list;

struct					s_buffer
{
	char				*buf;
	size_t				pos;
	size_t				size;
};

struct					s_list
{
	void				*content;
	struct s_list		*next;
};

char					*get_next_line(int fd);
void					*ft_memcpy(void *dst, const void *src, size_t n);
size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_calloc(size_t count, size_t size);
char					*ft_strdup(const char *s1);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					**ft_split(char const *s, char c);
char					*ft_strchr(const char *s, int c);

#endif
