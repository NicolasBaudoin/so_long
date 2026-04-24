/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:00:23 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/20 15:17:46 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_error(char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putchar_fd('\n', 2);
}

void	display_perror(void)
{
	ft_putstr_fd("Error\n", 2);
	perror("Message from perror ");
}

int	mlx_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("MLX failed\n", 2);
	return (1);
}
