/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:40 by melperri          #+#    #+#             */
/*   Updated: 2021/04/23 09:00:10 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		ft_only_space(char *line)
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

void	sort_sprites(t_all *all)
{
	int			i;
	int			j;
	t_sprite	swap;

	i = 0;
	while (i < all->numsprites)
	{
		j = i + 1;
		while (j < all->numsprites)
		{
			if (all->sprite[i].dist < all->sprite[j].dist)
			{
				swap = all->sprite[i];
				all->sprite[i] = all->sprite[j];
				all->sprite[j] = swap;
			}
			j++;
		}
		i++;
	}
}
