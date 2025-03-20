/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:06:39 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/20 12:21:49 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MMAP_COLOR_PLAYER 0x27AE60
#define MMAP_COLOR_WALL 0x2C3E50
#define MMAP_COLOR_FLOOR 0xE6E6E6
#define MMAP_COLOR_SPACE 0x7F8C8D

static void	draw_pixels(t_cub3d *cub3d, int x, int y, int color)
{
	int			i;
	int			j;
	t_minimap	*minimap;

	minimap = &cub3d->minimap;
	i = 0;
	while (i < minimap->tile_size)
	{
		j = 0;
		while (j < minimap->tile_size)
		{
			set_image_pixel(&cub3d->frame, x + j + 100, i + y + 100, color);
			j++;
		}
		i++;
	}
}

static void	draw_circle(t_cub3d *cub3d, int center_x, int center_y, int radius,
		int color)
{
	int	x;
	int	y;

	y = -radius;
	while (y <= radius)
	{
		x = -sqrt(radius * radius - y * y);
		while (x <= sqrt(radius * radius - y * y))
		{
			set_image_pixel(&cub3d->frame, center_x + x + 100, center_y + y
				+ 100, color);
			x++;
		}
		y++;
	}
}

static void	draw_tiles(t_cub3d *cub3d, t_minimap *m, int x, int y)
{
	double		playerX;
	double		playerY;
	t_player	player;

	player = cub3d->player;
	playerX = (player.x - m->startx);
	playerY = (player.y - m->starty);
	if (m->map[y][x] == '0')
		draw_pixels(cub3d, x * m->tile_size, y * m->tile_size,
			MMAP_COLOR_FLOOR);
	else if (m->map[y][x] == '1')
		draw_pixels(cub3d, x * m->tile_size, y * m->tile_size, MMAP_COLOR_WALL);
	else
		draw_pixels(cub3d, x * m->tile_size, y * m->tile_size,
			MMAP_COLOR_SPACE);
	draw_circle(cub3d, (playerX * m->tile_size), (playerY * m->tile_size),
		m->tile_size / 3, MMAP_COLOR_PLAYER);
}

static void	draw_minimap(t_cub3d *cub3d, t_minimap *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->size)
	{
		x = -1;
		while (++x < m->size)
		{
			if (!m->map[y] || !m->map[y][x] || m->map[y][x] == '\0')
				break ;
			draw_tiles(cub3d, m, x, y);
		}
	}
}

void	render_minimap(t_cub3d *cub3d, t_minimap *m)
{
	// int img_size;
	// int map_size;

	// map_size = MMAP_SIZE;
	// img_size = MMAP_SIZE + m->tile_size;
	// init_img(cub3d, &cub3d->minimap.image, img_size, img_size);
	draw_minimap(cub3d, m);
	//     mlx_put_image_to_window(cub3d->win.mlx, cub3d->win.window,
		// cub3d->minimap.image.img, m->tile_size, WIN_HEIGHT - (map_size
		// 	+ (m->tile_size * 2)) );
	//    mlx_destroy_image(cub3d->win.mlx, cub3d->minimap.image.img);
}