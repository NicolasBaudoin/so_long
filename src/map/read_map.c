/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:13:59 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/24 14:52:08 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *map_name, t_data *data)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		display_perror();
		return (1);
	}
	data->map.full_map = ft_get_map(fd);
	if (!data->map.full_map || !data->map.full_map[0])
	{
		free_all(data);
		display_error("Empty map");
		close(fd);
		return (1);
	}
	data->map.height = ft_get_height(data->map.full_map);
	data->map.width = ft_get_width(data->map.full_map[0]);
	close(fd);
	return (0);
}

char	**ft_get_map(int fd)
{
	char	*map;
	char	*line;
	char	*tmp;
	char	**full_map;

	map = ft_strdup("");
	if (!map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map;
		map = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (!map)
			return (NULL);
	}
	full_map = ft_split(map, '\n');
	free(map);
	if (!full_map)
		return (NULL);
	return (full_map);
}

int	ft_get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_get_width(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	map_not_rectangle_or_too_big(t_data *data)
{
	int	i;

	i = 0;
	data->max_height = MAX_HEIGHT_WINDOW;
	data->max_width = MAX_WIDTH_WINDOW;
	while (data->map.full_map[i])
	{
		if (ft_get_width(data->map.full_map[i]) != data->map.width)
		{
			display_error("Map is not rectangular");
			free_all(data);
			return (1);
		}
		i++;
	}
	if (data->map.width > data->max_width / TILE_SIZE
		|| data->map.height > data->max_height / TILE_SIZE)
	{
		display_error("Map is too big.");
		free_all(data);
		return (1);
	}
	return (0);
}
