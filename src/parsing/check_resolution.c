/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:23 by melperri          #+#    #+#             */
/*   Updated: 2021/05/03 21:24:28 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_resolution_path_part_two(char *line, t_all *all)
{
	if (ft_isdigit(*line))
		all->ry = ft_atoi(line);
	else
		return (check_error(all, RES_ERROR));
	while (ft_isdigit(*line))
		line++;
	if (*line == ' ' || *line == '\0')
		while (*line == ' ')
			line++;
	if (*line != '\0')
		return (check_error(all, RES_ERROR));
	return (0);
}

int			check_resolution_path(char *line, t_all *all)
{
	line++;
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line))
		all->rx = ft_atoi(line);
	else
		return (check_error(all, RES_ERROR));
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	if (check_resolution_path_part_two(line, all) < 0)
		return (-1);
	return (0);
}

int			check_resolution_value(t_all *all)
{
	if (all->rx == 0 || all->ry == 0)
		return (check_error(all, RES_ERROR));
	if (all->rx > INT_MAX || all->rx < 0)
		all->rx = INT_MAX;
	if (all->ry > INT_MAX || all->ry < 0)
		all->ry = INT_MAX;
	return (0);
}

void		rectify_resolution_value(t_all *all)
{
	int	resx;
	int	resy;

	mlx_get_screen_size(all->mlx_ptr, &resx, &resy);
	if (all->rx >= resx)
		all->rx = resx;
	if (all->ry >= resy)
		all->ry = resy;
}
