/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:06:39 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/13 21:22:06 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

# define MMAP_COLOR_PLAYER 0x27AE60
# define MMAP_COLOR_WALL 0x2C3E50
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x7F8C8D

static void	draw_pixels(t_minimap *minimap, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			set_image_pixel(&minimap->image, x + j, i + y, color);
			j++;
		}
		i++;
	}
}

static void draw_circle(t_minimap *minimap, int center_x, int center_y, int radius, int color)
{
    int x;
    int y;

    y = -radius;
    while (y <= radius)
    {
        x = -sqrt(radius * radius - y * y);
        while (x <= sqrt(radius * radius - y * y))
        {
            set_image_pixel(&minimap->image, center_x + x, center_y + y, color);
            x++;
        }
        y++;
    }
}

static void draw_tiles(t_minimap *m, int x, int y)
{
    if(m->map[y][x] == '0')
        draw_pixels(m, x * m->tile_size, y * m->tile_size, MMAP_COLOR_FLOOR);
    else if(m->map[y][x] == 'P')
    {
        draw_pixels(m, x * m->tile_size, y * m->tile_size, MMAP_COLOR_FLOOR);
        draw_circle(m, (x * m->tile_size) + m->tile_size / 2, (y * m->tile_size) + m->tile_size / 2, m->tile_size / 4, MMAP_COLOR_PLAYER);
    }
    else if(m->map[y][x] == '1')
        draw_pixels(m, x * m->tile_size, y * m->tile_size, MMAP_COLOR_WALL);
    else
        draw_pixels(m, x * m->tile_size, y * m->tile_size, MMAP_COLOR_SPACE);
}

static void draw_minimap(t_minimap  *m)
{
    int x;
    int y;

    y = -1;
    while(++y < m->size)
    {
        x = -1;
        while(++x < m->size)
        {
            if (!m->map[y] || !m->map[y][x]
				|| m->map[y][x] == '\0')
				break ;
            draw_tiles(m, x, y);
        }
    }
}

void render_minimap(t_cub3d *cub3d, t_minimap *m)
{
    int img_size;
    int map_size;

    map_size = MMAP_SIZE;
    img_size = MMAP_SIZE + m->tile_size;
    init_img(cub3d, &cub3d->minimap.image, img_size, img_size);
    draw_minimap(m);
    mlx_put_image_to_window(cub3d->win.mlx, cub3d->win.window, cub3d->minimap.image.img, m->tile_size, WIN_HEIGHT - (map_size + (m->tile_size * 2)) );
   mlx_destroy_image(cub3d->win.mlx, cub3d->minimap.image.img);
}