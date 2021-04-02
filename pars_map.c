#include "cub3d.h"

int	extract_map(char *line, t_all *all, int n)
{
	static int	i = 0;
	if (!all->map)
	{
		if (!(all->map = (char **)malloc(sizeof(char *) * n)))
			return (check_error(MALLOC_ERROR));
		all->map[n] = NULL;
	}
	all->map[i++] = ft_strdup(line);
	return (0);
}

void	set_player(t_all *all, int x, int y)
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
}

int	check_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map[++i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '0' || all->map[i][j] == '1'
				|| all->map[i][j] == '2')
				j++;
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
