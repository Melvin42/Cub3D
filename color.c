#include "cub3d.h"

int	check_floor_color(char *line, t_all *all)
{
	if (all->floor.red != -1 || all->floor.green != -1
		|| all->floor.blue != -1)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	if (!ft_isdigit(*line))
		return (check_error(PARS_ERROR));
	else
	{
		all->floor.red = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	if (*line == ',')
		line++;
	else
		return (check_error(PARS_ERROR));
	if (!ft_isdigit(*line))
		return (check_error(PARS_ERROR));
	else
	{
		all->floor.green = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	if (*line == ',')
		line++;
	else
		return (check_error(PARS_ERROR));
	if (!ft_isdigit(*line))
		return (check_error(PARS_ERROR));
	else
	{
		all->floor.blue = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	return (0);
}

int	check_ceiling_color(char *line, t_all *all)
{
	if (all->ceiling.red != -1 || all->ceiling.green != -1
		|| all->ceiling.blue != -1)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	if (!ft_isdigit(*line))
		return (check_error(PARS_ERROR));
	else
	{
		all->ceiling.red = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	if (*line == ',')
		line++;
	else
		return (check_error(PARS_ERROR));
	if (!ft_isdigit(*line))
		return (check_error(PARS_ERROR));
	else
	{
		all->ceiling.green = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	if (*line == ',')
		line++;
	else
		return (check_error(PARS_ERROR));
	if (!ft_isdigit(*line))
		return (check_error(PARS_ERROR));
	else
	{
		all->ceiling.blue = ft_atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	return (0);
}
