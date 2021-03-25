#include "cub3d.h"

int	extract_map(char *line, t_param *param, int n)
{
	static int	i = 0;
	if (!param->map)
	{
		if (!(param->map = (char **)malloc(sizeof(char *) * n)))
			return (check_error(MALLOC_ERROR));
		param->map[n] = NULL;
	}
	param->map[i++] = ft_strdup(line);
	return (0);
}

void	set_player(t_param *param, t_player *player, int x, int y)
{
	player->flag = 1;
	if (param->map[y][x] =='N')
		player->diry = -1;
	else if (param->map[y][x] =='S')
		player->diry = 1;
	else if (param->map[y][x] =='E')
		player->dirx = -1;
	else if (param->map[y][x] =='W')
		player->dirx = 1;
}

int	check_map(t_param *param, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (param->map[++i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == '0' || param->map[i][j] == '1'
				|| param->map[i][j] == '2' || param->map[i][j] == ' ')
				j++;
			else if (param->map[i][j] == 'N' || param->map[i][j] == 'S'
				|| param->map[i][j] == 'E' || param->map[i][j] == 'W')
			{
				if (player->flag == 1)
					return (check_error(PARS_ERROR));
				set_player(param, player, j, i);
				player->posx = j;
				player->posy = i;
				j++;
			}
			else
				return (check_error(PARS_ERROR));
		}
	}
	return (0);
}
