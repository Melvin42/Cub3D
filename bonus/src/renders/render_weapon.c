/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:08:30 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:07:26 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	render_weapon_pix(t_all *all, int j, int i, int color)
{
	int	x;
	int	y;
	int	factor;

	factor = 1;
	if (all->rx > 1600 && all->ry > 800)
		factor = 3;
	else if (all->rx > 1000 && all->rx <= 1600)
		factor = 2;
	else if (all->ry > 800 && all->ry <= 800)
		factor = 2;
	i = i * factor;
	j = j * factor;
	y = i - 1;
	while (++y < i + factor)
	{
		x = j - 1;
		while (++x < j + factor)
			if ((color & 0x00FFFFFF) != 0)
				img_pix_put(&all->img, all->rx / 2
					+ (all->weapon.x_end - all->weapon.x_start) * factor + x,
					all->ry - (all->weapon.y_end - all->weapon.y_start)
					* factor + y, color);
	}
	return (0);
}

int	ft_render_weapon(t_all *all)
{
	int	y;
	int	x;
	int	color;

	y = all->weapon.y_start - 1;
	while (++y < all->weapon.y_end)
	{
		x = all->weapon.x_start - 1;
		while (++x < all->weapon.x_end)
		{
			color = *((int *)all->sprite_axe.addr + (x + y * 626));
			render_weapon_pix(all, x - all->weapon.x_end, y
				- all->weapon.y_start, color);
		}
	}
	return (0);
}
