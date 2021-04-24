/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:27 by melperri          #+#    #+#             */
/*   Updated: 2021/04/24 12:22:50 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

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

int	check_sprite_two_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '2' || all->path_sprite_two)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_two = ft_strdup((const char *)line);
	if (all->path_sprite_two == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_two;
	all->path_sprite_two = ft_strtrim((const char *)all->path_sprite_two, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_two) < 0)
		return (-1);
	fd = open(all->path_sprite_two, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}
int	check_sprite_three_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '3' || all->path_sprite_three)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_three = ft_strdup((const char *)line);
	if (all->path_sprite_three == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_three;
	all->path_sprite_three = ft_strtrim((const char *)all->path_sprite_three, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_three) < 0)
		return (-1);
	fd = open(all->path_sprite_three, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_four_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '4' || all->path_sprite_four)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_four = ft_strdup((const char *)line);
	if (all->path_sprite_four == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_four;
	all->path_sprite_four = ft_strtrim((const char *)all->path_sprite_four, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_four) < 0)
		return (-1);
	fd = open(all->path_sprite_four, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_five_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '5' || all->path_sprite_five)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_five = ft_strdup((const char *)line);
	if (all->path_sprite_five == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_five;
	all->path_sprite_five = ft_strtrim((const char *)all->path_sprite_five, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_five) < 0)
		return (-1);
	fd = open(all->path_sprite_five, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_six_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '6' || all->path_sprite_six)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_six = ft_strdup((const char *)line);
	if (all->path_sprite_six == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_six;
	all->path_sprite_six = ft_strtrim((const char *)all->path_sprite_six, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_six) < 0)
		return (-1);
	fd = open(all->path_sprite_six, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_seven_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '7' || all->path_sprite_seven)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_seven = ft_strdup((const char *)line);
	if (all->path_sprite_seven == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_seven;
	all->path_sprite_seven = ft_strtrim((const char *)all->path_sprite_seven, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_seven) < 0)
		return (-1);
	fd = open(all->path_sprite_seven, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_eight_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '8' || all->path_sprite_eight)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_eight = ft_strdup((const char *)line);
	if (all->path_sprite_eight == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_eight;
	all->path_sprite_eight = ft_strtrim((const char *)all->path_sprite_eight, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_eight) < 0)
		return (-1);
	fd = open(all->path_sprite_eight, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}

int	check_sprite_nine_path(char *line, t_all *all)
{
	int		fd;
	char	*to_free;

	line++;
	if (*line != '9' || all->path_sprite_nine)
		return (check_error(all, PARS_ERROR));
	line++;
	if (*line != ' ')
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite_nine = ft_strdup((const char *)line);
	if (all->path_sprite_nine == NULL)
		return (check_error(all, PARS_ERROR));
	to_free = all->path_sprite_nine;
	all->path_sprite_nine = ft_strtrim((const char *)all->path_sprite_nine, " ");
	free(to_free);
	to_free = NULL;
	if (check_xpm_path(all, all->path_sprite_nine) < 0)
		return (-1);
	fd = open(all->path_sprite_nine, O_RDONLY);
	if (check_fd(all, fd) < 0)
		return (-1);
	return (0);
}
