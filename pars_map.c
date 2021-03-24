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

int	check_map(t_param *param)
{
	int	i;
	int	j;

	i = -1;
	while (param->map[++i])
	{
		j = -1;
		while (param->map[i][++j])
		{
			printf("%c", param->map[i][j]);
			if (!ft_isdigit(param->map[i][j]) || param->map[i][j] != ' ')
				return(check_error(PARS_ERROR));
		}
	}
	return (0);
}
