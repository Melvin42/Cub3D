#include "cub3d.h"

int	check_north_path(char *line, t_param *param)
{
	line++;
	if (*line != 'O' || param->north)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	param->north = ft_strdup(line);	
	
	return (0);
}

int	check_south_path(char *line, t_param *param)
{
	line++;
	if (*line != 'O' || param->south)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	param->south = ft_strdup(line);	
	
	return (0);
}

int	check_west_path(char *line, t_param *param)
{
	line++;
	if (*line != 'E' || param->west)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	param->west = ft_strdup(line);	
	
	return (0);
}

int	check_east_path(char *line, t_param *param)
{
	line++;
	if (*line != 'A' || param->east)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	param->east = ft_strdup(line);	
	
	return (0);
}

int	check_sprite_path(char *line, t_param *param)
{
	line++;
	if (*line != ' ' || param->sprite)
		return (check_error(PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	param->sprite = ft_strdup(line);	
	return (0);
}
