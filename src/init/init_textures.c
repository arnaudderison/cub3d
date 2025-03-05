/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:22:56 by aderison          #+#    #+#             */
/*   Updated: 2025/03/05 21:02:22 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int *xpm_to_img(t_cub3d *cub3d, char *path)
{
    t_img img;
    int *buffer;
    int x;
    int y;

    create_img_from_xpm(cub3d, &img, path);
    buffer = ft_calloc(1, sizeof(int) * TEX_SIZE * TEX_SIZE);
    if (!buffer)
		error(MALLOC, cub3d, &destroy_win);
    y = 0;
	while (y < TEX_SIZE)
	{
		x = 0;
		while (x < TEX_SIZE)
		{
			buffer[y * TEX_SIZE + x]
				= img.addr[y * TEX_SIZE + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(cub3d->win.mlx, img.img);
	return (buffer);
}

void	init_textures(t_cub3d *cub3d)
{
    //les fichiers xpm peuvent etre different mais pauline doit gerer ca
	cub3d->textures = ft_calloc(5, sizeof(int*));
	if (!cub3d->textures)
		error(MALLOC, cub3d, &destroy_win);
	cub3d->textures[0] = xpm_to_img(cub3d, "src/assets/textures/wolfenstein/grey_stone.xpm");
	cub3d->textures[1] = xpm_to_img(cub3d, "src/assets/textures/wolfenstein/purple_stone.xpm");
	cub3d->textures[2] = xpm_to_img(cub3d, "src/assets/textures/wolfenstein/red_brick.xpm");
	cub3d->textures[3] = xpm_to_img(cub3d, "src/assets/textures/wolfenstein/wood.xpm");
}
