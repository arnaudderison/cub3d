/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:04:41 by aderison          #+#    #+#             */
/*   Updated: 2025/03/25 15:35:56 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_wall(t_cub3d *cub3d, double x, double y)
{
	if (cub3d->map.matrice[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

static bool	is_valid_pos(t_cub3d *cub3d, double x, double y)
{
	bool	wall;
	bool	map;

	map = true;
	wall = false;
	if (0)
		wall = is_wall(cub3d, x, y);
	if (x < 0.25 || x >= (cub3d->map.width) - 1.25)
		map = false;
	if (y < 1.25 || y >= (cub3d->map.height) - 0.25)
		map = false;
	return (map && !wall);
}

int	validate_move(t_cub3d *cub3d, double new_x, double new_y)
{
	int	moved;

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
