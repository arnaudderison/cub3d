/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:47:32 by plachard          #+#    #+#             */
/*   Updated: 2025/03/19 16:27:22 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if the string is a valid texture identifier (NO, SO, EA, WE). */
bool	is_tex(char *path)
{
	int		count;
	char	first;
	char	second;

	if (!path || !path[0] || !path[1])
		return (false);
	count = 0;
	while (path[count] != ' ')
		if (count++ > 1)
			return (false);
	first = path[0];
	second = path[1];
	if (first == 'N' && second == 'O')
		return (true);
	if (first == 'S' && second == 'O')
		return (true);
	if (first == 'E' && second == 'A')
		return (true);
	if (first == 'W' && second == 'E')
		return (true);
	return (false);
}
