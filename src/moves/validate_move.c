/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:04:41 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 12:22:55 by aderison         ###   ########.fr       */
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
	if (BONUS)
		wall = is_wall(cub3d, x, y);
	if (x < 1.25 || x >= cub3d->map.width - 2.25)
		map = false;
	if (y < 1.25 || y >= cub3d->map.height - 1.25)
		map = false;
	return (map && !wall);
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