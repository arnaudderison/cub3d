/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:57:30 by aderison          #+#    #+#             */
/*   Updated: 2025/03/11 10:27:02 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_player_forward(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x + cub3d->player.dirX * MOVESPEED;
	new_y = cub3d->player.y + cub3d->player.dirY * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

static int	move_player_backward(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x - cub3d->player.dirX * MOVESPEED;
	new_y = cub3d->player.y - cub3d->player.dirY * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

static int	move_player_left(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x - cub3d->player.dirY * MOVESPEED;
	new_y = cub3d->player.y + cub3d->player.dirX * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

static int	move_player_right(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x + cub3d->player.dirY * MOVESPEED;
	new_y = cub3d->player.y - cub3d->player.dirX * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

int	move_player(t_cub3d *cub3d)
{
	int	moved;

	moved = 0;
	if (cub3d->player.moveY == 1)
		moved += move_player_forward(cub3d);
	if (cub3d->player.moveY == -1)
		moved += move_player_backward(cub3d);
	if (cub3d->player.moveX == -1)
		moved += move_player_left(cub3d);
	if (cub3d->player.moveX == 1)
		moved += move_player_right(cub3d);
	if (cub3d->player.rotate != 0)
		moved += rotate_player(cub3d, cub3d->player.rotate);
	return (moved);
}
