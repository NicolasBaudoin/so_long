/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_component_valid_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 09:02:25 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 18:04:34 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_components(t_data *data)
{
	int	x;
	int	y;
	int	p;
	int	e;
	int	c;

	init_counts(&p, &e, &c, &x);
	while (data->map.full_map[x])
	{
		y = 0;
		while (data->map.full_map[x][y])
		{
			if (count_components(data->map.full_map[x][y], &p, &e, &c))
				return (1);
			init_start_player(data->map.full_map[x][y], x, y, data);
			y++;
		}
		x++;
	}
	if (check_component_number(p, e, c))
		return (1);
	data->collectibles.max_to_collect = c;
	data->collectibles.collected_counter = 0;
	return (0);
}

void	init_counts(int *p, int *e, int *c, int *x)
{
	*x = 0;
	*p = 0;
	*e = 0;
	*c = 0;
}

int	count_components(char tile, int *p, int *e, int *c)
{
	if (tile == PLAYER)
		(*p)++;
	else if (tile == EXIT_MAP)
		(*e)++;
	else if (tile == COLLECTIBLES)
		(*c)++;
	else if (tile != WALL_MAP && tile != '0')
	{
		display_error("Invalid character");
		return (1);
	}
	return (0);
}

void	init_start_player(char tile, int x, int y, t_data *data)
{
	if (tile == PLAYER)
	{
		data->player.x_start_p = x;
		data->player.y_start_p = y;
	}
}

int	check_component_number(int p, int e, int c)
{
	if (p != 1)
	{
		if (p == 0)
			display_error("Player not found.");
		else
			display_error("Multiplayers found, only one player is allowed");
		return (1);
	}
	if (c < 1)
	{
		display_error("No collectibles to collect");
		return (1);
	}
	if (e != 1)
	{
		if (e == 0)
			display_error("Exit not found");
		else
			display_error("Multiple exits found, only one is allowed");
		return (1);
	}
	return (0);
}
