/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ceiling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:54:16 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 12:19:21 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_ceiling_color_part_three(char *line, t_all *all)
{
	if (!ft_isdigit(*line))
		return (check_error(all, PARS_ERROR));
	else
	{
		all->ceiling.blue = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	if (*line == ' ' || *line == '\0')
		while (*line == ' ')
			line++;
	else
		return (check_error(all, PARS_ERROR));
	if (*line != '\0')
		return (check_error(all, PARS_ERROR));
	return (0);
}

static int	check_ceiling_color_part_two(char *line, t_all *all)
{
	if (!ft_isdigit(*line))
		return (check_error(all, PARS_ERROR));
	else
	{
		all->ceiling.green = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	while (*line == ' ')
		line++;
	if (*line == ',')
		line++;
	else
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	if (check_ceiling_color_part_three(line, all) < 0)
		return (-1);
	return (0);
}

int	check_ceiling_color(char *line, t_all *all)
{
	line++;
	while (*line == ' ')
		line++;
	if (!ft_isdigit(*line))
		return (check_error(all, PARS_ERROR));
	else
	{
		all->ceiling.red = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	while (*line == ' ')
		line++;
	if (*line == ',')
		line++;
	else
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	if (check_ceiling_color_part_two(line, all) < 0)
		return (-1);
	return (0);
}
