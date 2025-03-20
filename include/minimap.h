/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:55:27 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/20 20:38:07 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "window.h"

# define HEIGHT_MM 150
# define WIDTH_MM 150
# define MMAP_SIZE 200

typedef struct s_minimap
{
	char	**map;
	int		width;
	int		height;
	int		size;
	int		tile_size;
	int		view_dist;
	int		startx;
	int		starty;
	int		endx;
	int		endy;
	t_img	image;
}			t_minimap;

#endif