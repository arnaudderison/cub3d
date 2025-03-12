/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:46:29 by aderison          #+#    #+#             */
/*   Updated: 2025/03/12 12:47:08 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

typedef struct s_textures
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				x;
	int				y;
	double			step;
	double			pos;
	int				index;
	int				*floor;
	int				*ceiling;
	unsigned int	hex_ceiling;
	unsigned int	hex_floor;
}					t_textures;

#endif