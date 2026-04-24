/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:46:58 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 18:04:22 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_hooks(t_data *data)
{
	mlx_key_hook(data->win, handle_keypress, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	close_esc(keycode, data);
	if (keycode == KEY_W || keycode == ARROW_UP)
		move_player(data, -1, 0);
	if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_player(data, 1, 0);
	if (keycode == KEY_A || keycode == ARROW_LEFT)
	{
		data->player.direction = LEFT;
		move_player(data, 0, -1);
	}
	if (keycode == KEY_D || keycode == ARROW_RIGHT)
	{
		data->player.direction = RIGHT;
		move_player(data, 0, 1);
	}
	return (0);
}
