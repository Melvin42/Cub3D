/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:15 by melperri          #+#    #+#             */
/*   Updated: 2021/05/19 22:11:21 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	set_map_width_max(t_all *all, char *line, int i)
{
	int	j;
	int	map_line;
	int	tmp;

	j = -1;
	map_line = 0;
	tmp = ft_strlen(line);
	while (line[++j] == ' ' || (line[j] >= '0' && line[j] <= '9'))
		map_line = 1;
	if (map_line == 1)
	{
		if (all->map_width_max < tmp)
			all->map_width_max = tmp;
		i++;
	}
	return (i);
}

int			count_line(int fd, t_all *all)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_only_space(line))
		{
			free(line);
			line = NULL;
			continue;
		}
		i = set_map_width_max(all, line, i);
		free(line);
		line = NULL;
	}
	free(line);
	return (i);
}

static int	read_file(int fd, t_all *all)
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
			if (dispatcher(line, all) < 0)
				return (-1);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	return (0);
}

int			ft_pars_file(t_all *all, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (check_error(all, fd));
	all->map_malloc_size = count_line(fd, all);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (read_file(fd, all) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (!all->map)
		return (check_error(all, FOLDER_ERROR));
	if (check_map(all) < 0)
		return (-1);
	if (is_map_open(all) < 0)
		return (-1);
	replace_space_by_one(all);
	return (0);
}
