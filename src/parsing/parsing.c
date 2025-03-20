/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:15:34 by plachard          #+#    #+#             */
/*   Updated: 2025/03/20 22:10:42 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if the given path is not a directory. */
static bool	is_not_dir(char *file)
{
	int	fd;

	if (!file)
	{
		printf("no file\n");
		return (false);
	}
	fd = open(file, __O_DIRECTORY);
	if (fd < 0)
		return (true);
	close(fd);
	return (false);
}

/* Checks if the file has a ".cub" extension. */
static bool	is_cub_ext(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (file[len - 4] != '.' || file[len - 3] != 'c' || file[len - 2] != 'u'
		|| file[len - 1] != 'b')
		return (false);
	return (true);
}

/* Checks if the file has a ".xpm" extension. */
static bool	is_xpm_ext(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		return (false);
	if (file[len - 4] != '.' || file[len - 3] != 'x' || file[len - 2] != 'p'
		|| file[len - 1] != 'm')
		return (false);
	return (true);
}

/* Validates if a file is readable and has the correct extension. */
t_status	is_ext(char *file, bool cub)
{
	int	fd;

	if (!is_not_dir(file))
	{
		printf("is dir\n");
		return (FAILED);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("no fd\n");
		return (false);
	}
	close(fd);
	if (cub && !is_cub_ext(file))
		return (FAILED);
	if (!cub && !is_xpm_ext(file))
	{
		printf("!xpm\n");
		return (FAILED);
	}
	return (SUCCESS);
}

t_status	parsing(char **av, t_cub3d *cub3d)
{
	int	status;

	status = is_ext(av[1], 1);
	if (status != SUCCESS)
		return (status);
	status = init_data(av[1], cub3d);
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
