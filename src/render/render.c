/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:24:04 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 15:36:51 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_animation(t_data *data)
{
	draw_counter(data);
	draw_player(data);
	return (0);
}

void	draw_player(t_data *data)
{
	void	*img;

	update_player_animation(&data->player);
	if (data->player.direction == RIGHT)
		img = data->player.img_right[data->player.frame];
	else
		img = data->player.img_left[data->player.frame];
	mlx_put_image_to_window(
		data->mlx,
		data->win,
		img,
		data->player.pos_y * TILE_SIZE,
		data->player.pos_x * TILE_SIZE
		);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.full_map[x])
	{
		y = 0;
		while (data->map.full_map[x][y])
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img.floor,
				y * TILE_SIZE, x * TILE_SIZE);
			if (data->map.full_map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
					y * TILE_SIZE, x * TILE_SIZE);
			else if (data->map.full_map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.collectibles, y * TILE_SIZE, x * TILE_SIZE);
			else if (data->map.full_map[x][y] == 'E')
				handle_exit_img(data, y, x);
			y++;
		}
		x++;
	}
}

void	handle_exit_img(t_data *data, int y, int x)
{
	void	*img;

	if (data->collectibles.collected_counter
		== data->collectibles.max_to_collect)
		img = data->img.exit_open;
	else
		img = data->img.exit_closed;
	mlx_put_image_to_window(data->mlx, data->win, img,
		y * TILE_SIZE, x * TILE_SIZE);
}
