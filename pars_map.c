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
		write(1, STR_MALLOC_ERROR, ft_strlen(STR_MALLOC_ERROR));
	else if (i == ARG_ERROR)
		write(1, STR_ARG_ERROR, ft_strlen(STR_ARG_ERROR));
	else if (i == FD_ERROR)
		write(1, STR_FD_ERROR, ft_strlen(STR_FD_ERROR));
	else if (i == PARS_ERROR)
		write(1, STR_PARS_ERROR, ft_strlen(STR_PARS_ERROR)); 
	return (0);
}

int	check_resolution(char *line, t_param *param)
{
	if (param->rx != 0 || param->ry != 0)
		return (check_error(PARS_ERROR));
	while (*line)
	{
		// dabord passer la lettre 'R';
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			param->rx = ft_atoi(line);
		else
			return (PARS_ERROR);
		while (ft_isdigit(*line))
			line++;
		while (*line == ' ')
			line++;
		if (ft_isdigit(*line))
			param->ry = ft_atoi(line);
		else
			return (PARS_ERROR);
		while (ft_isdigit(*line))
			line++;
	}
	return (0);
}

int	check_texture_path(char *line, t_param *param)
{
	(void)line;
	(void)param;
	return (0);
}

int	check_color(char *line, t_param *param)
{
	(void)line;
	(void)param;
	return (0);
}

int	check_map(char *line, t_param *param)
{
	(void)line;
	(void)param;
	return (0);
}

int	dispatcher(char *line, t_param *param)
{
	if (*line == 'R')
		check_resolution(line, param);
	else if (*line == 'N' || *line != 'S')
	{
		check_texture_path(line, param);
	}
	else if (*line == 'W')
	{
		check_texture_path(line, param);
	}
	else if (*line == 'E')
	{
		check_texture_path(line, param);
	}
	else if (*line == 'S')
		check_texture_path(line, param);
	else if (*line == 'F')
		check_color(line, param);
	else if (*line == 'C')
		check_color(line, param);
	else
		return (check_error(PARS_ERROR));
	return (0);
}


int	read_file(int n, int fd, t_param *param)
{
	int		i;
	char	*line;
	if (!(param->map = malloc(sizeof(char *) * n + 1)))
		return (check_error(MALLOC_ERROR));
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		dispatcher(line, param);
		i++;
		free(line);
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
		free(line);
	}
	return (i);
}

int	main(int ac, char **av)
{
	int	fd;
	t_param	param;
	int	n;

	param = (t_param){0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	if (ac != 2)
		return (check_error(ARG_ERROR));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (check_error(fd));
	n = count_line(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	read_file(n, fd, &param);
	close(fd);
	printf("x = %d\n", param.rx);
	printf("y = %d\n", param.ry);
	return (0);
}
