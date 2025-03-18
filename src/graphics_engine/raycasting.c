/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:36 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/16 00:38:17 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_radius(int x, t_radius *rad, t_player *player)
{
	*rad = (t_radius){0};
	rad->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	rad->dirX = player->dirX + player->planeX * rad->cameraX;
	rad->dirY = player->dirY + player->planeY * rad->cameraX;
	rad->mapX = (int)player->x;
	rad->mapY = (int)player->y;
	rad->deltadistX = fabs(1 / rad->dirX);
	rad->deltadistY = fabs(1 / rad->dirY); 
}

static void	set_dda(t_radius *rad, t_player *player)
{
	if (rad->dirX < 0)
	{
		rad->stepX = -1;
		rad->sidedistX = (player->x - rad->mapX) * rad->deltadistX;
	}
	else
	{
		rad->stepX = 1;
		rad->sidedistX = (rad->mapX + 1.0 - player->x) * rad->deltadistX;
	}
	if (rad->dirY < 0)
	{
		rad->stepY = -1;
		rad->sidedistY = (player->y - rad->mapY) * rad->deltadistY;
	}
	else
	{
		rad->stepY = 1;
		rad->sidedistY = (rad->mapY + 1.0 - player->y) * rad->deltadistY;
	}
}

static void	dda(t_cub3d *cub3d, t_radius *rad)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (rad->sidedistX < rad->sidedistY)
		{
			rad->sidedistX += rad->deltadistX;
			rad->mapX += rad->stepX;
			rad->side = 0;
		}
		else
		{
			rad->sidedistY += rad->deltadistY;
			rad->mapY += rad->stepY;
			rad->side = 1;
		}
		if (rad->mapY < 0.25 || rad->mapY < 0.25
			|| rad->mapY > cub3d->map.height - 0.25
			|| rad->mapY > cub3d->map.width - 1.25)
			break ;
		if(cub3d->map.matrice[rad->mapY][rad->mapX] == 'D' || cub3d->map.matrice[rad->mapY][rad->mapX] == 'O')
		{
			if(player_near_door(&cub3d->player, rad->mapX, rad->mapY))
			{
				cub3d->map.matrice[rad->mapY][rad->mapX] = 'O';
			}
			else
				cub3d->map.matrice[rad->mapY][rad->mapX] = 'D';
		}
		if (cub3d->map.matrice[rad->mapY][rad->mapX] == '1' || cub3d->map.matrice[rad->mapY][rad->mapX] == 'D')
			hit = 1;
	}
}

static void	calculate_line_height(t_radius *rad, t_player *player)
{
	if (rad->side == 0)
		rad->wall_dist = (rad->sidedistX - rad->deltadistX);
	else
		rad->wall_dist = (rad->sidedistY - rad->deltadistY);
	rad->line_height = (int)((double)WIN_HEIGHT / rad->wall_dist);
	rad->draw_start = -(rad->line_height) / 2 + WIN_HEIGHT / 2;
	if (rad->draw_start < 0)
		rad->draw_start = 0;
	rad->draw_end = rad->line_height / 2 + WIN_HEIGHT / 2;
	if (rad->draw_end >= WIN_HEIGHT)
		rad->draw_end = WIN_HEIGHT - 1;
	if (rad->side == 0)
		rad->wallX = player->y + rad->wall_dist * rad->dirY;
	else
		rad->wallX = player->x + rad->wall_dist * rad->dirX;
	rad->wallX -= floor(rad->wallX);
}

t_status	raycasting(t_player *player, t_cub3d *cub3d)
{
	t_radius	rad;
	int			x;

	x = 0;
	rad = cub3d->radius;
	cub3d->time_counter++;
	// rad = (t_radius){0};
	while (x < WIN_WIDTH)
	{
		// if(x % 2 == 0)
		{

			update_radius(x, &rad, player);
			set_dda(&rad, player);
			dda(cub3d, &rad);
			calculate_line_height(&rad, player);
			update_modify_textures(cub3d, &cub3d->datatex, &rad, x);
		}
		x++;
	}
	return (SUCCESS);
}
