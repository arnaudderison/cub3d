/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_listener.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:37:55 by aderison          #+#    #+#             */
/*   Updated: 2025/03/13 11:22:14 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press_handler(int key, t_cub3d *cub3d)
{
	// if (key == XK_Escape)
	// quit and free
	if (key == XK_w)
		cub3d->player.moveY = 1;
	if (key == XK_s)
		cub3d->player.moveY = -1;
	if (key == XK_d)
		cub3d->player.moveX = 1;
	if (key == XK_a)
		cub3d->player.moveX = -1;
	if (key == XK_Left)
		cub3d->player.rotate += 1;
	if (key == XK_Right)
		cub3d->player.rotate -= 1;
	return (0);
}

static int	key_unpress_handler(int key, t_cub3d *cub3d)
{
	if (key == XK_Escape)
		error(SUCCESS, cub3d, &freeall);
	if (key == XK_w && cub3d->player.moveY == 1)
		cub3d->player.moveY = 0;
	if (key == XK_s && cub3d->player.moveY == -1)
		cub3d->player.moveY = 0;
	if (key == XK_a && cub3d->player.moveX == -1)
		cub3d->player.moveX += 1;
	if (key == XK_d && cub3d->player.moveX == 1)
		cub3d->player.moveX -= 1;
	if (key == XK_Left && cub3d->player.rotate <= 1)
		cub3d->player.rotate = 0;
	if (key == XK_Right && cub3d->player.rotate >= -1)
		cub3d->player.rotate = 0;
	return (0);
}

static void	wrap_mouse(t_cub3d *cub3d, int x, int y)
{
	if (x > WIN_WIDTH - DIST_EDGE_MOUSE_WRAP)
	{
		x = DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(cub3d->win.mlx, cub3d->win.window, x, y);
	}
	if (x < DIST_EDGE_MOUSE_WRAP)
	{
		x = WIN_WIDTH - DIST_EDGE_MOUSE_WRAP;
		mlx_mouse_move(cub3d->win.mlx, cub3d->win.window, x, y);
	}
}

static int	mouse_handler(int x, int y, t_cub3d *cub3d)
{
	static int	old_x = WIN_WIDTH / 2;

	wrap_mouse(cub3d, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		cub3d->player.is_in_move += rotate_player(cub3d, 1);
	else if (x > old_x)
		cub3d->player.is_in_move += rotate_player(cub3d, -1);
	old_x = x;
	return (0);;
}

void	key_listener(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win.window, KeyPress, KeyPressMask, key_press_handler,
		cub3d);
	mlx_hook(cub3d->win.window, KeyRelease, KeyReleaseMask, key_unpress_handler,
		cub3d);
	if (BONUS)
		mlx_hook(cub3d->win.window, MotionNotify, PointerMotionMask,
			mouse_handler, cub3d);
}