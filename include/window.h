/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:48:37 by aderison          #+#    #+#             */
/*   Updated: 2025/03/12 12:49:12 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_img
{
	void			*img;
	int				*addr;
	int pixel_bits; // taille d'un pixel
	int size_line;  // taille d'une ligne de pixel
	int endian;     // permet de savoir comment lire les pixels
}					t_img;

typedef struct s_win
{
	void			*mlx;
	void			*window;
}					t_win;

#endif