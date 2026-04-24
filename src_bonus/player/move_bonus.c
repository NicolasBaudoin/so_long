/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 07:43:18 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/24 14:37:55 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player( t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player.pos_x + dx;
	new_y = data->player.pos_y + dy;
	if (!data->map.full_map[new_x] || !data->map.full_map[new_x][new_y])
		return ;
	if (data->map.full_map[new_x][new_y] == WALL_MAP)
		return ;
	if (data->map.full_map[new_x][new_y] == COLLECTIBLES)
	{
		data->map.full_map[new_x][new_y] = '0';
		data->collectibles.collected_counter++;
	}
	if (handle_exit_condition(data, data->map.full_map[new_x][new_y])
		&& data->map.full_map[new_x][new_y] == EXIT_MAP)
		return ;
	draw_map(data);
	data->player.pos_x = new_x;
	data->player.pos_y = new_y;
	data->player.counter_move++;
	ft_putstr_fd("Moves : ", 1);
	ft_putnbr_fd(data->player.counter_move, 1);
	ft_putchar_fd('\n', 1);
}

int	all_collectibles_collected(t_data *data)
{
	if (data->collectibles.collected_counter
		== data->collectibles.max_to_collect)
		return (1);
	else
		return (0);
}

int	handle_exit_condition(t_data *data, char tile)
{
	if (data->collectibles.collected_counter
		== data->collectibles.max_to_collect && tile == EXIT_MAP)
	{
		ft_putstr_fd("Moves : ", 1);
		ft_putnbr_fd(data->player.counter_move + 1, 1);
		ft_putchar_fd('\n', 1);
		ft_putstr_fd("YOU WIN\n", 1);
		free_all(data);
		exit(0);
		return (1);
	}
	return (0);
}

void	draw_counter(t_data *data)
{
	char	*str_move;
	char	*join;
	char	*str_collectible;

	str_move = ft_itoa(data->player.counter_move);
	join = ft_strjoin("Move : ", str_move);
	str_collectible = ft_itoa(data->collectibles.collected_counter);
	mlx_string_put(data->mlx, data->win, data->player.pos_y * TILE_SIZE,
		data->player.pos_x * TILE_SIZE, 0xFFFFFF, join);
	free(str_move);
	free(join);
	mlx_string_put(data->mlx, data->win, data->player.pos_y * TILE_SIZE - 26,
		data->player.pos_x * TILE_SIZE + 16, 0xffe600, str_collectible);
	free(str_collectible);
	draw_max_collectible(data);
}

void	draw_max_collectible(t_data *data)
{
	char	*str_max_collectible;
	char	*slash;

	str_max_collectible = ft_itoa(data->collectibles.max_to_collect);
	slash = "/";
	mlx_string_put(data->mlx, data->win, data->player.pos_y * TILE_SIZE - 13,
		data->player.pos_x * TILE_SIZE + 25, 0xffe600, str_max_collectible);
	free(str_max_collectible);
	mlx_string_put(data->mlx, data->win, data->player.pos_y * TILE_SIZE - 16,
		data->player.pos_x * TILE_SIZE + 20, 0xffe600, slash);
}
