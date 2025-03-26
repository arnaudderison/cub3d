/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:18:15 by aderison          #+#    #+#             */
/*   Updated: 2025/03/26 18:30:11 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_tex(t_cub3d *cub3d)
{
	if (cub3d->datatex.north)
		ft_free(1, &cub3d->datatex.north);
	if (cub3d->datatex.south)
		ft_free(1, &cub3d->datatex.south);
	if (cub3d->datatex.east)
		ft_free(1, &cub3d->datatex.east);
	if (cub3d->datatex.west)
		ft_free(1, &cub3d->datatex.west);
	if (cub3d->datatex.floor)
		ft_free(1, &cub3d->datatex.floor);
	if (cub3d->datatex.ceiling)
		ft_free(1, &cub3d->datatex.ceiling);
}

int	freeall(t_cub3d *cub3d)
{
	if (!cub3d)
		exit(EXIT_FAILURE);
	if (cub3d->textures)
		ft_free_matrice(1, &cub3d->textures);
	if (cub3d->modify_textures)
		ft_free_matrice(1, &cub3d->modify_textures);
	if (cub3d->minimap.map)
		ft_free_matrice(1, &cub3d->minimap.map);
	if (cub3d->data)
		ft_free_matrice(1, &cub3d->data);
	if (cub3d->map.matrice)
		ft_free_matrice(1, &cub3d->map.matrice);
	free_tex(cub3d);
	destroy_win(cub3d);
	return (0);
}
