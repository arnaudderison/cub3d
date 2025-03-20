/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:37:07 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 20:38:10 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player
{
	double	x;
	double	y;
	int		movex;
	int		movey;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	int		rotate;
	int		is_in_move;
}			t_player;

#endif