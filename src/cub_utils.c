#include "../inc/cub3d.h"

int 	ft_only_space(char *line)
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

void	replace_space_by_one(t_all *all)
{
	int	x;
	int	y;

	y = -1;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == ' ')
				all->map[y][x] = '1';
		}
	}
}

void	ft_free_all(t_all *all)
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
	if (all->zbuffer)
		free(all->zbuffer);
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
	if (all->mlx_ptr)
		free(all->mlx_ptr);
}
