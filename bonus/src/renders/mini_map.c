/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:46:04 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 19:53:17 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	render_mini_map_pix(t_all *all, int j, int i, int color)
{
	int	x;
	int	y;

	i = i * 4;
	j = j * 4;
	y = i;
	while (y < i + 4)
	{
		x = j;
		while (x < j + 4)
		{
			img_pix_put(&all->mini_map, x, y, color);
			x++;
		}
		y++;
	}
}

static void	ft_put_dragon_on_mini_map(t_all *all)
{
	int	d;

	d = -1;
	while (++d < all->numsprites)
		if (all->sprite[d].num == 9)
			render_mini_map_pix(all, (int)(all->sprite[d].x),
								(int)(all->sprite[d].y), RED_PIXEL);
}

void		ft_mini_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->map_height)
	{
		j = -1;
		while (++j < all->map_width_max)
		{
			if (all->map[i][j] == '1')
				render_mini_map_pix(all, j, i, GREY_PIXEL);
			else if (all->map[i][j] >= '2' && all->map[i][j] <= '8')
				render_mini_map_pix(all, j, i, WHITE_PIXEL);
			else
				render_mini_map_pix(all, j, i, BLACK_PIXEL);
			ft_put_dragon_on_mini_map(all);
			render_mini_map_pix(all, (int)(all->player.posx),
								(int)(all->player.posy), GREEN_PIXEL);
		}
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr,
							all->mini_map.mlx_img, 0, 0);
}
