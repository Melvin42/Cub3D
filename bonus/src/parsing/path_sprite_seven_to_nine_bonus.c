/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_sprite_seven_to_nine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:55:10 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 17:55:12 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	check_sprite_seven_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '7' || all->path_seven)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_seven = ft_strdup((const char *)line);
	if (all->path_seven == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_seven;
	all->path_seven = ft_strtrim((const char *)all->path_seven, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_seven) < 0)
		return (-1);
	fd = open(all->path_seven, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_eight_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '8' || all->path_eight)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_eight = ft_strdup((const char *)line);
	if (all->path_eight == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_eight;
	all->path_eight = ft_strtrim((const char *)all->path_eight, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_eight) < 0)
		return (-1);
	fd = open(all->path_eight, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_nine_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '9' || all->path_nine)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_nine = ft_strdup((const char *)line);
	if (all->path_nine == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_nine;
	all->path_nine = ft_strtrim((const char *)all->path_nine, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_nine) < 0)
		return (-1);
	fd = open(all->path_nine, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}
