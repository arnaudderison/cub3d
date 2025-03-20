/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:31:53 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 12:10:49 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	player_near_door(t_player *player, int porteX, int porteY)
{
	double	distance;

	distance = sqrt(pow((int)player->x - porteX, 2) + pow((int)player->y
				- porteY, 2));
	if (distance <= 2.0)
		return (true);
	return (false);
}
