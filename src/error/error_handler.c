/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:51:46 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/20 15:16:17 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_from_parsing(int ac, char *map_str)
{
	if (error_args_number(ac))
		return (1);
	else if (map_invalid_format(map_str))
		return (1);
	else
		return (0);
}

int	error_args_number(int ac)
{
	if (ac != 2)
	{
		display_error("Number of arguments isn't 2");
		return (1);
	}
	else
		return (0);
}
