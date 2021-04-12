#include "cub3d.h"

char *ft_strcpy_cub_line(t_all *all, char *dst, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
	{
		dst[i] = src[i];
	}
	while (i < all->map_width_max)
	{
		dst[i] = ' ';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	extract_map(char *line, t_all *all)
{
	static int	i = 0;
	if (!all->map)
	{
		if (!(all->map = (char **)malloc(sizeof(char *) * (all->map_malloc_size + 1))))
			return (check_error(MALLOC_ERROR));
		all->map_height = all->map_malloc_size;
		all->map[all->map_height] = NULL;
	}
	if (!(all->map[i] = malloc(sizeof(char) * (all->map_width_max + 1))))
		return (check_error(MALLOC_ERROR));
	all->map[i] = ft_strcpy_cub_line(all, all->map[i], line);
	i++;
	return (0);
}

int	set_player(t_all *all, int x, int y)
{
	all->player.flag = 1;
	if (all->map[y][x] == 'N')
	{
		all->player.diry = -1;
		all->player.planx = 0.66;
		all->player.plany = 0;
	}
	else if (all->map[y][x] == 'S')
	{
		all->player.diry = 1;
		all->player.planx = -0.66;
		all->player.plany = 0;
	}
	else if (all->map[y][x] == 'E')
	{
		all->player.dirx = -1;
		all->player.planx = 0;
		all->player.plany = -0.66;
	}
	else if (all->map[y][x] == 'W')
	{
		all->player.dirx = 1;
		all->player.planx = 0;
		all->player.plany = 0.66;
	}
	all->map[y][x] = '0';
	return (0);
}

int	pos_sprites(t_all *all)
{
	int	x;
	int	y;
	int	i;

	if (!(all->sprite = malloc(sizeof(t_sprite) * (all->numsprites + 1))))
		return (check_error(MALLOC_ERROR));
	all->sprite[all->numsprites] = (t_sprite){0, 0, 0, 0};
	y = -1;
	i = 0;
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == '2')
			{
				all->sprite[i].x = (double)x;
				all->sprite[i].y = (double)y;
				i++;
				//all.map[y][x] = '0';
			}
		}
	}
	return (0);
}

int	check_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	if (!all->map)
			return (check_error(FOLDER_ERROR));
	while (all->map[++i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '0' || all->map[i][j] == '1')
				j++;
			else if (all->map[i][j] == '2')
			{
				all->numsprites++;
				j++;
			}
			else if (all->map[i][j] == ' ')
			{
				all->map[i][j] = '1';
				j++;
			}
			else if (all->map[i][j] == 'N' || all->map[i][j] == 'S'
				|| all->map[i][j] == 'E' || all->map[i][j] == 'W')
			{
				if (all->player.flag == 1)
					return (check_error(PARS_ERROR));
				set_player(all, j, i);
				all->player.posx = j + 0.5;
				all->player.posy = i + 0.5;
				j++;
			}
			else
				return (check_error(PARS_ERROR));
		}
	}
	return (0);
}
