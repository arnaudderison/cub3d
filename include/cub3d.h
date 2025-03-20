/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:05:48 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 16:27:28 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "colors.h"
# include "libft.h"
# include "minimap.h"
# include "mlx.h"
# include "player.h"
# include "radius.h"
# include "texture.h"
# include "window.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define TEX_SIZE 64

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define MOVESPEED 0.2
# define ROTSPEED 0.02
# define DIST_EDGE_MOUSE_WRAP 50

# define MMAP_COLOR_PLAYER 0x27AE60
# define MMAP_COLOR_WALL 0x2C3E50
# define MMAP_COLOR_FLOOR 0xE6E6E6
# define MMAP_COLOR_SPACE 0x7F8C8D

# ifndef BONUS
#  define BONUS 1
# endif

typedef enum s_status
{
	SUCCESS = 1,
	FAILED = 0,
	MALLOC = -1,
	PTR_NULL = -2,
	UNKNOWN = -3,
}				t_status;

typedef struct s_map
{
	int			width;
	int			height;
	char		**matrice;
}				t_map;

typedef struct cub3d
{
	t_player	player;
	t_map		map;
	t_radius	radius;
	t_win		win;
	int			**textures;
	int			**modify_textures;
	t_minimap	minimap;
	t_textures	datatex;
	int			time_counter;
	t_img		frame;
}				t_cub3d;

// handle error
void			error(t_status status, t_cub3d *cub3d,
					void (*callback)(t_cub3d *));
void			destroy_win(t_cub3d *cub3d);
void			freeall(t_cub3d *cub3d);

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
int				render(t_cub3d *cub3d);
void			draw_star(t_cub3d *cub3d, t_img *image, int x, int y);
unsigned int	random2d(int x, int y);

// door
void handle_door(t_cub3d *cub3d, t_radius *rad);
bool is_close_door(t_cub3d *cub3d, int x, int y);

// moves
int				move_player(t_cub3d *cub3d);
void			key_listener(t_cub3d *cub3d);
int				validate_move(t_cub3d *cub3d, double new_x, double new_y);
int				rotate_player(t_cub3d *cub3d, double rotdir);

// minimap
void			init_minimap(t_minimap *minimap, t_cub3d *cub3d);
void			render_minimap(t_cub3d *cub3d, t_minimap *m);
int				maps_engine(t_cub3d *cub3d);

#endif