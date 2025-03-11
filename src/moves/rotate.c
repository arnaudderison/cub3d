/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 10:20:47 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/11 10:35:00 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	rotate_left_right(t_cub3d *cub3d, double rotspeed)
// {
// 	t_player	*p;
// 	double		tmp_x;

// 	p = &cub3d->player;
// 	tmp_x = p->dirX;
// 	p->dirX = p->dirX * cos(rotspeed) - p->dirY * sin(rotspeed);
// 	p->dirY = tmp_x * sin(rotspeed) + p->dirY * cos(rotspeed);
// 	tmp_x = p->planeX;
// 	p->planeX = p->planeX * cos(rotspeed) - p->planeY * sin(rotspeed);
// 	p->planeY = tmp_x * sin(rotspeed) + p->planeY * cos(rotspeed);
// 	return (1);
// }

static int	rotate_left_right(t_cub3d *cub3d, double rotspeed)
{
	t_player	*p;
	double		tmp_x;

	p = &cub3d->player;
	tmp_x = p->dirX;
	// Si rotspeed est positif, on tourne à gauche (antihoraire)
	// Si rotspeed est négatif, on tourne à droite (horaire)
	p->dirX = p->dirX * cos(rotspeed) - p->dirY * sin(rotspeed);
	p->dirY = tmp_x * sin(rotspeed) + p->dirY * cos(rotspeed);
	tmp_x = p->planeX;
	p->planeX = p->planeX * cos(rotspeed) - p->planeY * sin(rotspeed);
	p->planeY = tmp_x * sin(rotspeed) + p->planeY * cos(rotspeed);
	return (1);
}

int	rotate_player(t_cub3d *cub3d, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROTSPEED * rotdir;
	moved += rotate_left_right(cub3d, rotspeed);
	return (moved);
}
