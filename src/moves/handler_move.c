/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:57:30 by aderison          #+#    #+#             */
/*   Updated: 2025/03/21 17:48:32 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	move_player_forward(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x + cub3d->player.dirx * MOVESPEED;
	new_y = cub3d->player.y + cub3d->player.diry * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

static int	move_player_backward(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x - cub3d->player.dirx * MOVESPEED;
	new_y = cub3d->player.y - cub3d->player.diry * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

static int	move_player_left(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x + cub3d->player.diry * MOVESPEED;
	new_y = cub3d->player.y - cub3d->player.dirx * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

static int	move_player_right(t_cub3d *cub3d)
{
	double	new_x;
	double	new_y;

	new_x = cub3d->player.x - cub3d->player.diry * MOVESPEED;
	new_y = cub3d->player.y + cub3d->player.dirx * MOVESPEED;
	return (validate_move(cub3d, new_x, new_y));
}

int	move_player(t_cub3d *cub3d)
{
	int	moved;

	moved = 0;
	if (cub3d->player.movey == 1)
		moved += move_player_forward(cub3d);
	if (cub3d->player.movey == -1)
		moved += move_player_backward(cub3d);
	if (cub3d->player.movex == -1)
		moved += move_player_left(cub3d);
	if (cub3d->player.movex == 1)
		moved += move_player_right(cub3d);
	if (cub3d->player.rotate != 0)
		moved += rotate_player(cub3d, cub3d->player.rotate);
	return (moved);
}
