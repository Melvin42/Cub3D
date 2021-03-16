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
	if (i == -2)
		write(1, STR_ERROR_ARG, ft_strlen(STR_ERROR_ARG));
	return (0);
}

int	count_line(int fd, char *line)
{
	int	i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	char	*line;
	char	**map;
//	char	**charac;
	int	fd;
	int	i;
	
	i = 0;	
	map = NULL;
	line = NULL;
	if (ac != 2)
		return (check_error(ERROR_ARG));
	fd = open(av[1], O_RDONLY);
	if (fd != -1)
		i = count_line(fd, line);
	close(fd);
	if (!(map = (char **)malloc(sizeof(char *) * (i + 1))))
		return (-1);
	if (map)
		map[i + 1] = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd != -1)
	{
		i = 0;
		while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
			map[i] = line;
			i++;
		}	
	}
	close(fd);
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
