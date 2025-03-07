/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:26:36 by aderison          #+#    #+#             */
/*   Updated: 2025/03/07 19:22:17 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_img_from_xpm(t_cub3d *cub3d, t_img *img, char *path)
{
	t_win	win;

	int size; // taille d'un xpm pourrait changer a voir avec pauline !
	*img = (t_img){0};
	win = cub3d->win;
	size = TEX_SIZE;
	img->img = mlx_xpm_file_to_image(win.mlx, path, &size, &size);
	if (!img->img)
		error(PTR_NULL, cub3d, &destroy_win);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->pixel_bits,
		&img->size_line, &img->endian);
}

void	init_img(t_cub3d *cub3d, t_img *image, int width, int height)
{
	*image = (t_img){0};
	image->img = mlx_new_image(cub3d->win.mlx, width, height);
	// if (image->img == NULL)
	// free ? et exit
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
		&image->size_line, &image->endian);
	return ;
}
