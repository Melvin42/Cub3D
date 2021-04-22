/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:27 by melperri          #+#    #+#             */
/*   Updated: 2021/04/22 20:23:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_north_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != 'O' || all->north)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->north = ft_strdup((const char *)line);
	if (all->north == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->north;
	all->north = ft_strtrim((const char *)all->north, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->north) < 0)
		return (-1);
	fd = open(all->north, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	close(fd);
	return (0);
}

int	check_south_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != 'O' || all->south)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->south = ft_strdup((const char *)line);
	if (all->south == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->south;
	all->south = ft_strtrim((const char *)all->south, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->south) < 0)
		return (-1);
	fd = open(all->south, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_west_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != 'E' || all->west)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->west = ft_strdup((const char *)line);
	if (all->west == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->west;
	all->west = ft_strtrim((const char *)all->west, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->west) < 0)
		return (-1);
	fd = open(all->west, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_east_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != 'A' || all->east)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->east = ft_strdup((const char *)line);
	if (all->east == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->east;
	all->east = ft_strtrim((const char *)all->east, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->east) < 0)
		return (-1);
	fd = open(all->east, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != ' ' || all->path_sprite)
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite = ft_strdup((const char *)line);
	if (all->path_sprite == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite;
	all->path_sprite = ft_strtrim((const char *)all->path_sprite, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite) < 0)
		return (-1);
	fd = open(all->path_sprite, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}
