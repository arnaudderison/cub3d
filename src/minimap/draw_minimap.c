/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:06:39 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/13 19:05:18 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	clear_image(t_img *img)
// {
// 	int	*pixels;
// 	int	i;

// 	pixels = (int *)img->addr;
// 	i = 0;
// 	while (i < img->width * img->height)
// 	{
// 		pixels[i] = 0x000000;  // Couleur de fond
// 		i++;
// 	}
// }

static void	set_minimap_tile_pixels(t_minimap *minimap, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			// On dessine en multipliant par tile_size pour la position réelle
			set_image_pixel(&minimap->image, 
				x * minimap->tile_size + j, 
				y * minimap->tile_size + i, 
				color);
			j++;
		}
		i++;
	}
}

static bool is_valid_pos(int x, int y, t_map *map)
{
    return (x >= 0 && x < map->width && y >= 0 && y < map->height);
}

static int get_color(int x, int y, t_map *map)
{
    int color;

    if (map->matrice[y][x] == '1')
        color = 0x808080;
    else if (map->matrice[y][x] == '0')
        color = 0xFFFFFF;
    else
        color = 0x000000;
    return color;
}

static void init_vector(t_cub3d *cub3d)
{
    int playerX;
    int playerY;
    t_minimap *minimap;

    minimap = &cub3d->minimap;
    init_minimap(minimap);
    init_img(cub3d, &minimap->image, minimap->width, minimap->height);
    playerX = (int)(cub3d->player.x / minimap->tile_size);
    playerY = (int)(cub3d->player.y / minimap->tile_size);
    minimap->startX = playerX - minimap->viewX;
    minimap->startY = playerY - minimap->viewY;
    minimap->endX = playerX + minimap->viewX;
    minimap->endY = playerY + minimap->viewY;

}

void draw_minimap(t_cub3d *cub3d)
{
    int y;
    int x;
    t_minimap *minimap;
    int color;

    init_vector(cub3d);
    minimap = &cub3d->minimap;
    y = minimap->startY;
    while(y <= minimap->endY)
    {
        x = minimap->startX;
        while(x <= minimap->endX)
        {
            if(is_valid_pos(x, y, &cub3d->map))
            {
                color = get_color(x, y, &cub3d->map);
                printf("x: %d y: %d", (x - minimap->startX )* minimap->tile_size, (y - minimap->startY) * minimap->tile_size);
                set_minimap_tile_pixels(minimap, (x - minimap->startX ), (y - minimap->startY), color);
                // dessiner sur x - start 0
            }
            x++;
        }
        y++;
    }

    mlx_put_image_to_window(cub3d->win.mlx, cub3d->win.window, &cub3d->minimap.image, 100, 100);
	mlx_destroy_image(cub3d->win.mlx, &cub3d->minimap.image);
}


