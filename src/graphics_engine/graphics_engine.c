/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:26 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/10 17:32:51 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_frame_image_pixel(t_cub3d *cub3d, t_img *image, int x, int y)
{
	if (cub3d->modify_textures[y][x] > 0)
		set_image_pixel(image, x, y, cub3d->modify_textures[y][x]);
}

static void	render_frame(t_cub3d *cub3d)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(cub3d, &image, WIN_WIDTH, WIN_HEIGHT);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			set_frame_image_pixel(cub3d, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub3d->win.mlx, cub3d->win.window, image.img, 0, 0);
	mlx_destroy_image(cub3d->win.mlx, image.img);
}

// gestion du raycasting et du rendu
int	graphics_engine(t_cub3d *cub3d)
{
	cub3d->datatex = (t_textures){0};
	init_modify_textures(cub3d);
	raycasting(&cub3d->player, cub3d);
	render_frame(cub3d);
	return (0);
}

int render(t_cub3d *cub3d)
{
	cub3d->player.is_in_move = move_player(cub3d);
	if(!cub3d->player.is_in_move)
		return 0;
	graphics_engine(cub3d);
	return 0;
}
