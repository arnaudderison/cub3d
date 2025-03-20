/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:26 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/20 12:15:01 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Ajoute dans t_cub3d
int time_counter; // Initialiser à 0

// Fonction de bruit procédural
static unsigned int	random2D(int x, int y)
{
	unsigned int	h;

	h = (x * 92837111) ^ (y * 689287499);
	h = (h >> 13) ^ h;
	return (h * (h * h * 60493 + 19990303) + 1376312589);
}

static void	set_image_pixels(t_cub3d *cub3d, t_img *image, int x, int y)
{
	float	speed;
	float	phase;
	int		halo_intensity;
	float	twinkle;

	if (cub3d->modify_textures[y][x] > 0)
	{
		set_image_pixel(image, x, y, cub3d->modify_textures[y][x]);
		return ;
	}
	if (y < WIN_HEIGHT / 2 && BONUS)
	{
		if (random2D(x, y) % 666 < 4)
		{
			speed = 0.1f;
			phase = cub3d->time_counter * speed + random2D(x, y) % 1000;
			twinkle = sinf(phase) * sinf(phase * 2.7f);
			int intensity = 100 + 155 * fabsf(twinkle); // De 100 à 255
			set_image_pixel(image, x, y, intensity * 0x010101);
			if ((random2D(x, y) % 100) < 30)
			{
				for (int dx = -1; dx <= 1; dx++)
				{
					for (int dy = -1; dy <= 1; dy++)
					{
						if ((dx || dy) && x + dx >= 0 && x + dx < WIN_WIDTH && y
							+ dy >= 0)
						{
							halo_intensity = intensity - 50 - abs(dx * dy * 30);
							if (halo_intensity > 50)
							{
								set_image_pixel(image, x + dx, y + dy,
									halo_intensity * 0x010101);
							}
						}
					}
				}
			}
		}
		else
		{
			set_image_pixel(image, x, y, 0x121212);
		}
	}
	else if (y < WIN_HEIGHT - 1 && x % 3 == 0)
	{
		set_image_pixel(image, x, y, cub3d->datatex.hex_floor);
	}
}

static void	render_frame(t_cub3d *cub3d)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			set_image_pixels(cub3d, &cub3d->frame, x, y);
		y++;
	}
	mlx_put_image_to_window(cub3d->win.mlx, cub3d->win.window, cub3d->frame.img,
		0, 0);
}

// gestion du raycasting et du rendu
int	graphics_engine(t_cub3d *cub3d)
{
	t_img	image;

	image.img = NULL;
	cub3d->frame = image;
	init_img(cub3d, &cub3d->frame, WIN_WIDTH, WIN_HEIGHT);
	init_modify_textures(cub3d);
	raycasting(&cub3d->player, cub3d);
	render_frame(cub3d);
	if (BONUS)
		maps_engine(cub3d);
	mlx_destroy_image(cub3d->win.mlx, cub3d->frame.img);
	return (0);
}

int	render(t_cub3d *cub3d)
{
	cub3d->player.is_in_move += move_player(cub3d);
	if (cub3d->player.is_in_move == 0)
		return (0);
	graphics_engine(cub3d);
	return (0);
}
