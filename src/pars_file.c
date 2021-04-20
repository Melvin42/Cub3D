#include "../inc/cub3d.h"

int	check_resolution_path(char *line, t_all *all)
{
	if (all->rx != 0 || all->ry != 0)
		return (check_error(all, RES_ERROR));
	line++;
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			all->rx = ft_atoi(line);
		else
			return (check_error(all, RES_ERROR));
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			all->ry = ft_atoi(line);
		else
			return (check_error(all, RES_ERROR));
		while (ft_isdigit(*line))
			line++;
		if (*line == ' ' || *line == '\0')
			while (*line == ' ')
				line++;
		else
			return (check_error(all, RES_ERROR));
		if (*line != '\0')
			return (check_error(all, RES_ERROR));
	}
	return (0);
}

int	dispatcher(char *line, t_all *all)
{
	if (*line == 'R')
		return(check_resolution_path(line, all));
	else if (*line == 'N')
		return(check_north_path(line, all));
	else if (*line == 'S' && line[1] == 'O')
		return(check_south_path(line, all));
	else if (*line == 'W')
		return(check_west_path(line, all));
	else if (*line == 'E')
		return(check_east_path(line, all));
	else if (*line == 'S' && line[1] != 'O')
		return(check_sprite_path(line, all));
	else if (*line == 'F')
		return(check_floor_color(line, all));
	else if (*line == 'C')
		return(check_ceiling_color(line, all));
	else if ((*line == ' ' || *line == '1' || *line == '2'))
		return(extract_map(line, all)); 
	else
		return (check_error(all, PARS_ERROR));
}

int	read_file(int fd, t_all *all)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_only_space(line) && all->flag_map == 0)
		{
			free(line);
			line = NULL;
			continue;

		}
		else if (ft_only_space(line) && all->flag_map == 1)
		{
			free(line);
			line = NULL;
			return (check_error(all, EMPTY_LINE_ERROR));
		}
		if (*line != '\0')
		{
			if (dispatcher(line, all) < 0)
				return (-1);
		}
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (0);
}

int	count_line(int fd, t_all *all)
{
	int		i;
	int		j;
	int		map_line;
	char	*line;
	int		tmp;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_only_space(line))
		{
			free(line);
			line = NULL;
			continue;
		}
			j = -1;
			map_line = 0;
			tmp = ft_strlen(line);
			while (line[++j] == ' ' || line[j] == '1' || line[j] == '2')
					map_line = 1;
			if (map_line == 1)
			{
				if (all->map_width_max < tmp)
					all->map_width_max = tmp;
				i++;
			}
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	return (i);
}
