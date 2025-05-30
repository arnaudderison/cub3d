/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:39:59 by aderison          #+#    #+#             */
/*   Updated: 2025/03/26 18:09:17 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(t_status status, t_errinfo *info, t_cub3d *cub3d,
int (*callback)(t_cub3d *))
{
	if (status == MALLOC)
		ft_printf_fd(2,
			YELLOW "[INFO]: " RESET "Exit with malloc error code\n");
	if (status == PTR_NULL)
		ft_printf_fd(2,
			YELLOW "[INFO]: " RESET "Exit with ptr null error code\n");
	if (status == UNKNOWN)
		ft_printf_fd(2,
			YELLOW "[INFO]: " RESET "Exit with UNKNOWN error code\n");
	if (info)
	{
		ft_printf("L'erreur est probablement survenue dans [%s] ligne [%d]", \
		info->file, info->line);
		set_errinfo(info, 0, NULL);
	}
	if (callback && cub3d)
		callback(cub3d);
	exit(EXIT_SUCCESS);
}
