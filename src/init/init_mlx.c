/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:00:19 by aderison          #+#    #+#             */
/*   Updated: 2025/03/05 19:40:26 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_mlx(t_cub3d *cub3d)
{
    cub3d->win.mlx = mlx_init();
    if(!cub3d->win.mlx)
        error(PTR_NULL, NULL, NULL);
    cub3d->win.window = mlx_new_window(cub3d->win.mlx,
    WIN_WIDTH, WIN_HEIGHT, "cub3d");
    if(!cub3d->win.window)
        error(PTR_NULL, cub3d, &destroy_win);
}
