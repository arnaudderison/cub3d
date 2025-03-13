/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:55:27 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/13 17:49:20 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

#include "window.h"

#define HEIGHT_MM 150;
#define WIDTH_MM 150;
#define TILE_SIZE 5;

typedef struct s_minimap
{
    int width;
    int height;
    int tile_size;
    int viewX;
    int viewY;
    int startX;
    int startY;
    int endX;
    int endY;
    t_img image;
} t_minimap;

#endif