/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:15:34 by plachard          #+#    #+#             */
/*   Updated: 2025/03/21 18:18:15 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_status	parsing(char **av, t_cub3d *cub3d)
{
	int	status;

	status = is_ext(av[1], 1);
	if (status != SUCCESS)
	{
		printf("is ext failed \n");
		return (status);
	}
	status = init_data(av[1], cub3d);
	if (status != SUCCESS)
	{
		printf("init data failed\n");
		return (status);
	}
	status = init_datatex(cub3d, cub3d->data);
	if (status != SUCCESS)
	{
		printf("init datatex failed\n");
		return (status);
	}
	status = init_map(cub3d);
	if (status != SUCCESS)
	{
		printf("init map failed\n");
		return (status);
	}
	status = parse_map(cub3d);
	if (status != SUCCESS)
	{
		printf("parse mapfailed\n");
		return (status);
	}
	status = init_color(cub3d);
	if (status != SUCCESS)
	{
		printf("init color failed\n");
		return (status);
	}
	return (SUCCESS);
}
