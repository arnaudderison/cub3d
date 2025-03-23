/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_modify_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:26:10 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/20 15:16:18 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_open_door(t_cub3d *cub3d, int x, int y)
{
	if (x >= 0 && x < cub3d->map.width && y >= 0 && y < cub3d->map.height)
	{
		// ft_printf("x: %d, y: %d \n", x, y);
		return (cub3d->map.matrice[y][x] == 'D');
	}
	return false;
}

static void	get_texture_index(t_cub3d *cub3d, t_radius *rad)
{
	if (rad->side == 0)
	{
		if (rad->dirx < 0)
			cub3d->datatex.index = 3;
		else
			cub3d->datatex.index = 2;
	}
	else
	{
		if (rad->diry > 0)
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
	tex->x = (int)(rad->wallx * TEX_SIZE);
	if ((rad->side == 0 && rad->dirx < 0) || (rad->side == 1 && rad->diry > 0))
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
		if (is_open_door(cub3d, rad->mapx, rad->mapy))
			color = 0x11111111;
		if (color > 0)
			cub3d->modify_textures[y][x] = color;
		y++;
	}
}
