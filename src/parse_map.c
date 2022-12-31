/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:12:52 by hahadiou          #+#    #+#             */
/*   Updated: 2022/12/31 17:26:26 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	is_valid_map(char *map_path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	map->w = strlen(line) - 1;
	map->h = 0;
	while (line)
	{
		map->h++;
		free(line);
		line = get_next_line(fd);
		if (line && strlen(line) != map->w + 1)
		{
			free(line);
			return (0);
		}
	}
	close(fd);
	return (1);
}

void	build_map(char *map_path, t_map *map)
{
	int		fd;
	size_t	i;
	size_t	j;

	map->coords = malloc(map->h * sizeof(char *));
	if (!map->coords)
		return ;
	fd = open(map_path, O_RDONLY);
	i = -1;
	while (++i < map->h)
	{
		map->coords[i] = get_next_line(fd);
		j = -1;
		while (++j < map->w)
			map->coords[i][j] -= 48;
	}
	close(fd);
}

t_map	parse_map(char *map_path)
{
	t_map	map;

	map.coords = 0;
	if (is_valid_map(map_path, &map))
		build_map(map_path, &map);
	return (map);
}
