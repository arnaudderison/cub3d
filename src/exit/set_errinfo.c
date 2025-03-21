/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_errinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:54:44 by aderison          #+#    #+#             */
/*   Updated: 2025/03/20 20:36:06 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_errinfo(t_errinfo *errinfo, int line, char *file)
{
	errinfo->file = file;
	errinfo->line = line;
}
