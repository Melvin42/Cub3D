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
	return (0);
}

int	check_resolution(char *line, t_all *all)
{
	if (all->rx != 0 || all->ry != 0)
		return (check_error(PARS_ERROR));
	line++;
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			all->rx = ft_atoi(line);
		else
			return (PARS_ERROR);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			all->ry = ft_atoi(line);
		else
			return (PARS_ERROR);
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

int	dispatcher(char *line, t_all *all, int n)
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
	else if (*line == ' ' || *line == '1')
		return(extract_map(line, all, n)); 
	else
		return (PARS_ERROR);
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

int	read_file(int n, int fd, t_all *all)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (!only_space(line))
		{
			if (dispatcher(line, all, n) < 0)
				return (-1);
		}
		n--;
	//	free(line);
	}
	return (0);
}

int	count_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
//		free(line);
	}
	return (i);
}

void	free_all(t_all *all)
{
	if (all->north)
		free(all->north);
	if (all->south)
		free(all->south);
	if (all->west)
		free(all->west);
	if (all->east)
		free(all->east);
	if (all->sprite)
		free(all->sprite);
	//free > char **map
}
