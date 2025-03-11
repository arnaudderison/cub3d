/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:04:41 by aderison          #+#    #+#             */
/*   Updated: 2025/03/11 11:03:53 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_pos(t_cub3d *cub3d, double x, double y)
{
	if (x < 0.50 || x >= cub3d->map.width - 1.25)
		return (false);
	if (y < 0.50 || y >= cub3d->map.height - 0.50)
		return (false);
	return (true);
}

int	validate_move(t_cub3d *cub3d, double new_x, double new_y)
{
	int moved;

	moved = 0;
	if (is_valid_pos(cub3d, new_x, cub3d->player.y))
	{
		cub3d->player.x = new_x;
		moved = 1;
	}
	if (is_valid_pos(cub3d, cub3d->player.x, new_y))
	{
		cub3d->player.y = new_y;
		moved = 1;
	}
	return (moved);
}