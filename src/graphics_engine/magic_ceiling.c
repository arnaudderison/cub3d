/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:25:55 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 13:26:37 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	random2d(int x, int y)
{
	unsigned int	h;

	h = (x * 92837111) ^ (y * 689287499);
	h = (h >> 13) ^ h;
	return (h * (h * h * 60493 + 19990303) + 1376312589);
}

static void	draw_halo(t_img *image, int x, int y, int intensity)
{
	int	dx;
	int	dy;
	int	halo_intensity;

	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			if ((dx || dy) && x + dx >= 0 && x + dx < WIN_WIDTH && y + dy >= 0)
			{
				halo_intensity = intensity - 50 - abs(dx * dy * 30);
				if (halo_intensity > 50)
				{
					set_image_pixel(image, x + dx, y + dy, halo_intensity
						* 0x010101);
				}
			}
			dy++;
		}
		dx++;
	}
}

void	draw_star(t_cub3d *cub3d, t_img *image, int x, int y)
{
	float	speed;
	float	phase;
	float	twinkle;
	int		intensity;

	speed = 0.1f;
	phase = cub3d->time_counter * speed + random2d(x, y) % 1000;
	twinkle = sinf(phase) * sinf(phase * 2.7f);
	intensity = 100 + 155 * fabsf(twinkle);
	set_image_pixel(image, x, y, intensity * 0x010101);
	if ((random2d(x, y) % 100) < 30)
		draw_halo(image, x, y, intensity);
}
