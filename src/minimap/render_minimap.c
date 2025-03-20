/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:06:39 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/20 13:07:11 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	draw_circle(t_cub3d *cub3d, int center_x, int center_y, int radius)
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
				+ 100, MMAP_COLOR_PLAYER);
			x++;
		}
		y++;
	}
}

static void	draw_tiles(t_cub3d *cub3d, t_minimap *m, int x, int y)
{
	double		player_x;
	double		player_y;
	t_player	player;

	player = cub3d->player;
	player_x = (player.x - m->startx);
	player_y = (player.y - m->starty);
	if (m->map[y][x] == '0')
		draw_pixels(cub3d, x * m->tile_size, y * m->tile_size,
			MMAP_COLOR_FLOOR);
	else if (m->map[y][x] == '1')
		draw_pixels(cub3d, x * m->tile_size, y * m->tile_size, MMAP_COLOR_WALL);
	else
		draw_pixels(cub3d, x * m->tile_size, y * m->tile_size,
			MMAP_COLOR_SPACE);
	draw_circle(cub3d, (player_x * m->tile_size), (player_y * m->tile_size),
		m->tile_size / 3);
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
	draw_minimap(cub3d, m);
}
