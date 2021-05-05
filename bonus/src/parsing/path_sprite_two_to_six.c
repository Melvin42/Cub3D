/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_sprite_two_to_six.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:52:34 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 17:52:35 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	check_sprite_two_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '2' || all->path_two)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_two = ft_strdup((const char *)line);
	if (all->path_two == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_two;
	all->path_two = ft_strtrim((const char *)all->path_two, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_two) < 0)
		return (-1);
	fd = open(all->path_two, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_three_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '3' || all->path_three)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_three = ft_strdup((const char *)line);
	if (all->path_three == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_three;
	all->path_three = ft_strtrim((const char *)all->path_three, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_three) < 0)
		return (-1);
	fd = open(all->path_three, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_four_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '4' || all->path_four)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_four = ft_strdup((const char *)line);
	if (all->path_four == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_four;
	all->path_four = ft_strtrim((const char *)all->path_four, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_four) < 0)
		return (-1);
	fd = open(all->path_four, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_five_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '5' || all->path_five)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_five = ft_strdup((const char *)line);
	if (all->path_five == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_five;
	all->path_five = ft_strtrim((const char *)all->path_five, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_five) < 0)
		return (-1);
	fd = open(all->path_five, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_six_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '6' || all->path_six)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_six = ft_strdup((const char *)line);
	if (all->path_six == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_six;
	all->path_six = ft_strtrim((const char *)all->path_six, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_six) < 0)
		return (-1);
	fd = open(all->path_six, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}
