/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_outline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:27:33 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/24 14:41:36 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_not_enclosed_by_wall(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.full_map[x])
	{
		y = 0;
		while (data->map.full_map[x][y])
		{
			if (x == 0 && ft_first_line_check(data->map.full_map[x][y], data))
				return (1);
			if (x == data->map.height - 1
				&& ft_last_line_check(data->map.full_map[x][y], x, data))
				return (1);
			y++;
		}
		if (x != 0 && x < data->map.height - 1)
		{
			if (ft_check_body_lines(data->map.full_map[x], data, x))
				return (1);
		}
		x++;
	}
	return (0);
}

int	ft_first_line_check(char tile, t_data *data)
{
	if (tile != WALL_MAP)
	{
		display_error("Map is not enclosed by walls at line 1");
		free_all(data);
		return (1);
	}
	return (0);
}

int	ft_last_line_check(char tile, int x, t_data *data)
{
	if (tile != WALL_MAP)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map is not enclosed by walls at line ", 2);
		ft_putnbr_fd(x + 1, 2);
		ft_putchar_fd('\n', 2);
		free_all(data);
		return (1);
	}
	return (0);
}

// if (line[len - 1] == '\r') case when user edit a map on windows OS

int	ft_check_body_lines(char *line, t_data *data, int x)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\r')
		len--;
	if (line[0] != WALL_MAP || line[len - 1] != WALL_MAP)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Map is not enclosed by walls at line ", 2);
		ft_putnbr_fd(x + 1, 2);
		ft_putchar_fd('\n', 2);
		free_all(data);
		return (1);
	}
	return (0);
}
