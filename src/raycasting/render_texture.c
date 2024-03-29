/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:46 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 13:21:56 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	render_tex_n(t_all *all, int x, int y)
{
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (all->tex_n.res_y - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_n.addr + (all->tex_n.res_y
					* all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}

int	render_tex_s(t_all *all, int x, int y)
{
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (all->tex_s.res_y - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_s.addr + (all->tex_s.res_y
					* all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}

int	render_tex_e(t_all *all, int x, int y)
{
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (all->tex_e.res_y - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_e.addr + (all->tex_e.res_y
					* all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}

int	render_tex_w(t_all *all, int x, int y)
{
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (all->tex_w.res_y - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_w.addr + (all->tex_w.res_y
					* all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}
