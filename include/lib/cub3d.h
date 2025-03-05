/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:05:48 by aderison          #+#    #+#             */
/*   Updated: 2025/03/05 18:20:08 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include "colors.h"
#include <stdbool.h>

typedef enum s_status
{
	SUCCESS = 1,
	FAILED = 0,
	MALLOC = -1,
	PTR_NULL = -2,
	UNKNOWN = -3,
} t_status;

typedef struct s_map
{
    int width;
    int height;
}   t_map;

typedef struct s_player
{
    double x;
    double y;
    double dirX;
    double dirY;
}   t_player;

typedef struct cub3d
{
    t_player player;
}   t_cub3d;

#endif