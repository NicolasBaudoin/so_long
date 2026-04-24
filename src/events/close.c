/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:46:58 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 13:04:06 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_esc(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		free_all(data);
		exit(0);
	}
	return (0);
}

int	close_window(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}
