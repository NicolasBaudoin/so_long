/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 08:56:30 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 14:10:38 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_map(data->map.full_map);
	free_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	free_images(t_data *data)
{
	int	i;

	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.collectibles)
		mlx_destroy_image(data->mlx, data->img.collectibles);
	if (data->img.exit_state)
		mlx_destroy_image(data->mlx, data->img.exit_state);
	if (data->img.exit_open)
		mlx_destroy_image(data->mlx, data->img.exit_open);
	if (data->img.exit_closed)
		mlx_destroy_image(data->mlx, data->img.exit_closed);
	i = 0;
	while (i < 3)
	{
		if (data->player.img_right[i])
			mlx_destroy_image(data->mlx, data->player.img_right[i]);
		if (data->player.img_left[i])
			mlx_destroy_image(data->mlx, data->player.img_left[i]);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}
