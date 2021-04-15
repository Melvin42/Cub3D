#include "cub3d.h"

int	check_north_path(char *line, t_all *all)
{
	line++;
	if (*line != 'O' || all->north)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->north = ft_strdup(line);
	return (0);
}

int	check_south_path(char *line, t_all *all)
{
	line++;
	if (*line != 'O' || all->south)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->south = ft_strdup(line);
	return (0);
}

int	check_west_path(char *line, t_all *all)
{
	line++;
	if (*line != 'E' || all->west)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->west = ft_strdup(line);
	return (0);
}

int	check_east_path(char *line, t_all *all)
{
	line++;
	if (*line != 'A' || all->east)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->east = ft_strdup(line);
	return (0);
}

int	check_sprite_path(char *line, t_all *all)
{
	line++;
	if (*line != ' ' || all->path_sprite)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->path_sprite = ft_strdup(line);
	return (0);
}
