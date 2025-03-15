/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:18:15 by aderison          #+#    #+#             */
/*   Updated: 2025/03/14 21:45:01 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void freeall(t_cub3d *cub3d)
{
    if(!cub3d)
        exit(EXIT_FAILURE);
    if(cub3d->textures)
        ft_free_matrice(1, &cub3d->textures);
    if(cub3d->modify_textures)
        ft_free_matrice(1, &cub3d->modify_textures);
    if(cub3d->minimap.map)
        ft_free_matrice(1, &cub3d->minimap.map);
    destroy_win(cub3d);
}
