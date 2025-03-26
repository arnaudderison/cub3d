/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:15:34 by plachard          #+#    #+#             */
/*   Updated: 2025/03/26 17:13:39 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_status	parsing(char **av, t_cub3d *cub3d)
{
	int	status;

	status = is_ext(av[1], 1);
	if (status != SUCCESS)
		return (status);
	status = init_data(av[1], cub3d);
	if (status != SUCCESS)
		return (status);
	status = init_datatex(cub3d, cub3d->data);
	if (status != SUCCESS)
		return (status);
	status = init_map(cub3d);
	if (status != SUCCESS)
		return (status);
	status = parse_map(cub3d);
	if (status != SUCCESS)
		return (status);
	status = init_color(cub3d);
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}
