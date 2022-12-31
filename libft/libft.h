/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:38:40 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/31 17:15:47 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
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
void					free_buffer(t_read *prb);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_atoi(const char *s);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_lstsize(t_list *lst);
size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					ft_putchar_fd(int fd, char c);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_calloc(size_t count, size_t size);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_lstadd_front(t_list **lst, t_list *n);
void					ft_lstadd_back(t_list **lst, t_list *n);
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
void					ft_lstdelone(t_list *lst, void (*del)(void *));
char					*ft_strdup(const char *s1);
char					*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					**ft_split(char const *s, char c);
char					*ft_strchr(const char *s, int c);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
char					*ft_itoa(int n);
t_list					*ft_lstnew(void *content);
t_list					*ft_lstlast(t_list *lst);
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));

#endif
