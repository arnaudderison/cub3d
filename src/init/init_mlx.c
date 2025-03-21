/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:00:19 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 17:04:00 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_cub3d *cub3d)
{
	cub3d->win.mlx = mlx_init();
	if (!cub3d->win.mlx)
	{
		set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
		error(PTR_NULL, &cub3d->errinfo, NULL, NULL);
	}
	cub3d->win.window = mlx_new_window(cub3d->win.mlx, WIN_WIDTH, WIN_HEIGHT,
			"cub3d");
	if (!cub3d->win.window)
	{
		set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
		error(PTR_NULL, &cub3d->errinfo, cub3d, &destroy_win);
	}
}
