/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:40 by melperri          #+#    #+#             */
/*   Updated: 2021/05/20 14:55:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_set_raycast_vars(t_all *all)
{
	all->player.raydirx = all->player.dirx + all->player.planx
						* all->player.camerax;
	all->player.raydiry = all->player.diry + all->player.plany
						* all->player.camerax;
	all->ray.map_x = (int)(all->player.posx);
	all->ray.map_y = (int)(all->player.posy);
	all->ray.delta_dist_x = fabs(1.0 / all->player.raydirx);
	all->ray.delta_dist_y = fabs(1.0 / all->player.raydiry);
	all->ray.hit = 0;
}

void	ft_chose_tex(t_all *all)
{
	if (all->ray.hit == 1)
	{
		if (all->ray.side == 0 && all->ray.step_x == -1)
		{
			all->tex_width = all->tex_e.res_x;
			all->tex_height = all->tex_e.res_y;
		}
		else if (all->ray.side == 0 && all->ray.step_x == 1)
		{
			all->tex_width = all->tex_w.res_x;
			all->tex_height = all->tex_w.res_y;
		}
		else if (all->ray.side == 1 && all->ray.step_y == -1)
		{
			all->tex_width = all->tex_s.res_x;
			all->tex_height = all->tex_s.res_y;
		}
		else if (all->ray.side == 1 && all->ray.step_y == 1)
		{
			all->tex_width = all->tex_n.res_x;
			all->tex_height = all->tex_n.res_y;
		}
	}
}

void	ft_skybox(t_all *all)
{
	int		x;
	int		y;
	int		color;
	double	vector;
	int		vectorx;

	vector = atan2(all->player.raydirx, all->player.raydiry);
	vector *= (double)all->rx / 6.28;
	y = -1;
	while (++y < all->ry / 2)
	{
		x = -1;
		vectorx = (int)vector;
		while (++x < all->rx)
		{
			color = *((int *)all->skybox_scale.addr
					+ (x + ((y * all->skybox_scale.res_x))));
			if (vectorx < 0)
				img_pix_put(&all->img, all->rx + vectorx, y, color);
			else
				img_pix_put(&all->img, vectorx, y, color);
			vectorx++;
		}
	}
}
