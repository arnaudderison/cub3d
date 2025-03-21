/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_datatex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:29:40 by plachard          #+#    #+#             */
/*   Updated: 2025/03/21 18:23:27 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* attention si un fdp met un buffer bcp trop long, check si premiere fois
	qu'on lit tout le fichier gnl renvoi une erreur et la gerer */
/* attention check strdup calloc pas malloc ou termine la chaine par \0
	et si la chaine n'existe pas*/
/* attention retour d'erreur d'atoi,
	recoder pour que ne soit accepte que les digits */

/* Converts an RGB string to an array of integers. */
static int	*to_rgb(char *rgb)
{
	char	**str_rgb;
	int		*int_rgb;
	int		i;

	int_rgb = malloc(sizeof(int) * 3);
	str_rgb = ft_split(rgb, ',');
	if (!str_rgb)
		return (NULL);
	i = 0;
	while (str_rgb[i] && i < 3)
	{
		if (ft_strlen(str_rgb[i]) < 1)
			return (ft_free_matrice(1, &str_rgb), ft_free(1, &int_rgb), NULL);
		int_rgb[i] = ft_atoi(str_rgb[i]);
		if (int_rgb[i] < 0 || int_rgb[i] > 255)
			return (ft_free_matrice(1, &str_rgb), ft_free(1, &int_rgb), NULL);
		++i;
	}
	if (str_rgb[i] || i < 3)
		return (ft_free_matrice(1, &str_rgb), ft_free(1, &int_rgb), NULL);
	return (ft_free_matrice(1, &str_rgb), int_rgb);
}

/* Assigns color to floor or ceiling. */
static t_status	assign_color(t_cub3d *cub3d, char *path, char wall)
{
	if (!path)
		return (FAILED);
	if (wall == 'F')
	{
		cub3d->datatex.floor = to_rgb(path);
		if (!cub3d->datatex.floor)
		{
			printf("F failed\n");
			return (FAILED);
		}
	}
	if (wall == 'C')
	{
		cub3d->datatex.ceiling = to_rgb(path);
		if (!cub3d->datatex.ceiling)
		{
			printf("C failed\n");
			return (FAILED);
		}
	}
	return (SUCCESS);
}

static char	*assign_tex_path(char *datatex, char *path)
{
	if (datatex)
		return (NULL);
	path = ft_strtrim(path, " \t");
	datatex = ft_strdup(path);
	return (ft_free(1, &path), datatex);
}

/* Assigns texture path based on wall type. */
static t_status	assign_tex_wall(t_cub3d *cub3d, char *path, char wall)
{
	if (wall == 'N')
	{
		cub3d->datatex.north = assign_tex_path(cub3d->datatex.north, path);
		if (!cub3d->datatex.north)
			return (FAILED);
	}
	if (wall == 'S')
	{
		cub3d->datatex.south = assign_tex_path(cub3d->datatex.south, path);
		if (!cub3d->datatex.south)
			return (FAILED);
	}
	if (wall == 'E')
	{
		cub3d->datatex.east = assign_tex_path(cub3d->datatex.east, path);
		if (!cub3d->datatex.east)
			return (FAILED);
	}
	if (wall == 'W')
	{
		cub3d->datatex.west = assign_tex_path(cub3d->datatex.west, path);
		if (!cub3d->datatex.west)
			return (FAILED);
	}
	return (SUCCESS);
}

/* Initializes colors and textures from the data array. */
t_status	init_datatex(t_cub3d *cub3d, char **data)
{
	int	i;

	i = 0;
	while (data[i] && i < 6)
	{
		printf("data[%d] = %s\n", i, data[i]);
		if (is_tex(data[i]))
		{
			if (!data[i][3])
				return (FAILED);
			if (assign_tex_wall(cub3d, data[i] + 3, data[i][0]) != SUCCESS)
				return (FAILED);
		}
		if (data[i][0] == 'C' || data[i][0] == 'F')
		{
			if (!data[i][2])
				return (FAILED);
			if (assign_color(cub3d, data[i] + 2, data[i][0]) != SUCCESS)
				return (FAILED);
		}
		++i;
	}
	return (SUCCESS);
}
