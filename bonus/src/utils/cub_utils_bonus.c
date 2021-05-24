/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:40 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:10:31 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	ft_img_scale(t_img *dst, t_img *src)
{
	int		x;
	int		y;
	int		color;
	double	target_x;
	double	target_y;

	y = -1;
	while (++y < (int)dst->res_y)
	{
		x = -1;
		while (++x < (int)dst->res_x)
		{
			target_x = ((double)x / (double)dst->res_x * (double)src->res_x);
			target_y = ((double)y / (double)dst->res_y * (double)src->res_y);
			target_x = floor(target_x);
			target_y = floor(target_y);
			color = *((int *)src->addr + ((int)target_x
						+ (int)target_y * src->res_x));
			img_pix_put(dst, x, y, color);
		}
	}
	return (0);
}

int	ft_only_space(char *line)
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

	ft_calc_sprite_dist(all);
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
