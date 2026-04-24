/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:14:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 18:18:21 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_textures(t_data *data)
{
	init_map_images(data);
	init_player_images(data);
}

static int	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_all(data);
		mlx_error();
		return (1);
	}
	data->win = init_window(data);
	if (!data->win)
	{
		free_all(data);
		mlx_error();
		return (1);
	}
	init_textures(data);
	data->player.last_time = get_time();
	data->player.pos_x = data->player.x_start_p;
	data->player.pos_y = data->player.y_start_p;
	data->max_height = MAX_HEIGHT_WINDOW;
	data->max_width = MAX_WIDTH_WINDOW;
	init_hooks(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (error_from_parsing(ac, av[1]))
		return (1);
	ft_bzero(&data, sizeof(t_data));
	if (read_map(av[1], &data))
		return (1);
	if (map_not_rectangle_or_too_big(&data))
		return (1);
	if (map_not_enclosed_by_wall(&data))
		return (1);
	if (check_components(&data))
	{
		free_all(&data);
		return (1);
	}
	if (not_valid_path(&data))
		return (1);
	if (init_game(&data))
		return (1);
	draw_map(&data);
	mlx_loop_hook(data.mlx, render_animation, &data);
	mlx_loop(data.mlx);
	return (0);
}
