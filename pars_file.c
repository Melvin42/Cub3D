/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:39:46 by melperri          #+#    #+#             */
/*   Updated: 2021/02/02 16:31:52 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_error(int i)
{
	if (i == MALLOC_ERROR)
	{
		write(1, STR_MALLOC_ERROR, ft_strlen(STR_MALLOC_ERROR));
		return (-1);
	}
	else if (i == ARG_ERROR)
	{
		write(1, STR_ARG_ERROR, ft_strlen(STR_ARG_ERROR));
		return (-1);
	}
	else if (i == FD_ERROR)
	{
		write(1, STR_FD_ERROR, ft_strlen(STR_FD_ERROR));
		return (-1);
	}
	else if (i == PARS_ERROR)
	{
		write(1, STR_PARS_ERROR, ft_strlen(STR_PARS_ERROR)); 
		return (-1);
	}
	else if (i == MLX_ERROR)
	{
		write(1, STR_MLX_ERROR, ft_strlen(STR_MLX_ERROR)); 
		return (-1);
	}
	else if (i == FOLDER_ERROR)
	{
		write(1, STR_FOLDER_ERROR, ft_strlen(STR_FOLDER_ERROR)); 
		return (-1);
	}
	else if (i == MAP_ERROR)
	{
		write(1, STR_MAP_ERROR, ft_strlen(STR_MAP_ERROR)); 
		return (-1);
	}
	else if (i == RES_ERROR)
	{
		write(1, STR_RES_ERROR, ft_strlen(STR_RES_ERROR)); 
		return (-1);
	}
	return (0);
}

int	check_resolution(char *line, t_all *all)
{
	if (all->rx != 0 || all->ry != 0)
		return (check_error(RES_ERROR));
	line++;
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			all->rx = ft_atoi(line);
		else
			return (check_error(RES_ERROR));
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			all->ry = ft_atoi(line);
		else
			return (check_error(RES_ERROR));
		while (ft_isdigit(*line))
			line++;
	}
	return (0);
}

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

int	dispatcher(char *line, t_all *all)
{
	if (*line == 'R')
		return(check_resolution(line, all));
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
	else if (*line == ' ' || *line == '1' || *line == '2')
		return(extract_map(line, all)); 
	else
		return (check_error(PARS_ERROR));
	return (0);
}

int only_space(char *line)
{
	if (!line)
		return (1);
	while (*line)
	{
		if (*line != ' ')
			return (0);
		line++;
	}
	return (1);
}

int	read_file(int fd, t_all *all)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (!only_space(line))
		{
			if (dispatcher(line, all) < 0)
				return (-1);
		}
		all->map_malloc_size--;
		if (line)
			free(line);
	}
	if (line)
		free(line);
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
		i++;
		j = -1;
		map_line = 0;
		tmp = ft_strlen(line);
		while ((line[++j] == ' ' || line[j] == '1' || line[j] == '2') && !only_space(line))
				map_line = 1;
		if (map_line == 1)
			if (all->map_width_max < tmp)
				all->map_width_max = tmp;
		if (line)
			free(line);
	}
	if (line)
		free(line);
	return (i);
}

void	free_all(t_all *all)
{
	int	i;

	if (all->north)
		free(all->north);
	if (all->south)
		free(all->south);
	if (all->west)
		free(all->west);
	if (all->east)
		free(all->east);
	if (all->path_sprite)
		free(all->path_sprite);
	if (all->map)
	{
		i = -1;
		while (all->map[++i])
		{
			if (all->map[i])
				free(all->map[i]);
		}
		free(all->map);
	}
	if (all->sprite)
		free(all->sprite);
}
