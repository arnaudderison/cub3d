/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:34:10 by plachard          #+#    #+#             */
/*   Updated: 2025/04/01 15:07:03 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_plane(t_cub3d *cub3d)
{
	if (cub3d->player.diry == 1)
	{
		cub3d->player.planex = 0.66;
		cub3d->player.planey = 0;
	}
	else if (cub3d->player.diry == -1)
	{
		cub3d->player.planex = -0.66;
		cub3d->player.planey = 0;
	}
	else if (cub3d->player.dirx == 1)
	{
		cub3d->player.planex = 0;
		cub3d->player.planey = -0.66;
	}
	else if (cub3d->player.dirx == -1)
	{
		cub3d->player.planex = 0;
		cub3d->player.planey = 0.66;
	}
}

/**
 * Initialise la position du joueur et définit sa direction initiale.
 */
static void	set_player_start(char **data, int x, int y, t_cub3d *cub3d)
{
	cub3d->player.x = x + 0.5f;
	cub3d->player.y = y + 0.5f;
	if (ft_strchr("NS", data[y][x]))
	{
		if (data[y][x] == 'N')
			cub3d->player.diry = -1;
		else if (data[y][x] == 'S')
			cub3d->player.diry = 1;
		cub3d->player.dirx = 0;
	}
	else if (ft_strchr("EW", data[y][x]))
	{
		if (data[y][x] == 'E')
			cub3d->player.dirx = 1;
		else if (data[y][x] == 'W')
			cub3d->player.dirx = -1;
		cub3d->player.diry = 0;
	}
}

static int	set_player(char **data, int x, int y, t_cub3d *cub3d)
{
	set_player_start(data, x, y, cub3d);
	set_player_plane(cub3d);
	return (1);
}

/*
 * Analyse les éléments de la carte, valide les caractères autorisés et
 * initialise la position du joueur (une seule fois).
 */
t_status	init_player(char **map, t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	flag_player;

	flag_player = 0;
	i = -1;
	while (++i < cub3d->map.height)
	{
		j = 0;
		while (map[i][j] && j < cub3d->map.width)
		{
			if ((BONUS == 0 && !ft_strchr("10 ", map[i][j]))
				|| (BONUS == 1 && !ft_strchr("D10 ", map[i][j])))
			{
				if (ft_strchr("NSEW", map[i][j]) && flag_player == 0)
					flag_player += set_player(map, j, i, cub3d);
				else
					return (FAILED);
			}
			++j;
		}
	}
	return (SUCCESS);
}
