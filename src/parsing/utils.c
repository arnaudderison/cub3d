/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:26:48 by plachard          #+#    #+#             */
/*   Updated: 2025/03/20 23:27:58 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if the given path is not a directory. */
static bool	is_not_dir(char *file)
{
	int	fd;

	if (!file)
		return (false);
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
		return (FAILED);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	if (cub && !is_cub_ext(file))
		return (FAILED);
	if (!cub && !is_xpm_ext(file))
		return (FAILED);
	return (SUCCESS);
}

/* Checks if the string is a valid texture identifier (NO, SO, EA, WE). */
bool	is_tex(char *path)
{
	int		count;
	char	first;
	char	second;

	if (!path || !path[0] || !path[1])
		return (false);
	count = 0;
	while (path[count] != ' ')
		if (count++ > 1)
			return (false);
	first = path[0];
	second = path[1];
	if (first == 'N' && second == 'O')
		return (true);
	if (first == 'S' && second == 'O')
		return (true);
	if (first == 'E' && second == 'A')
		return (true);
	if (first == 'W' && second == 'E')
		return (true);
	return (false);
}
