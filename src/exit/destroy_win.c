/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:11:38 by aderison          #+#    #+#             */
/*   Updated: 2025/03/26 18:30:37 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_win(t_cub3d *cub3d)
{
	if (!cub3d)
		exit(1);
	if (cub3d->win.window && cub3d->win.mlx)
		mlx_destroy_window(cub3d->win.mlx, cub3d->win.window);
	if (cub3d->win.mlx)
	{
		mlx_destroy_display(cub3d->win.mlx);
		mlx_loop_end(cub3d->win.mlx);
		ft_free(1, &(cub3d->win.mlx));
	}
	return (0);
}
