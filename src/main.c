/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:08:38 by aderison          #+#    #+#             */
/*   Updated: 2025/03/05 21:03:17 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
CETTE PARTIE EST TEMPORAIRE
cette partie doit etre faites dans le parsing
*/
static void init_temp(t_cub3d *cub3d)
{
	 char *carte[12] = {
        "111111111111111",
        "111111000111111",
        "111110000011111",
        "1111000N0001111",
        "111000000000111",
        "110000000000011",
        "100001111100001",
        "110000111000011",
        "111000010000111",
        "111100000001111",
        "111110000011111",
        "111111000111111"
    };
	// int *texs[4] = {
    //     "src/assets/textures/wolfenstein/grey_stone.xpm",
    //     "src/assets/textures/wolfenstein/purple_stone.xpm",
    //     "src/assets/textures/wolfenstein/red_brick.xpm",
    //     "src/assets/textures/wolfenstein/wood.xpm"
    // };
	cub3d->map.matrice = carte;
	cub3d->map.width = 16;
	cub3d->map.height = 12;

}

int	main(void)
{
	t_cub3d cub3d;

	cub3d = (t_cub3d){0};
	init_mlx(&cub3d);
	init_temp(&cub3d);
	init_textures(&cub3d);
	// ft_printf("test %c\n", cub3d.map.matrice[0][0]);
	mlx_loop(cub3d.win.mlx);
	return (0);
}
