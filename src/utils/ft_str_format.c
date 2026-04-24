/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:21:53 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/04/23 18:03:27 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_str_format(char *string, char *sub_string)
{
	int	start;
	int	k;
	int	len_sub;
	int	len_string;

	if (!sub_string || !sub_string[0] || !string || !string[0])
		return (0);
	len_sub = ft_strlen(sub_string);
	len_string = ft_strlen(string);
	start = len_string - len_sub;
	k = 0;
	while (string[start])
	{
		if (string[start++] == sub_string[k++])
		{
			if (sub_string[k] == '\0')
				return (1);
		}
		else
		{
			start = start - k + 1;
			k = 0;
		}
	}
	return (0);
}
