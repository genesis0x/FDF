/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:59:22 by hahadiou          #+#    #+#             */
/*   Updated: 2023/01/13 17:42:55 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = -1;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		return (ft_calloc(1, 1));
	}
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

static int	ft_countword(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		word_len;
	int		i;

	if (!s)
		return (0);
	strs = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!strs)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
		{
			word_len = strchr(s, c) - s;
			if (!strchr(s, c))
				word_len = strlen(s);
			strs[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	strs[i] = 0;
	return (strs);
}
