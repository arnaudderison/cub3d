/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:08:38 by aderison          #+#    #+#             */
/*   Updated: 2025/03/25 15:38:28 by arnaud           ###   ########.fr       */
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

static void	free_all(t_cub3d *cub3d)
{
	if (!cub3d)
		exit(EXIT_FAILURE);
	if (cub3d->data)
		ft_free_matrice(1, &cub3d->data);
	if (cub3d->map.matrice)
		ft_free_matrice(1, &cub3d->map.matrice);
	free_tex(cub3d);
	if (cub3d->textures)
		ft_free_matrice(1, &cub3d->textures);
	if (cub3d->modify_textures)
		ft_free_matrice(1, &cub3d->modify_textures);
	// if(cub3d->minimap.map)
	//     ft_free_matrice(1, &cub3d->minimap.map);
	destroy_win(cub3d);
}

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
		free_all(&cub3d);
		write(1, "Error\n", 6);
		return (1);
	}
	print_cub3d(&cub3d);
	init_mlx(&cub3d);
	init_textures(&cub3d);
	init_minimap(&cub3d.minimap, &cub3d);
	graphics_engine(&cub3d);
	key_listener(&cub3d);
	mlx_loop_hook(cub3d.win.mlx, &render, &cub3d);
	mlx_loop(cub3d.win.mlx);
	free_all(&cub3d);
	return (0);
}
