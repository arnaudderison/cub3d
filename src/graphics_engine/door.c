/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:31:53 by aderison          #+#    #+#             */
/*   Updated: 2025/03/15 20:53:06 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool player_near_door(t_player *player, int porteX, int porteY)
{
    double distance;
    
    distance = sqrt(pow((int)player->x - porteX, 2) + pow((int)player->y - porteY, 2));
    if (distance <= 2.0)
    {
        // printf("player: x %f y %f || porte x %d y %x\n", player->x, player->y, porteX, porteY);
        return true;
    }
    return false;
}

