/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:00 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/13 15:47:05 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_minimap(t_minimap *minimap)
{
    *minimap = (t_minimap){0};
    minimap->width = WIDTH_MM;
    minimap->height = HEIGHT_MM;
    minimap->tile_size = TILE_SIZE;
    minimap->viewX = 4;
    minimap->viewY = 4;
    minimap->image = (t_img){0};
}
