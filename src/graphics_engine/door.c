/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:31:53 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 16:27:26 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	player_near_door(t_player *player, int porteX, int porteY)
{
	double	distance;

	distance = sqrt(pow((int)player->x - porteX, 2) + pow((int)player->y
				- porteY, 2));
	if (distance <= 2.0)
		return (true);
	return (false);
}

 static bool is_door(t_cub3d *cub3d, int x, int y)
{
	return (cub3d->map.matrice[y][x] == 'D' || cub3d->map.matrice[y][x] == 'O');
}

bool is_close_door(t_cub3d *cub3d, int x, int y)
{
	return (cub3d->map.matrice[y][x] == 'D');
}

static void toggle_door(t_cub3d *cub3d, int x, int y)
{
	if(player_near_door(&cub3d->player, x, y))
		cub3d->map.matrice[y][x] = 'O';
	else
		cub3d->map.matrice[y][x] = 'D';
}

void handle_door(t_cub3d *cub3d, t_radius *rad)
{
	if(is_door(cub3d, rad->mapx, rad->mapy))
			toggle_door(cub3d, rad->mapx, rad->mapy);
}