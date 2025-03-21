/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:33:12 by plachard          #+#    #+#             */
/*   Updated: 2025/03/21 18:00:37 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned long	rgb_to_hex(int *rgb_tab)
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

static bool	open_tex(t_textures data_tex)
{
	if (is_ext(data_tex.north, false) != SUCCESS)
		return (false);
	if (is_ext(data_tex.south, false) != SUCCESS)
		return (false);
	if (is_ext(data_tex.east, false) != SUCCESS)
		return (false);
	if (is_ext(data_tex.west, false) != SUCCESS)
		return (false);
	return (true);
}

t_status	init_color(t_cub3d *cub3d)
{
	if (!cub3d->datatex.floor || !cub3d->datatex.ceiling)
		return (FAILED);
	cub3d->datatex.hex_floor = rgb_to_hex(cub3d->datatex.floor);
	cub3d->datatex.hex_ceiling = rgb_to_hex(cub3d->datatex.ceiling);
	if (!open_tex(cub3d->datatex))
		return (FAILED);
	return (SUCCESS);
}
