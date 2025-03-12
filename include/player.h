/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:37:07 by aderison          #+#    #+#             */
/*   Updated: 2025/03/12 12:37:53 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

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

#endif