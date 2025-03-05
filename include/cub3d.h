/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:05:48 by aderison          #+#    #+#             */
/*   Updated: 2025/03/05 21:02:54 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include "colors.h"
#include <stdbool.h>
#include "mlx.h"

#define WIN_WIDTH 960
#define WIN_HEIGHT 720

#define TEX_SIZE 64

typedef enum s_status
{
	SUCCESS = 1,
	FAILED = 0,
	MALLOC = -1,
	PTR_NULL = -2,
	UNKNOWN = -3,
} t_status;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits; //taille d'un pixel
	int		size_line; // taille d'une ligne de pixel
	int		endian; //permet de savoir comment lire les pixels
}	t_img;

typedef struct s_textures
{
    char			*north;
	char			*south;
	char			*west;
	char			*east;
}   t_textures;

typedef struct s_win
{
    void		*mlx;
	void		*window;
}   t_win;

typedef struct s_map
{
    int width;
    int height;
    char **matrice;
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
    t_map map;
    t_win win;
    int **textures;
}   t_cub3d;


//handle error
void error(t_status status, t_cub3d *cub3d, void (*callback)(t_cub3d*));
void destroy_win(t_cub3d *cub3d);

//init
void init_mlx(t_cub3d *cub3d);
void create_img_from_xpm(t_cub3d *cub3d, t_img *img, char *path);
void	init_textures(t_cub3d *cub3d);

#endif