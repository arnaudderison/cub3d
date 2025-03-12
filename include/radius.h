/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:50:12 by aderison          #+#    #+#             */
/*   Updated: 2025/03/12 12:50:44 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIUS_H
# define RADIUS_H

typedef struct s_radius
{
	double			cameraX;
	double			dirX;
	double			dirY;
	int				mapX;
	int				mapY;
	int				stepX;
	int				stepY;
	double			sidedistX;
	double			sidedistY;
	double			deltadistX;
	double			deltadistY;
	double			wallX;
	double			wall_dist;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_radius;

#endif