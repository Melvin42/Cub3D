/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_format_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:03:27 by melperri          #+#    #+#             */
/*   Updated: 2021/05/25 12:25:54 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	check_save_name(t_all *all, char *arg)
{
	size_t	i;

	i = ft_strlen((const char *)arg);
	if (i != 6)
		return (check_error(all, ARG_ERROR));
	if (arg[--i] != 'e')
		return (check_error(all, ARG_ERROR));
	if (arg[--i] != 'v')
		return (check_error(all, ARG_ERROR));
	if (arg[--i] != 'a')
		return (check_error(all, ARG_ERROR));
	if (arg[--i] != 's')
		return (check_error(all, ARG_ERROR));
	if (arg[--i] != '-')
		return (check_error(all, ARG_ERROR));
	if (arg[--i] != '-')
		return (check_error(all, ARG_ERROR));
	return (0);
}

int	check_map_name(t_all *all, char *arg)
{
	size_t	i;

	i = ft_strlen((const char *)arg);
	if (i < 4)
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != 'b')
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != 'u')
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != 'c')
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != '.')
		return (check_error(all, NAME_ERROR));
	return (0);
}

int	check_xpm_path(t_all *all, char *path)
{
	size_t	i;

	i = ft_strlen((const char *)path);
	if (i < 4)
		return (check_error(all, PATH_ERROR));
	if (path[--i] != 'm')
		return (check_error(all, PATH_ERROR));
	if (path[--i] != 'p')
		return (check_error(all, PATH_ERROR));
	if (path[--i] != 'x')
		return (check_error(all, PATH_ERROR));
	if (path[--i] != '.')
		return (check_error(all, PATH_ERROR));
	return (0);
}
