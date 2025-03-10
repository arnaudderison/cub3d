/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:05:48 by aderison          #+#    #+#             */
/*   Updated: 2025/03/10 18:02:22 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define TEX_SIZE 64

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define MOVESPEED 0.0300

typedef enum s_status
{
	SUCCESS = 1,
	FAILED = 0,
	MALLOC = -1,
	PTR_NULL = -2,
	UNKNOWN = -3,
}				t_status;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int pixel_bits; // taille d'un pixel
	int size_line;  // taille d'une ligne de pixel
	int endian;     // permet de savoir comment lire les pixels
}				t_img;

typedef struct s_textures
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	int			x;
	int			y;
	double		step;
	double		pos;
	int			index;
}				t_textures;

typedef struct s_win
{
	void		*mlx;
	void		*window;
}				t_win;

typedef struct s_map
{
	int			width;
	int			height;
	char		**matrice;
}				t_map;

typedef struct s_radius
{
	double		cameraX;
	double		dirX;
	double		dirY;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	double		sidedistX;
	double		sidedistY;
	double		deltadistX;
	double		deltadistY;
	double		wallX;
	double		wall_dist;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_radius;

typedef struct s_player
{
	double		x;
	double		y;
	int			moveX;
	int			moveY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			is_in_move;
}				t_player;

typedef struct cub3d
{
	t_player	player;
	t_map		map;
	t_radius	radius;
	t_win		win;
	int			**textures;
	int			**modify_textures;
	t_textures	datatex;
}				t_cub3d;

// handle error
void			error(t_status status, t_cub3d *cub3d,
					void (*callback)(t_cub3d *));
void			destroy_win(t_cub3d *cub3d);

// init
void			init_mlx(t_cub3d *cub3d);
void			create_img_from_xpm(t_cub3d *cub3d, t_img *img, char *path);
void			init_textures(t_cub3d *cub3d);
void			init_modify_textures(t_cub3d *cub3d);
void			init_img(t_cub3d *cub3d, t_img *image, int width, int height);

// graphics engine
int				graphics_engine(t_cub3d *cub3d);
void			update_modify_textures(t_cub3d *cub3d, t_textures *tex,
					t_radius *rad, int x);
t_status		raycasting(t_player *player, t_cub3d *cub3d);
void			set_image_pixel(t_img *image, int x, int y, int color);
int render(t_cub3d *cub3d);

//moves
int	validate_move(t_cub3d *cub3d, double new_x, double new_y);
int	move_player(t_cub3d *cub3d);
void key_listener(t_cub3d *cub3d);
int	validate_move(t_cub3d *cub3d, double new_x, double new_y);

#endif