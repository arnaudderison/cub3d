/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:08:38 by aderison          #+#    #+#             */
/*   Updated: 2025/03/10 17:43:10 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
CETTE PARTIE EST TEMPORAIRE
cette partie doit etre faites dans le parsing
*/
#include <string.h>

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
	strcpy(carte[1], "111111000111111");
	strcpy(carte[2], "111110000011111");
	strcpy(carte[3], "1111000N0001111");
	strcpy(carte[4], "111000000000111");
	strcpy(carte[5], "110000000000011");
	strcpy(carte[6], "100001111100001");
	strcpy(carte[7], "110000111000011");
	strcpy(carte[8], "111000010000111");
	strcpy(carte[9], "111100000001111");
	strcpy(carte[10], "111110000011111");
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
	cub3d->player.dirX = 0;
	cub3d->player.dirY = -1;
	cub3d->player.planeX = -0.75;
	cub3d->player.planeY = 0;
}

int	main(void)
{
	t_cub3d	cub3d;

	cub3d = (t_cub3d){0};
	init_mlx(&cub3d);
	init_temp(&cub3d);
	init_textures(&cub3d);
	graphics_engine(&cub3d);
	key_listener(&cub3d);
	// ft_printf("test %c\n", cub3d.map.matrice[0][0]);
	mlx_loop_hook(cub3d.win.mlx, &render, &cub3d);
	mlx_loop(cub3d.win.mlx);
	return (0);
}
