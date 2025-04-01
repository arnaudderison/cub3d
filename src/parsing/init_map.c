/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:32:43 by plachard          #+#    #+#             */
/*   Updated: 2025/04/01 15:26:01 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Extrait la carte à partir des données brutes et
l'enregistre dans `cub3d->map.matrice`. */
static t_status	map_dup(char **data, t_cub3d *cub3d, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	while (j < cub3d->map.height
		&& ((BONUS == 0 && ft_strchr(" 10NSEW", data[i][0]))
		|| (BONUS == 1 && ft_strchr(" 10DNSEW", data[i][0]))))
	{
		cub3d->map.matrice[j] = ft_strtrim(data[i], "\n");
		if (!cub3d->map.matrice[j])
			return (FAILED);
		++j;
		++i;
	}
	if (!data[i])
		return (SUCCESS);
	tmp = ft_strtrim(cub3d->data[i], " \n\t");
	if (ft_strlen(tmp) == 0)
		return (ft_free(1, &tmp), SUCCESS);
	ft_free(1, &tmp);
	return (FAILED);
}

static t_status	map_alloc(t_cub3d *cub3d, int i)
{
	int	width;
	int	tmp;

	tmp = i;
	width = 0;
	if (cub3d->map.height < 3 || cub3d->map.height > MAP_HEIGHT_MAX)
		return (FAILED);
	while (ft_strchr(cub3d->data[i], '1') || ft_strchr(cub3d->data[i], '0'))
	{
		if (ft_strlen(cub3d->data[i]) > width)
			width = ft_strlen(cub3d->data[i]);
		++i;
	}
	cub3d->map.height = i - tmp;
	if (width > MAP_WIDTH_MAX)
		return (FAILED);
	cub3d->map.matrice = ft_calloc(cub3d->map.height + 1, sizeof(char *));
	if (!cub3d->map.matrice)
		return (FAILED);
	cub3d->map.width = width;
	return (SUCCESS);
}

static int	ignore_empty_line(t_cub3d *cub3d)
{
	char	*tmp;
	int		i;

	i = 6;
	tmp = ft_strtrim(cub3d->data[i], " \n\t");
	while (ft_strlen(tmp) == 0)
	{
		++i;
		if (!cub3d->data[i])
		{
			ft_free(1, &tmp);
			return (-1);
		}
		ft_free(1, &tmp);
		tmp = ft_strtrim(cub3d->data[i], " \n\t");
	}
	ft_free(1, &tmp);
	return (i);
}

t_status	init_map(t_cub3d *cub3d)
{
	int	i;

	i = ignore_empty_line(cub3d);
	if (i < 0)
		return (FAILED);
	if (map_alloc(cub3d, i) != SUCCESS)
		return (FAILED);
	if (!map_dup(cub3d->data, cub3d, i))
		return (FAILED);
	if (init_player(cub3d->map.matrice, cub3d) != SUCCESS)
		return (FAILED);
	if (cub3d->player.x == -1 || cub3d->player.y == -1)
		return (FAILED);
	return (SUCCESS);
}
