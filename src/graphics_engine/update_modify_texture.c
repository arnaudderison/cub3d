/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_modify_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:10 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/08 13:57:33 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_texture_index(t_cub3d *cub3d, t_radius *rad)
{
	if (rad->side == 0)
	{
		if (rad->dirX < 0)
			cub3d->datatex.index = 3;
		else
			cub3d->datatex.index = 2;
	}
	else
	{
		if (rad->dirY > 0)
			cub3d->datatex.index = 1;
		else
			cub3d->datatex.index = 0;
	}
}

void	update_modify_textures(t_cub3d *cub3d, t_textures *tex, t_radius *rad,
		int x)
{
	int	y;
	int	color;

	get_texture_index(cub3d, rad);
	tex->x = (int)(rad->wallX * TEX_SIZE);
	if ((rad->side == 0 && rad->dirX < 0) || (rad->side == 1 && rad->dirY > 0))
		tex->x = TEX_SIZE - tex->x - 1;
	tex->step = 1.0 * TEX_SIZE / rad->line_height;
	tex->pos = (rad->draw_start - WIN_HEIGHT / 2 + rad->line_height / 2)
		* tex->step;
	y = rad->draw_start;
	while (y < rad->draw_end)
	{
		tex->y = (int)tex->pos & (TEX_SIZE - 1);
		tex->pos += tex->step;
		color = cub3d->textures[tex->index][TEX_SIZE * tex->y + tex->x];
		// if (tex->index == 0 || tex->index == 2)
		// 	color = (color >> 1) & 8355711;
		if (color > 0)
		{
			cub3d->modify_textures[y][x] = color;
		}
		y++;
	}
}
