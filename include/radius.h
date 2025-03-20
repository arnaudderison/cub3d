/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:50:12 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 12:09:31 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIUS_H
# define RADIUS_H

typedef struct s_radius
{
	double			camerax;
	double			dirx;
	double			diry;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			wallx;
	double			wall_dist;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_radius;

#endif