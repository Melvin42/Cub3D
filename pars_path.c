#include "cub3d.h"

int	check_north_path(char *line, t_data *data)
{
	line++;
	if (*line != 'O' || data->north)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	data->north = ft_strdup(line);	
	
	return (0);
}

int	check_south_path(char *line, t_data *data)
{
	line++;
	if (*line != 'O' || data->south)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	data->south = ft_strdup(line);	
	
	return (0);
}

int	check_west_path(char *line, t_data *data)
{
	line++;
	if (*line != 'E' || data->west)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	data->west = ft_strdup(line);	
	
	return (0);
}

int	check_east_path(char *line, t_data *data)
{
	line++;
	if (*line != 'A' || data->east)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	data->east = ft_strdup(line);	
	
	return (0);
}

int	check_sprite_path(char *line, t_data *data)
{
	line++;
	if (*line != ' ' || data->sprite)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	data->sprite = ft_strdup(line);	
	return (0);
}
