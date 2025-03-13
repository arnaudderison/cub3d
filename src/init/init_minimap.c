/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:00 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/13 21:15:39 by aderison         ###   ########.fr       */
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

static char	*add_line(t_cub3d *cub3d, t_minimap *m, int y)
{
	char	*line;
	int		x;

	line = ft_calloc(m->size + 1, sizeof(char));
	if (!line)
		return (NULL);
	x = 0;
	while (x < m->size && x < cub3d->map.width)
	{
		if (!(y + m->startY < cub3d->map.height)
			|| !(x + m->startX < cub3d->map.width))
			line[x] = '\0';
		else if ((int)cub3d->player.x == (x + m->startX)
			&& (int)cub3d->player.y == (y + m->startY))
			line[x] = 'P';
		else if (cub3d->map.matrice[y + m->startY][x + m->startX] == '1')
			line[x] = '1';
		else if (cub3d->map.matrice[y + m->startY][x + m->startX] == '0' || cub3d->map.matrice[y + m->startY][x + m->startX] == 'N' || cub3d->map.matrice[y + m->startY][x + m->startX] == 'S' || cub3d->map.matrice[y + m->startY][x + m->startX] == 'W' || cub3d->map.matrice[y + m->startY][x + m->startX] == 'E')
			line[x] = '0';
		else
			line[x] = '\0';
		x++;
	}
	return (line);
}

static char **create_minimap(t_cub3d *cub3d, t_minimap *minimap)
{
    char **mmap;
    int y;

    mmap = ft_calloc(minimap->size + 1, sizeof(char *));
    // erreu si NULL
    y = 0;
    while(y < minimap->size && y < cub3d->map.height)
    {
        mmap[y] = add_line(cub3d, minimap, y);
        //free
        y++;
    }
    return (mmap);
}

void init_minimap(t_minimap *minimap, t_cub3d *cub3d)
{
    int map_size;

    map_size = MMAP_SIZE;
    *minimap = (t_minimap){0};
    minimap->width = WIDTH_MM;
    minimap->height = HEIGHT_MM;
    minimap->view_dist = 5;
    minimap->size = (2 * minimap->view_dist) + 1;
    minimap->tile_size = map_size / (2 * minimap->view_dist);
    minimap->startX = get_map_offset(minimap, cub3d->map.width, (int)cub3d->player.x);
    minimap->startY = get_map_offset(minimap, cub3d->map.height, (int)cub3d->player.y);
    minimap->map = create_minimap(cub3d, minimap);
    minimap->image = (t_img){0};
    render_minimap(cub3d, minimap);
    ft_free_matrice(1, &minimap->map);
}
