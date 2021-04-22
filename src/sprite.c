/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:31:04 by melperri          #+#    #+#             */
/*   Updated: 2021/04/22 20:39:52 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_calc_sprite_dist(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->numsprites)
	{
		all->sprite[i].dist = ((all->player.posx - all->sprite[i].x)
							* (all->player.posx - all->sprite[i].x)
							+ (all->player.posy - all->sprite[i].y)
							* (all->player.posy - all->sprite[i].y));
	}
}

void	ft_set_sprite_vars(t_all *all, int i)
{
	all->spritex = all->sprite[i].x - all->player.posx + 0.5;
	all->spritey = all->sprite[i].y - all->player.posy + 0.5;
	all->invdet = 1.0 / (all->player.planx * all->player.diry
						- all->player.dirx * all->player.plany);
	all->transformx = all->invdet * (all->player.diry * all->spritex
									- all->player.dirx * all->spritey);
	all->transformy = all->invdet * (-all->player.plany * all->spritex
									+ all->player.planx * all->spritey);
	all->spritescreenx = (int)((all->rx / 2)
						* (1 + all->transformx / all->transformy));
	all->spriteheight = abs((int)(all->ry / all->transformy));
	all->drawstarty = -all->spriteheight / 2 + all->ry / 2;
}

void	ft_calc_sprite_ray(t_all *all)
{
	if (all->drawstarty < 0)
		all->drawstarty = 0;
	all->drawendy = all->spriteheight / 2 + all->ry / 2;
	if (all->drawendy >= all->ry)
		all->drawendy = all->ry - 1;
	all->spritewidth = abs((int)(all->ry / all->transformy));
	all->drawstartx = -all->spritewidth / 2 + all->spritescreenx;
	if (all->drawstartx < 0)
		all->drawstartx = 0;
	all->drawendx = all->spritewidth / 2 + all->spritescreenx;
	if (all->drawendx >= all->rx)
		all->drawendx = all->rx - 1;
}

void	ft_put_sprite_pix(t_all *all, int stripe)
{
	int	y;
	int	d;

	y = all->drawstarty;
	while (y < all->drawendy)
	{
		d = y * 256 - all->ry * 128 + all->spriteheight * 128;
		all->texture.tex_y = abs(((d * SPRITE_HEIGHT) / all->spriteheight)
								/ 256);
		all->texture.color = *((int *)all->sprite_img.addr + SPRITE_WIDTH
								* all->texture.tex_y + all->texture.tex_x);
		if ((all->texture.color & 0x00FFFFFF) != 0)
			img_pix_put(&all->img, stripe, y, all->texture.color);
		y++;
	}
}

void	ft_search_pix_in_sprite(t_all *all)
{
	int	stripe;

	stripe = all->drawstartx;
	while (stripe < all->drawendx)
	{
		all->texture.tex_x = abs((int)(256 * (stripe
								- (-all->spritewidth / 2 + all->spritescreenx))
								* SPRITE_WIDTH / all->spritewidth) / 256);
		if (all->transformy > 0 && stripe > 0
				&& stripe < all->rx && all->transformy < all->zbuffer[stripe])
			ft_put_sprite_pix(all, stripe);
		stripe++;
	}
}
