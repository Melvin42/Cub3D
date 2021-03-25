#include "cub3d.h"

int	extract_map(char *line, t_data *data, int n)
{
	static int	i = 0;
	if (!data->map)
	{
		if (!(data->map = (char **)malloc(sizeof(char *) * n)))
			return (check_error(MALLOC_ERROR));
		data->map[n] = NULL;
	}
	data->map[i++] = ft_strdup(line);
	return (0);
}

void	set_player(t_data *data, int x, int y)
{
	data->player.flag = 1;
	if (data->map[y][x] =='N')
		data->player.diry = -1;
	else if (data->map[y][x] =='S')
		data->player.diry = 1;
	else if (data->map[y][x] =='E')
		data->player.dirx = -1;
	else if (data->map[y][x] =='W')
		data->player.dirx = 1;
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0' || data->map[i][j] == '1'
				|| data->map[i][j] == '2' || data->map[i][j] == ' ')
				j++;
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				if (data->player.flag == 1)
					return (check_error(PARS_ERROR));
				set_player(data, j, i);
				data->player.posx = j;
				data->player.posy = i;
				j++;
			}
			else
				return (check_error(PARS_ERROR));
		}
	}
	return (0);
}
