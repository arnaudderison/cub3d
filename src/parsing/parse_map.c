/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:58:49 by plachard          #+#    #+#             */
/*   Updated: 2025/04/01 15:32:59 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**copy_map(char **map, int height)
{
	char	**map_cpy;
	int		i;

	map_cpy = ft_calloc(height + 1, sizeof(char *));
	if (!map_cpy)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
			return (ft_free_matrice(1, map_cpy), NULL);
	}
	return (map_cpy);
}

/*
 * Remplit récursivement la carte pour vérifier si elle est fermée.
 * Renvoie FAILED si une limite est atteinte ou une case vide (' ').
 */
static t_status	flood_fill(char **map_cpy, int x, int y, t_cub3d *cub3d)
{
	if (x < 0 || y < 0)
		return (FAILED);
	if (!map_cpy[y] || !map_cpy[y][x])
		return (FAILED);
	if ((x >= cub3d->map.width || y >= cub3d->map.height
			|| map_cpy[y][x] == ' '))
		return (FAILED);
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'X')
		return (SUCCESS);
	map_cpy[y][x] = 'X';
	if (!flood_fill(map_cpy, x + 1, y, cub3d))
		return (FAILED);
	if (!flood_fill(map_cpy, x - 1, y, cub3d))
		return (FAILED);
	if (!flood_fill(map_cpy, x, y + 1, cub3d))
		return (FAILED);
	if (!flood_fill(map_cpy, x, y - 1, cub3d))
		return (FAILED);
	return (SUCCESS);
}

/**
 * Vérifie que la carte est bien fermée en utilisant flood_fill.
 * Copie d'abord la carte,
	puis lance la vérification depuis la position du joueur.
 */
static t_status	map_locked_up(char **map_cpy, t_cub3d *cub3d)
{
	int	y;
	int	x;

	if (!map_cpy)
		return (FAILED);
	if (!flood_fill(map_cpy, cub3d->player.x, cub3d->player.y, cub3d))
		return (FAILED);
	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == '0')
				if (!flood_fill(map_cpy, x, y, cub3d))
					return (FAILED);
			++x;
		}
		++y;
	}
	return (SUCCESS);
}

t_status	parse_map(t_cub3d *cub3d)
{
	char	**map_cpy;

	map_cpy = copy_map(cub3d->map.matrice, cub3d->map.height);
	if (!map_cpy)
		return (FAILED);
	if (map_locked_up(map_cpy, cub3d) != SUCCESS)
	{
		ft_free_matrice(1, &map_cpy);
		return (FAILED);
	}
	ft_free_matrice(1, &map_cpy);
	return (SUCCESS);
}
