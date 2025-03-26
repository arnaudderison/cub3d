/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:32:43 by plachard          #+#    #+#             */
/*   Updated: 2025/03/26 17:13:09 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// // BONUS
// static t_status	map_dup(char **data, t_cub3d *cub3d)
// {
// 	int	i;
// 	int	j;

// 	i = 6;
// 	j = 0;
// 	while (j < cub3d->map.height && ft_strchr(" 10DNSEW", data[i][0]))
// 	{
// 		cub3d->map.matrice[j] = ft_strdup(data[i]);
// 		if (!cub3d->map.matrice[j])
// 			return (FAILED);
// 		++j;
// 		++i;
// 	}
// 	if (!data[i])
// 		return (SUCCESS);
// 	return (FAILED);
// }

/* Extrait la carte à partir des données brutes et
l'enregistre dans `cub3d->map.matrice`. */
static t_status	map_dup(char **data, t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (j < cub3d->map.height
		&& ((BONUS == 0 && ft_strchr(" 10NSEW", data[i][0]))
		|| (BONUS == 1 && ft_strchr(" 10DNSEW", data[i][0]))))
	{
		cub3d->map.matrice[j] = ft_strdup(data[i]);
		if (!cub3d->map.matrice[j])
			return (FAILED);
		++j;
		++i;
	}
	if (!data[i])
		return (SUCCESS);
	return (FAILED);
}

// attention retour erreur strlen et si > intmax
/**
 * Alloue dynamiquement la carte et vérifie ses dimensions.
 * Attention : vérifier `ft_strlen` pour éviter un dépassement de `int max`.
 */
static t_status	map_alloc(t_cub3d *cub3d)
{
	int	i;
	int	width;

	i = 6;
	width = 0;
	if (cub3d->map.height < 3 || cub3d->map.height > MAP_HEIGHT_MAX)
		return (FAILED);
	while (cub3d->data[i])
	{
		if (ft_strlen(cub3d->data[i]) > width)
			width = ft_strlen(cub3d->data[i]);
		++i;
	}
	if (width > MAP_WIDTH_MAX)
		return (FAILED);
	cub3d->map.matrice = ft_calloc(cub3d->map.height + 1, sizeof(char *));
	if (!cub3d->map.matrice)
		return (FAILED);
	cub3d->map.width = width;
	return (SUCCESS);
}

t_status	init_map(t_cub3d *cub3d)
{
	if (map_alloc(cub3d) != SUCCESS)
		return (FAILED);
	if (!map_dup(cub3d->data, cub3d))
		return (FAILED);
	if (init_player(cub3d->map.matrice, cub3d) != SUCCESS)
		return (FAILED);
	if (cub3d->player.x == -1 || cub3d->player.y == -1)
		return (FAILED);
	return (SUCCESS);
}
