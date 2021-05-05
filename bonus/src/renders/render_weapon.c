/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:08:30 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 21:02:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	render_weapon_pix(t_all *all, int j, int i, int color)
{
	int	x;
	int	y;

	i = i * 3;
	j = j * 3;
	y = i - 1;
	while (++y < i + 3)
	{
		x = j - 1;
		while (++x < j + 3)
			if ((color & 0x00FFFFFF) != 0)
				img_pix_put(&all->img, all->rx / 2
							+ (all->weapon.x_end - all->weapon.x_start) * 3 + x,
							all->ry - (all->weapon.y_end - all->weapon.y_start)
							* 3 + y, color);
	}
	return (0);
}

int			ft_render_weapon(t_all *all)
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
			render_weapon_pix(all, x - all->weapon.x_start, y
									- all->weapon.y_start, color);
		}
	}
	return (0);
}
