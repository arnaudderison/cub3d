/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:08:38 by aderison          #+#    #+#             */
/*   Updated: 2025/03/26 18:14:56 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data_clean(t_cub3d *cub3d)
{
	cub3d->player = (t_player){0};
	cub3d->player.x = -1;
	cub3d->player.y = -1;
	cub3d->map = (t_map){0};
	cub3d->map.height = WIN_HEIGHT;
	cub3d->map.width = WIN_WIDTH;
	cub3d->radius = (t_radius){0};
	cub3d->win = (t_win){0};
	cub3d->datatex = (t_textures){0};
	cub3d->datatex.size = TEX_SIZE;
}

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (ac != 2)
		return (1);
	cub3d = (t_cub3d){0};
	init_data_clean(&cub3d);
	if (parsing(av, &cub3d) != SUCCESS)
	{
		freeall(&cub3d);
		ft_printf("Error\n");
		return (1);
	}
	init_mlx(&cub3d);
	init_textures(&cub3d);
	init_minimap(&cub3d.minimap, &cub3d);
	graphics_engine(&cub3d);
	key_listener(&cub3d);
	mlx_loop_hook(cub3d.win.mlx, &render, &cub3d);
	mlx_loop(cub3d.win.mlx);
	freeall(&cub3d);
	return (0);
}
