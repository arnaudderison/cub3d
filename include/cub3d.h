/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:05:48 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 22:03:54 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define MAP_WIDTH_MAX 50
# define MAP_HEIGHT_MAX 50

# define TEX_SIZE 64

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define MOVESPEED 0.1
# define ROTSPEED 0.1

typedef enum s_status
{
	SUCCESS = 1,
	FAILED = 0,
	MALLOC = -1,
	PTR_NULL = -2,
	UNKNOWN = -3,
}					t_status;

typedef enum	e_wall
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_wall;

typedef struct s_img
{
	void			*img;
	int				*addr;
	int pixel_bits; // taille d'un pixel
	int size_line;  // taille d'une ligne de pixel
	int endian;     // permet de savoir comment lire les pixels
}					t_img;

typedef struct s_textures
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned int	hex_floor;
	unsigned int	hex_ceiling;
	int				size;
	int				x;
	int				y;
	double			step;
	double			pos;
	int				index;
}					t_textures;

typedef struct s_win
{
	void			*mlx;
	void			*window;
}					t_win;

typedef struct s_map
{
	int				width;
	int				height;
	char			**matrice;
}					t_map;

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

typedef struct s_player
{
	double			x;
	double			y;
	int				moveX;
	int				moveY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	int				rotate;
	int				is_in_move;
}					t_player;

typedef struct cub3d
{
	char			**data;
	t_player		player;
	t_map			map;
	t_radius		radius;
	t_win			win;
	int				**textures;
	int				**modify_textures;
	t_textures		datatex;
}					t_cub3d;

// parsing
t_status 			parsing(char **av, t_cub3d *cub3d);
t_status			is_ext(char *file, bool cub);
t_status			init_data(char *file, t_cub3d *cub3d);
t_status			init_datatex(t_cub3d *cub3d, char **data);
t_status			init_map(t_cub3d *cub3d);
t_status			parse_map(t_cub3d *cub3d);
t_status			init_player(char **map, t_cub3d *cub3d);
t_status			init_color(t_cub3d *cub3d);

	// utils
bool				is_tex(char *path);
	// debug
void 				print_cub3d(t_cub3d *cub3d);

// handle error
void				error(t_status status, t_cub3d *cub3d, void (*callback)(t_cub3d *));
void				destroy_win(t_cub3d *cub3d);

#endif