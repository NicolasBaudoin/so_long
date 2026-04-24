/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:12:11 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/22 14:59:30 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*init_window(t_data *data)
{
	void	*ptr;

	data->height = data->map.height * TILE_SIZE;
	data->width = data->map.width * TILE_SIZE;
	ptr = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	return (ptr);
}
