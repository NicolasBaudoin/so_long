/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:15:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 18:16:20 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_invalid_format(char *map_str)
{
	int	len;

	if (!map_str || !map_str[0])
		return (1);
	len = ft_strlen(map_str);
	if (!ft_str_format(map_str, ".ber"))
	{
		display_error("invalid map format, please use '.ber'");
		return (1);
	}
	return (0);
}
