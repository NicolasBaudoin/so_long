/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:15:36 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 14:01:32 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_animation(t_player *p)
{
	long	now;

	now = get_time();
	if (now - p->last_time > 150)
	{
		p->frame = (p->frame + 1) % 3;
		p->last_time = now;
	}
}
