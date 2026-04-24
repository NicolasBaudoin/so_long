/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:55:48 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 18:05:01 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player_images(t_data *data)
{
	data->player.img_right[0] = load_image(data, CHICKEN_R0);
	data->player.img_right[1] = load_image(data, CHICKEN_R1);
	data->player.img_right[2] = load_image(data, CHICKEN_R2);
	data->player.img_left[0] = load_image(data, CHICKEN_L0);
	data->player.img_left[1] = load_image(data, CHICKEN_L1);
	data->player.img_left[2] = load_image(data, CHICKEN_L2);
}

void	init_map_images(t_data *data)
{
	data->img.wall = load_image(data, WALL_IMG);
	data->img.collectibles = load_image(data, COLLECTIBLES_IMG);
	data->img.floor = load_image(data, FLOOR_IMG);
	data->img.exit_open = load_image(data, EXIT_IMG);
	data->img.exit_closed = load_image(data, EXIT_CLOSED_IMG);
}

void	*load_image(t_data *data, char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (!img)
	{
		free_all(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Error loading image :", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	return (img);
}
