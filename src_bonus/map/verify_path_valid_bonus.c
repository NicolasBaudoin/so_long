/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_valid_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:01:52 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 18:04:46 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	not_valid_path(t_data *data)
{
	char	**copy;

	copy = copy_map(data->map.full_map, data->map.height);
	if (!copy)
	{
		free_all(data);
		free_map(copy);
		return (1);
	}
	flood_fill(copy, data->player.x_start_p, data->player.y_start_p);
	if (impossible_to_win(copy))
	{
		free_all(data);
		free_map(copy);
		return (1);
	}
	free_map(copy);
	return (0);
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (!map[x] || !map[x][y])
		return ;
	if (map[x][y] == WALL_MAP || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	impossible_to_win(char **map)
{
	int	x;
	int	y;

	x = 0;
	if (!map)
		return (1);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == COLLECTIBLES || map[x][y] == EXIT_MAP)
			{
				display_error("Unwinable game, change for a valid path");
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
