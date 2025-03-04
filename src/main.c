/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:08:38 by aderison          #+#    #+#             */
/*   Updated: 2025/03/04 21:31:28 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	// Initialiser MiniLibX
	mlx = mlx_init();
	if (!mlx)
		return (1);
	// Créer une fenêtre 500x500
	win = mlx_new_window(mlx, 500, 500, "Test MiniLibX");
	if (!win)
		return (1);
	// Afficher la fenêtre et attendre
	mlx_loop(mlx);
	return (0);
}
