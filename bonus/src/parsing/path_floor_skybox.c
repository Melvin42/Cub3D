/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_floor_skybox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:37:19 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 17:37:49 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	check_floor_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != ' ' || all->floor)
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->floor = ft_strdup((const char *)line);
	if (all->floor == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->floor;
	all->floor = ft_strtrim((const char *)all->floor, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->floor) < 0)
		return (-1);
	fd = open(all->floor, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_skybox_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != ' ' || all->skybox)
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->skybox = ft_strdup((const char *)line);
	if (all->skybox == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->skybox;
	all->skybox = ft_strtrim((const char *)all->skybox, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->skybox) < 0)
		return (-1);
	fd = open(all->skybox, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}
