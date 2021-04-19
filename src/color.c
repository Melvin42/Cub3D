#include "../inc/cub3d.h"

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

int	check_floor_color(char *line, t_all *all)
{
	if (all->floor.red != -1 || all->floor.green != -1
		|| all->floor.blue != -1)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	if (!ft_isdigit(*line))
		return (check_error(all, PARS_ERROR));
	else
	{
		all->floor.red = ft_atoi(line);
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
	if (!ft_isdigit(*line))
		return (check_error(all, PARS_ERROR));
	else
	{
		all->floor.green = ft_atoi(line);
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
	if (!ft_isdigit(*line))
		return (check_error(all, PARS_ERROR));
	else
	{
		all->floor.blue = ft_atoi(line);
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

int	check_ceiling_color(char *line, t_all *all)
{
	if (all->ceiling.red != -1 || all->ceiling.green != -1
		|| all->ceiling.blue != -1)
		return (check_error(all, PARS_ERROR));
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
