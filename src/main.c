/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:08:38 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 16:54:10 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
CETTE PARTIE EST TEMPORAIRE
cette partie doit etre faites dans le parsing
*/
#include <string.h>

static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

static void	init_temp(t_cub3d *cub3d)
{
	char	**carte;

	// Allouer la mémoire pour le tableau de 12 pointeurs de chaînes
	carte = (char **)malloc(12 * sizeof(char *));
	// Vérifier si l'allocation a réussi
	if (carte == NULL)
	{
		perror("Échec de l'allocation de mémoire pour carte");
		// return (1);
	}
	// Initialiser chaque chaîne de caractères dans le tableau avec malloc
	carte[0] = (char *)malloc(16 * sizeof(char));
	carte[1] = (char *)malloc(16 * sizeof(char));
	carte[2] = (char *)malloc(16 * sizeof(char));
	carte[3] = (char *)malloc(16 * sizeof(char));
	carte[4] = (char *)malloc(16 * sizeof(char));
	carte[5] = (char *)malloc(16 * sizeof(char));
	carte[6] = (char *)malloc(16 * sizeof(char));
	carte[7] = (char *)malloc(16 * sizeof(char));
	carte[8] = (char *)malloc(16 * sizeof(char));
	carte[9] = (char *)malloc(16 * sizeof(char));
	carte[10] = (char *)malloc(16 * sizeof(char));
	carte[11] = (char *)malloc(16 * sizeof(char));
	// Vérifier si chaque allocation a réussi
	for (int i = 0; i < 12; i++)
	{
		if (carte[i] == NULL)
		{
			perror("Échec de l'allocation de mémoire pour carte[i]");
			// return (1);
		}
	}
	// Copier les chaînes dans le tableau
	strcpy(carte[0], "111111111111111");
	strcpy(carte[1], "100000000000001");
	strcpy(carte[2], "100000100000001");
	strcpy(carte[3], "1111110N0000001");
	strcpy(carte[4], "100001000000001");
	strcpy(carte[5], "100001000000001");
	strcpy(carte[6], "100001000000001");
	strcpy(carte[7], "1D1111000000001");
	strcpy(carte[8], "100000100000001");
	strcpy(carte[9], "100000010000001");
	strcpy(carte[10], "100000000000001");
	strcpy(carte[11], "111111111111111");
	// Afficher le tableau pour vérifier que tout fonctionne
	for (int i = 0; i < 12; i++)
	{
		printf("%s\n", carte[i]);
	}
	// Libérer la mémoire allouée
	// for (int i = 0; i < 12; i++)
	//{
	// free(carte[i]);
	//}
	// free(carte);
	// int *texs[4] = {
	//     "src/assets/textures/wolfenstein/grey_stone.xpm",
	//     "src/assets/textures/wolfenstein/purple_stone.xpm",
	//     "src/assets/textures/wolfenstein/red_brick.xpm",
	//     "src/assets/textures/wolfenstein/wood.xpm"
	// };
	cub3d->map.matrice = carte;
	cub3d->map.width = 16;
	cub3d->map.height = 12;
	cub3d->player.y = 3;
	cub3d->player.x = 7;
	cub3d->player.dirx = 0;
	cub3d->player.diry = -1;
	cub3d->player.planex = -0.75;
	cub3d->player.planey = 0;
}

int	main(void)
{
	t_cub3d	cub3d;

	cub3d = (t_cub3d){0};
	init_mlx(&cub3d);
	init_temp(&cub3d);
	init_textures(&cub3d);
	cub3d.errinfo = (t_errinfo){0};
	cub3d.time_counter = 0;
	cub3d.datatex = (t_textures){0};
	cub3d.datatex.floor = malloc(sizeof(int) * 4);
	cub3d.datatex.floor[0] = 10;
	cub3d.datatex.floor[1] = 38;
	cub3d.datatex.floor[2] = 146;
	cub3d.datatex.ceiling = malloc(sizeof(int) * 4);
	cub3d.datatex.ceiling[0] = 10;
	cub3d.datatex.ceiling[1] = 12;
	cub3d.datatex.ceiling[2] = 80;
	cub3d.datatex.hex_floor = convert_rgb_to_hex(cub3d.datatex.floor);
	cub3d.datatex.hex_ceiling = convert_rgb_to_hex(cub3d.datatex.ceiling);
	init_minimap(&cub3d.minimap, &cub3d);
	graphics_engine(&cub3d);
	key_listener(&cub3d);
	// ft_printf("test %c\n", cub3d.map.matrice[0][0]);
	// draw_minimap(&cub3d);
	mlx_loop_hook(cub3d.win.mlx, &render, &cub3d);
	mlx_loop(cub3d.win.mlx);
	return (0);
}
