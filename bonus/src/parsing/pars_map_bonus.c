/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:21 by melperri          #+#    #+#             */
/*   Updated: 2021/04/23 09:36:54 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static char	*ft_strcpy_cub_line(t_all *all, char *dst, char *src)
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

int			extract_map(char *line, t_all *all)
{
	if (ft_only_space(line) && all->flag_map == 0)
		return (0);
	if (!all->map)
	{
		if (!(all->map = malloc(sizeof(char *) * (all->map_malloc_size + 1))))
			return (check_error(all, MALLOC_ERROR));
		all->map_height = all->map_malloc_size;
		all->map[all->map_height] = NULL;
	}
	all->flag_map = 1;
	if (!(all->map[all->index] = malloc(sizeof(char)
								* (all->map_width_max + 1))))
		return (check_error(all, MALLOC_ERROR));
	if (all->index < all->map_height)
		all->map[all->index] = ft_strcpy_cub_line(all,
												all->map[all->index], line);
	all->index++;
	return (0);
}

static void	set_player(t_all *all, int x, int y)
{
	all->player.flag = 1;
	if (all->map[y][x] == 'N')
	{
		all->player.diry = -1;
		all->player.planx = 0.66;
	}
	else if (all->map[y][x] == 'S')
	{
		all->player.diry = 1;
		all->player.planx = -0.66;
	}
	else if (all->map[y][x] == 'E')
	{
		all->player.dirx = -1;
		all->player.plany = -0.66;
	}
	else if (all->map[y][x] == 'W')
	{
		all->player.dirx = 1;
		all->player.plany = 0.66;
	}
	all->map[y][x] = '0';
	all->player.posx = x + 0.5;
	all->player.posy = y + 0.5;
}

int			check_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
			if (all->map[i][j] == '0' || all->map[i][j] == '1'
				|| all->map[i][j] == ' ')
				;
			else if (all->map[i][j] == '2')
				all->numsprites++;
			else if (all->map[i][j] == 'N' || all->map[i][j] == 'S'
				|| all->map[i][j] == 'E' || all->map[i][j] == 'W')
			{
				if (all->player.flag == 1)
					return (check_error(all, PARS_ERROR));
				set_player(all, j, i);
			}
			else
				return (check_error(all, PARS_ERROR));
	}
	return (0);
}

int			pos_sprites(t_all *all)
{
	int	x;
	int	y;
	int	i;

	if (!(all->sprite = malloc(sizeof(t_sprite) * (all->numsprites + 1))))
		return (check_error(all, MALLOC_ERROR));
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
			}
		}
	}
	return (0);
}
