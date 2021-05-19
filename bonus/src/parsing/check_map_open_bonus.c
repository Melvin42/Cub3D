/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_open_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:13 by melperri          #+#    #+#             */
/*   Updated: 2021/05/19 22:21:18 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	check_side_up_down(t_all *all)
{
	int	x;

	x = -1;
	while (all->map[0][++x] == ' ' || all->map[0][x] == '1')
		;
	if (x < all->map_width_max)
		return (check_error(all, MAP_ERROR));
	x = -1;
	while (all->map[all->map_height - 1][++x] == ' '
			|| all->map[all->map_height - 1][x] == '1')
		;
	if (x != all->map_width_max)
		return (check_error(all, MAP_ERROR));
	return (0);
}

static int	check_side_left_right(t_all *all)
{
	int	y;

	y = -1;
	while ((all->map[++y][0] == ' ' || all->map[y][0] == '1')
		&& y < all->map_height - 1)
		;
	if (y < all->map_height - 1)
		return (check_error(all, MAP_ERROR));
	y = -1;
	while ((all->map[++y][all->map_width_max - 1] == ' '
			|| all->map[y][all->map_width_max - 1] == '1')
			&& y < all->map_height - 1)
		;
	if (y != all->map_height - 1)
		return (check_error(all, MAP_ERROR));
	return (0);
}

static int	check_around_zero(t_all *all, int x, int y, int flag)
{
	while (++y < all->map_height - 1)
	{
		x = -1;
		while (++x < all->map_width_max - 1)
		{
			flag = 1;
			if (all->map[y][x] == '0')
				flag = 0;
			if ((all->map[y][x] == '0')
				&& ((all->map[y][x + 1] >= '0' && all->map[y][x + 1] <= '9')
				|| (all->map[y][x + 1] >= 'a' && all->map[y][x + 1] <= 'z'))
				&& ((all->map[y][x - 1] >= '0' && all->map[y][x - 1] <= '9')
				|| (all->map[y][x - 1] >= 'a' && all->map[y][x - 1] <= 'z'))
				&& ((all->map[y + 1][x] >= '0' && all->map[y + 1][x] <= '9')
				|| (all->map[y + 1][x] >= 'a' && all->map[y + 1][x] <= 'z'))
				&& ((all->map[y - 1][x] >= '0' && all->map[y - 1][x] <= '9')
				|| (all->map[y - 1][x] >= 'a' && all->map[y - 1][x] <= 'z')))
				flag = 1;
			if (flag == 0)
				return (check_error(all, MAP_ERROR));
		}
	}
	return (0);
}

int			is_map_open(t_all *all)
{
	if (check_side_up_down(all) < 0)
		return (-1);
	if (check_side_left_right(all) < 0)
		return (-1);
	if (check_around_zero(all, 0, 0, 0) < 0)
		return (-1);
	return (0);
}
