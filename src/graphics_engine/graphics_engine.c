/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_engine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:15:26 by arnaud            #+#    #+#             */
/*   Updated: 2025/03/16 01:07:50 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// unsigned int color = cub3d->datatex.hex_ceiling;
// 		int random = (x * 17 + y * 13) % 1000; // Seed basée sur la position
		
// 		// Étoiles avec variations simples
// 		if (random < 8) { // 8 étoiles par 1000 pixels (~0.8%)
// 			int intensity = 200 + (random % 55); // Variation de luminosité
// 			color = (intensity << 16) | (intensity << 8) | intensity;
// 		}
		
// 		set_image_pixel(image, x, y, color);

// static void	set_image_pixels(t_cub3d *cub3d, t_img *image, int x, int y)
// {
// 	if (cub3d->modify_textures[y][x] > 0)
// 		set_image_pixel(image, x, y, cub3d->modify_textures[y][x]);
// 	else if (y < WIN_HEIGHT / 2)
// 	{
// 		if(BONUS)
// 		{
// 			if(x % 3 == 0)
// 			{
// 				unsigned int hash = (x * 12345 + y * 67890) ^ ((x << 16) | y);
// 			int star_chance = hash % 1000;
// 			int star_size = (hash >> 8) % 2; // Taille aléatoire 0-2

// 			if (star_chance < 2) // Densité globale ~0.5%
// 			{
// 				// Dessine une étoile carrée de taille variable
// 				for(int dx = -star_size; dx <= star_size; dx++) {
// 					for(int dy = -star_size; dy <= star_size; dy++) {
// 						if(x + dx >= 0 && x + dx < WIN_WIDTH && y + dy >= 0) {
// 							int intensity = 200 - (abs(dx) + abs(dy)) * 30;
// 							set_image_pixel(image, x + dx, y + dy, 
// 								(intensity << 16) | (intensity << 8) | intensity);
// 						}
// 					}
// 				}
// 			}else
// 				set_image_pixel(image, x, y, 0x171220);
// 			}
// 		}
// 		else if(x % 3 == 0)
// 			set_image_pixel(image, x, y, cub3d->datatex.hex_ceiling);
// 	}
// 	else if (y < WIN_HEIGHT - 1 && x % 3 == 0)
// 		set_image_pixel(image, x, y, cub3d->datatex.hex_floor);
// }

// Ajoute cette variable globale quelque part (dans t_cub3d par exemple)
// static int time_counter = 0;

// Ajoute dans t_cub3d
int time_counter; // Initialiser à 0

// Fonction de bruit procédural
static unsigned int random2D(int x, int y) {
    unsigned int h = (x * 92837111) ^ (y * 689287499);
    h = (h >> 13) ^ h;
    return (h * (h * h * 60493 + 19990303) + 1376312589);
}

static void	set_image_pixels(t_cub3d *cub3d, t_img *image, int x, int y) {
    if (cub3d->modify_textures[y][x] > 0) {
        set_image_pixel(image, x, y, cub3d->modify_textures[y][x]);
        return;
    }

    if (y < WIN_HEIGHT / 2 && BONUS) {
        // 1.5% de chance d'avoir une étoile à cette position
        if (random2D(x, y) % 666 < 4) {
            // Paramètres de scintillement
            float speed = 0.1f;
            float phase = cub3d->time_counter * speed + random2D(x, y) % 1000;
            
            // Scintillement intense avec effet carré
            float twinkle = sinf(phase) * sinf(phase * 2.7f); // Combinaison de fréquences
            int intensity = 100 + 155 * fabsf(twinkle); // De 100 à 255
            
            // Dessine l'étoile avec un point brillant
            set_image_pixel(image, x, y, intensity * 0x010101);
            
            // Ajoute un effet de halo aléatoire
            if ((random2D(x, y) % 100) < 30) {
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if ((dx || dy) && x + dx >= 0 && x + dx < WIN_WIDTH && y + dy >= 0) {
                            int halo_intensity = intensity - 50 - abs(dx * dy * 30);
                            if (halo_intensity > 50) {
                                set_image_pixel(image, x + dx, y + dy, 
                                    halo_intensity * 0x010101);
                            }
                        }
                    }
                }
            }
        } else {
            set_image_pixel(image, x, y, 0x121212);
        }
    } else if (y < WIN_HEIGHT - 1 && x % 3 == 0) {
        set_image_pixel(image, x, y, cub3d->datatex.hex_floor);
    }
}

static void	render_frame(t_cub3d *cub3d)
{
	
	int		x;
	int		y;

	
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			set_image_pixels(cub3d, &cub3d->frame, x, y);
		y++;
	}
	mlx_put_image_to_window(cub3d->win.mlx, cub3d->win.window, cub3d->frame.img, 0, 0);
}
// gestion du raycasting et du rendu
int	graphics_engine(t_cub3d *cub3d)
{
	t_img	image;

	image.img = NULL;
	cub3d->frame = image;
	init_img(cub3d, &cub3d->frame, WIN_WIDTH, WIN_HEIGHT);
	init_modify_textures(cub3d);
	raycasting(&cub3d->player, cub3d);
	render_frame(cub3d);
	if(BONUS)
	{
		
		maps_engine(cub3d);
	}
	mlx_destroy_image(cub3d->win.mlx, cub3d->frame.img);
	return (0);
}

int	render(t_cub3d *cub3d)
{
	cub3d->player.is_in_move += move_player(cub3d);
	if (cub3d->player.is_in_move == 0)
		return (0);
	graphics_engine(cub3d);
	return (0);
}
