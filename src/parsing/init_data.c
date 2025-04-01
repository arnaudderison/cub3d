/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plachard <plachard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:17:28 by plachard          #+#    #+#             */
/*   Updated: 2025/04/01 15:14:50 by plachard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	dup_no_empty_line(char *buffer, t_cub3d *cub3d, int i)
{
	char	*cpy;

	if (i < 6)
	{
		cpy = ft_strtrim(buffer, " \t\n");
		if (ft_strlen(cpy) == 0)
		{
			ft_free(2, &cpy, &buffer);
			return (i);
		}
	}
	else
		cpy = ft_strdup(buffer);
	cub3d->data[i] = ft_strdup(cpy);
	ft_free(2, &cpy, &buffer);
	if (!cub3d->data[i])
		return (-1);
	return (++i);
}

/* attention si un fdp met un buffer bcp trop long,
	check si premiere fois qu'on lit tout le fichier
	gnl renvoi une erreur et la gerer */
/* attention check strdup calloc pas malloc ou termine
la chaine par \0 et si la chaine n'existe pas*/
/* attention retour d'erreur d'atoi,
	recoder pour que ne soit accepte que les digits */
/* attention si \t ou ' ' puis nom du fichier */

static t_status	data_dup(char *file, t_cub3d *cub3d)
{
	int		fd;
	int		i;
	int		tmp;
	char	*buffer;

	fd = open(file, O_RDONLY);
	i = 0;
	tmp = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		tmp = dup_no_empty_line(buffer, cub3d, i);
		if (tmp < i)
			return (FAILED);
		i = tmp;
		buffer = get_next_line(fd);
	}
	ft_free(1, &buffer);
	close(fd);
	return (SUCCESS);
}

static int	count_line(char *line, int fd)
{
	char	*tmp;
	int		n;

	n = 0;
	while (line)
	{
		if (n < 6)
		{
			tmp = ft_strtrim(line, " \n\t");
			if (ft_strlen(tmp) > 0)
				++n;
			ft_free(1, &tmp);
		}
		else
			++n;
		ft_free(1, &line);
		line = get_next_line(fd);
	}
	ft_free(1, &line);
	return (n);
}

/* peut etre juste renvoyer un status */
static t_status	data_alloc(char *file, t_cub3d *cub3d)
{
	int		fd;
	char	*line;
	int		n;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FAILED);
	line = get_next_line(fd);
	n = count_line(line, fd);
	if (!n)
		return (FAILED);
	cub3d->map.height = n - 6;
	close(fd);
	cub3d->data = ft_calloc(n + 1, sizeof(char *));
	if (!cub3d->data)
		return (FAILED);
	return (SUCCESS);
}

t_status	init_data(char *file, t_cub3d *cub3d)
{
	int	status;

	if (!file)
		return (FAILED);
	status = data_alloc(file, cub3d);
	if (status != SUCCESS)
		return (status);
	status = data_dup(file, cub3d);
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}
