/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:11:40 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/07 19:11:48 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}
