/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:28:49 by melperri          #+#    #+#             */
/*   Updated: 2021/04/23 09:30:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int			check_fd(t_all *all, int fd)
{
	if (fd == -1)
		return (check_error(all, PARS_ERROR));
	if (read(fd, 0, 0))
	{
		close(fd);
		return (check_error(all, FOLDER_ERROR));
	}
	return (0);
}

static void	check_error_part_two(int error)
{
	if (error == MAP_ERROR)
		write(1, STR_MAP_ERROR, ft_strlen(STR_MAP_ERROR));
	else if (error == FOLDER_ERROR)
		write(1, STR_FOLDER_ERROR, ft_strlen(STR_FOLDER_ERROR));
	else if (error == MLX_ERROR)
		write(1, STR_MLX_ERROR, ft_strlen(STR_MLX_ERROR));
	else if (error == PARS_ERROR)
		write(1, STR_PARS_ERROR, ft_strlen(STR_PARS_ERROR));
	else if (error == MALLOC_ERROR)
		write(1, STR_MALLOC_ERROR, ft_strlen(STR_MALLOC_ERROR));
	else if (error == ARG_ERROR)
		write(1, STR_ARG_ERROR, ft_strlen(STR_ARG_ERROR));
	else if (error == FD_ERROR)
		write(1, STR_FD_ERROR, ft_strlen(STR_FD_ERROR));
}

static void	check_error_part_one(int error)
{
	if (error == NO_PLAYER_ERROR)
		write(1, STR_NO_PLAYER_ERROR, ft_strlen(STR_NO_PLAYER_ERROR));
	else if (error == EMPTY_LINE_ERROR)
		write(1, STR_EMPTY_LINE_ERROR, ft_strlen(STR_EMPTY_LINE_ERROR));
	else if (error == PATH_ERROR)
		write(1, STR_PATH_ERROR, ft_strlen(STR_PATH_ERROR));
	else if (error == SAVE_ERROR)
		write(1, STR_SAVE_ERROR, ft_strlen(STR_SAVE_ERROR));
	else if (error == NAME_ERROR)
		write(1, STR_NAME_ERROR, ft_strlen(STR_NAME_ERROR));
	else if (error == RES_ERROR)
		write(1, STR_RES_ERROR, ft_strlen(STR_RES_ERROR));
}

int			check_error(t_all *all, int error)
{
	ft_free_all(all);
	if (error >= -13 && error <= -8)
		check_error_part_one(error);
	else if (error >= -7 && error <= -1)
		check_error_part_two(error);
	return (-1);
}
