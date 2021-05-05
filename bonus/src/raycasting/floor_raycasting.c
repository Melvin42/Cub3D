/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:18:49 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 20:37:36 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	set_vars(t_all *all, int y)
{
	all->floor_ray.raydirx0 = all->player.dirx - all->player.planx;
	all->floor_ray.raydiry0 = all->player.diry - all->player.plany;
	all->floor_ray.raydirx1 = all->player.dirx + all->player.planx;
	all->floor_ray.raydiry1 = all->player.diry + all->player.plany;
	all->floor_ray.p = y - all->ry / 2;
	all->floor_ray.posz = 0.5 * all->ry;
	all->floor_ray.rowdistance = all->floor_ray.posz / all->floor_ray.p;
	all->floor_ray.floorstepx = all->floor_ray.rowdistance
							* (all->floor_ray.raydirx1
							- all->floor_ray.raydirx0) / all->rx;
	all->floor_ray.floorstepy = all->floor_ray.rowdistance
							* (all->floor_ray.raydiry1
							- all->floor_ray.raydiry0) / all->rx;
	all->floor_ray.floorx = all->player.posx + all->floor_ray.rowdistance
							* all->floor_ray.raydirx0;
	all->floor_ray.floory = all->player.posy + all->floor_ray.rowdistance
							* all->floor_ray.raydiry0;
}

static void	ft_calc_ray(t_all *all)
{
	all->floor_ray.cellx = (int)all->floor_ray.floorx;
	all->floor_ray.celly = (int)all->floor_ray.floory;
	all->floor_ray.tx = (int)(all->tex_floor.res_x
						* (all->floor_ray.floorx - all->floor_ray.cellx))
						& (all->tex_floor.res_x - 1);
	all->floor_ray.ty = (int)(all->tex_floor.res_y
						* (all->floor_ray.floory - all->floor_ray.celly))
						& (all->tex_floor.res_y - 1);
	all->floor_ray.floorx += all->floor_ray.floorstepx;
	all->floor_ray.floory += all->floor_ray.floorstepy;
}

void		floor_casting(t_all *all)
{
	int	y;
	int	x;
	int	color;

	y = (all->ry / 2) - 1;
	while (++y < all->ry)
	{
		set_vars(all, y);
		x = -1;
		while (++x < all->rx)
		{
			ft_calc_ray(all);
			color = *((int *)all->tex_floor.addr + (all->tex_floor.res_x
					* all->floor_ray.ty + all->floor_ray.tx));
			img_pix_put(&all->img, x, y, color);
		}
	}
}
