/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:37:55 by aderison          #+#    #+#             */
/*   Updated: 2025/03/10 17:58:33 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_cub3d *cub3d)
{
	// if (key == XK_Escape)
        //quit and free
	if (key == XK_w)
		cub3d->player.moveY = 1;
	if (key == XK_s)
		cub3d->player.moveY = -1;
	if (key == XK_d)
		cub3d->player.moveX = 1;
	if (key == XK_a)
		cub3d->player.moveX = -1;
    return 0;
}

static int	key_unpress_handler(int key, t_cub3d *cub3d)
{
	// if (key == XK_Escape)
        // free and quit
	if (key == XK_w && cub3d->player.moveY == 1)
		cub3d->player.moveY = 0;
	if (key == XK_s && cub3d->player.moveY == -1)
		cub3d->player.moveY = 0;
	if (key == XK_a && cub3d->player.moveX == -1)
		cub3d->player.moveX += 1;
	if (key == XK_d && cub3d->player.moveX == 1)
		cub3d->player.moveX -= 1;
    return 0;
}

void key_listener(t_cub3d *cub3d)
{
    mlx_hook(cub3d->win.window, KeyPress, KeyPressMask, key_press_handler, cub3d);
	mlx_hook(cub3d->win.window, KeyRelease, KeyReleaseMask, key_unpress_handler, cub3d);
}