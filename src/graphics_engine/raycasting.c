/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:36 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/20 16:36:58 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_radius(int x, t_radius *rad, t_player *player)
{
	*rad = (t_radius){0};
	rad->camerax = 2 * x / (double)WIN_WIDTH - 1;
	rad->dirx = player->dirx + player->planex * rad->camerax;
	rad->diry = player->diry + player->planey * rad->camerax;
	rad->mapx = (int)player->x;
	rad->mapy = (int)player->y;
	rad->deltadistx = fabs(1 / rad->dirx);
	rad->deltadisty = fabs(1 / rad->diry);
}

static void	set_dda(t_radius *rad, t_player *player)
{
	if (rad->dirx < 0)
	{
		rad->stepx = -1;
		rad->sidedistx = (player->x - rad->mapx) * rad->deltadistx;
	}
	else
	{
		rad->stepx = 1;
		rad->sidedistx = (rad->mapx + 1.0 - player->x) * rad->deltadistx;
	}
	if (rad->diry < 0)
	{
		rad->stepy = -1;
		rad->sidedisty = (player->y - rad->mapy) * rad->deltadisty;
	}
	else
	{
		rad->stepy = 1;
		rad->sidedisty = (rad->mapy + 1.0 - player->y) * rad->deltadisty;
	}
}

static void	dda(t_cub3d *cub3d, t_radius *rad)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (rad->sidedistx < rad->sidedisty)
		{
			rad->sidedistx += rad->deltadistx;
			rad->mapx += rad->stepx;
			rad->side = 0;
		}
		else
		{
			rad->sidedisty += rad->deltadisty;
			rad->mapy += rad->stepy;
			rad->side = 1;
		}
		if (rad->mapy < 0.25 || rad->mapy < 0.25
			|| rad->mapy > cub3d->map.height - 0.25
			|| rad->mapy > cub3d->map.width - 1.25)
			break ;
		handle_door(cub3d, rad, &hit);
		if (cub3d->map.matrice[rad->mapy][rad->mapx] == '1')
			hit = 1;
	}
}

static void	calculate_line_height(t_radius *rad, t_player *player)
{
	if (rad->side == 0)
		rad->wall_dist = (rad->sidedistx - rad->deltadistx);
	else
		rad->wall_dist = (rad->sidedisty - rad->deltadisty);
	rad->line_height = (int)((double)WIN_HEIGHT / rad->wall_dist);
	rad->draw_start = -(rad->line_height) / 2 + WIN_HEIGHT / 2;
	if (rad->draw_start < 0)
		rad->draw_start = 0;
	rad->draw_end = rad->line_height / 2 + WIN_HEIGHT / 2;
	if (rad->draw_end >= WIN_HEIGHT)
		rad->draw_end = WIN_HEIGHT - 1;
	if (rad->side == 0)
		rad->wallx = player->y + rad->wall_dist * rad->diry;
	else
		rad->wallx = player->x + rad->wall_dist * rad->dirx;
	rad->wallx -= floor(rad->wallx);
}

t_status	raycasting(t_player *player, t_cub3d *cub3d)
{
	t_radius	rad;
	int			x;

	x = 0;
	rad = cub3d->radius;
	cub3d->time_counter++;
	while (x < WIN_WIDTH)
	{
		update_radius(x, &rad, player);
		set_dda(&rad, player);
		dda(cub3d, &rad);
		calculate_line_height(&rad, player);
		update_modify_textures(cub3d, &cub3d->datatex, &rad, x);
		x++;
	}
	return (SUCCESS);
}
