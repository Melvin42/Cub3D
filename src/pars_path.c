#include "../inc/cub3d.h"

int	check_north_path(char *line, t_all *all)
{
	int fd;

	line++;
	if (*line != 'O' || all->north)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->north = ft_strdup((const char *)line);
	if (all->north == NULL)
		return (check_error(all, PARS_ERROR));
	all->north = ft_strtrim((const char *)all->north, " ");
	if (check_xpm_path(all, all->north) < 0)
		return (-1);
	fd = open(all->north, O_RDONLY);
	if (read(fd, 0, 0))
	{
		close(fd);
		return (check_error(all, FOLDER_ERROR));
	}
	close(fd);
	if (fd == -1)
		return (check_error(all, PARS_ERROR));
	return (0);
}

int	check_south_path(char *line, t_all *all)
{
	int fd;

	line++;
	if (*line != 'O' || all->south)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->south = ft_strdup((const char *)line);
	if (all->south == NULL)
		return (check_error(all, PARS_ERROR));
	all->south = ft_strtrim((const char *)all->south, " ");
	if (check_xpm_path(all, all->south) < 0)
		return (-1);
	fd = open(all->south, O_RDONLY);
	if (read(fd, 0, 0))
	{
		close(fd);
		return (check_error(all, FOLDER_ERROR));
	}
	close(fd);
	if (fd == -1)
		return (check_error(all, PARS_ERROR));
	return (0);
}

int	check_west_path(char *line, t_all *all)
{
	int fd;

	line++;
	if (*line != 'E' || all->west)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->west = ft_strdup((const char *)line);
	if (all->west == NULL)
		return (check_error(all, PARS_ERROR));
	all->west = ft_strtrim((const char *)all->west, " ");
	if (check_xpm_path(all, all->west) < 0)
		return (-1);
	fd = open(all->west, O_RDONLY);
	if (read(fd, 0, 0))
	{
		close(fd);
		return (check_error(all, FOLDER_ERROR));
	}
	close(fd);
	if (fd == -1)
		return (check_error(all, PARS_ERROR));
	return (0);
}

int	check_east_path(char *line, t_all *all)
{
	int fd;

	line++;
	if (*line != 'A' || all->east)
		return (check_error(all, PARS_ERROR));
	line++;
	while (*line == ' ')
		line++;
	all->east = ft_strdup((const char *)line);
	if (all->east == NULL)
		return (check_error(all, PARS_ERROR));
	all->east = ft_strtrim((const char *)all->east, " ");
	if (check_xpm_path(all, all->east) < 0)
		return (-1);
	fd = open(all->east, O_RDONLY);
	if (read(fd, 0, 0))
	{
		close(fd);
		return (check_error(all, FOLDER_ERROR));
	}
	close(fd);
	if (fd == -1)
		return (check_error(all, PARS_ERROR));
	return (0);
}

int	check_sprite_path(char *line, t_all *all)
{
	int fd;

	line++;
	if (*line != ' ' || all->path_sprite)
		return (check_error(all, PARS_ERROR));
	while (*line == ' ')
		line++;
	all->path_sprite = ft_strdup((const char *)line);
	if (all->path_sprite == NULL)
		return (check_error(all, PARS_ERROR));
	all->path_sprite = ft_strtrim((const char *)all->path_sprite, " ");
	if (check_xpm_path(all, all->path_sprite) < 0)
		return (-1);
	fd = open(all->path_sprite, O_RDONLY);
	if (read(fd, 0, 0))
	{
		close(fd);
		return (check_error(all, FOLDER_ERROR));
	}
	close(fd);
	if (fd == -1)
		return (check_error(all, PARS_ERROR));
	return (0);
}
