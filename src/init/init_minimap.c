/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:00 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/26 19:36:39 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_offset(t_minimap *minimap, int mapsize, int pos)
{
	if (pos > minimap->view_dist && mapsize - pos > minimap->view_dist + 1)
		return (pos - minimap->view_dist);
	if (pos > minimap->view_dist && mapsize - pos <= minimap->view_dist + 1)
		return (mapsize - minimap->size);
	return (0);
}

static void	update_mmap(t_cub3d *cub3d, t_minimap *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->size)
	{
		x = -1;
		while (++x < m->size)
		{
			if (y + m->starty > cub3d->map.height - 1 || x
				+ m->startx > cub3d->map.width - 1)
				continue ;
			if (cub3d->map.matrice[y + m->starty][x + m->startx] == '1')
				m->map[y][x] = '1';
			else if (cub3d->map.matrice[y + m->starty][x + m->startx])
				m->map[y][x] = '0';
			else
				m->map[y][x] = '\0';
		}
	}
}

static char	**create_minimap(t_cub3d *cub3d, t_minimap *minimap)
{
	char	**mmap;
	int		y;

	mmap = ft_calloc(minimap->size + 1, sizeof(char *));
	if (!mmap)
	{
		set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
		error(MALLOC, &cub3d->errinfo, cub3d, &freeall);
	}
	y = -1;
	while (++y < minimap->size && y < cub3d->map.height)
	{
		mmap[y] = ft_calloc(minimap->size + 1, sizeof(char));
		if (!mmap[y])
		{
			ft_free_matrice(1, &mmap);
			set_errinfo(&cub3d->errinfo, __LINE__, __FILE__);
			error(MALLOC, &cub3d->errinfo, cub3d, &freeall);
		}
	}
	return (mmap);
}

void	init_minimap(t_minimap *minimap, t_cub3d *cub3d)
{
	*minimap = (t_minimap){0};
	minimap->width = WIDTH_MM;
	minimap->height = HEIGHT_MM;
	minimap->view_dist = 5;
	minimap->size = (2 * minimap->view_dist) + 1;
	minimap->tile_size = MMAP_SIZE / (2 * minimap->view_dist);
	minimap->map = create_minimap(cub3d, minimap);
}

int	maps_engine(t_cub3d *cub3d)
{
	cub3d->minimap.startx = get_map_offset(&cub3d->minimap, \
		cub3d->map.width - 1, (int)cub3d->player.x);
	cub3d->minimap.starty = get_map_offset(&cub3d->minimap, \
		cub3d->map.height - 1, (int)cub3d->player.y);
	update_mmap(cub3d, &cub3d->minimap);
	cub3d->minimap.image = (t_img){0};
	render_minimap(cub3d, &cub3d->minimap);
	return (0);
}
