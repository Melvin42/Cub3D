/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:30 by melperri          #+#    #+#             */
/*   Updated: 2021/04/22 20:00:37 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	check_rgb(t_all *all)
{
	if (check_color_value(all, all->floor.red) < 0)
		return (-1);
	if (check_color_value(all, all->floor.green) < 0)
		return (-1);
	if (check_color_value(all, all->floor.blue) < 0)
		return (-1);
	if (check_color_value(all, all->ceiling.red) < 0)
		return (-1);
	if (check_color_value(all, all->ceiling.green) < 0)
		return (-1);
	if (check_color_value(all, all->ceiling.blue) < 0)
		return (-1);
	return (0);
}

int	check_color_value(t_all *all, int color)
{
	if (color < 0 || color > 255)
		return (check_error(all, PARS_ERROR));
	return (0);
}
