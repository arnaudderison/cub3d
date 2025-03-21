/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:22:56 by aderison          #+#    #+#             */
/*   Updated: 2025/03/21 17:01:54 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	*xpm_to_img(t_cub3d *cub3d, char *path)
{
	t_img	img;
	int		*buffer;
	int		x;
	int		y;

	create_img_from_xpm(cub3d, &img, path);
	buffer = ft_calloc(1, sizeof(int) * TEX_SIZE * TEX_SIZE);
	if (!buffer)
	{
		set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
		error(MALLOC, &cub3d->errinfo, cub3d, &destroy_win);
	}
	y = -1;
	while (++y < TEX_SIZE)
	{
		x = -1;
		while (++x < TEX_SIZE)
			buffer[y * TEX_SIZE + x] = img.addr[y * TEX_SIZE + x];
	}
	mlx_destroy_image(cub3d->win.mlx, img.img);
	return (buffer);
}

void	init_modify_textures(t_cub3d *cub3d)
{
	int	i;

	if (cub3d->modify_textures)
		ft_free_matrice(1, &cub3d->modify_textures);
	cub3d->modify_textures = ft_calloc(WIN_HEIGHT + 1,
			sizeof * cub3d->modify_textures);
	if (!cub3d->modify_textures)
	{
		set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
		error(MALLOC, &cub3d->errinfo, cub3d, &freeall);
	}
	i = 0;
	while (i < WIN_HEIGHT)
	{
		cub3d->modify_textures[i] = ft_calloc(WIN_WIDTH + 1,
				sizeof * cub3d->modify_textures);
		if (!cub3d->modify_textures[i])
		{
			set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
			error(MALLOC, &cub3d->errinfo, cub3d, &freeall);
		}
		i++;
	}
}

void	init_textures(t_cub3d *cub3d)
{
	cub3d->textures = ft_calloc(5, sizeof(int *));
	if (!cub3d->textures)
	{
		set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
		error(MALLOC, &cub3d->errinfo, cub3d, &freeall);
	}
	cub3d->textures[NORTH] = xpm_to_img(cub3d,
			cub3d->datatex.north);
	cub3d->textures[SOUTH] = xpm_to_img(cub3d,
			cub3d->datatex.south);
	cub3d->textures[EAST] = xpm_to_img(cub3d,
			cub3d->datatex.east);
	cub3d->textures[WEST] = xpm_to_img(cub3d,
			cub3d->datatex.west);
}
