/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:40 by melperri          #+#    #+#             */
/*   Updated: 2021/04/22 19:30:41 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

void	ft_render_side(t_all *all, int x)
{
	if (all->ray.hit == 1)
	{
		if (all->ray.side == 0 && all->ray.step_x == -1)
			render_tex_e(all, x, all->ray.drawstart);
		else if (all->ray.side == 0 && all->ray.step_x == 1)
			render_tex_w(all, x, all->ray.drawstart);
		else if (all->ray.side == 1 && all->ray.step_y == -1)
			render_tex_s(all, x, all->ray.drawstart);
		else if (all->ray.side == 1 && all->ray.step_y == 1)
			render_tex_n(all, x, all->ray.drawstart);
	}
}

int		render(t_all *all)
{
	if (all->win_ptr == NULL)// mettre le bon retour d'erreur
		return (1);
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (1);
	render_background(all);
	raycast(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	return (0);
}
