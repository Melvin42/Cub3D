/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:46:04 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:08:16 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	mini_map_factor(t_all *all)
{
	int	factor;

	if (all->rx > 1600 && all->ry > 800)
		factor = 4;
	else if (all->rx > 600 && all->rx <= 1600)
		factor = 3;
	else if (all->ry > 400 && all->ry <= 800)
		factor = 3;
	else if (all->rx > 200 && all->rx <= 600)
		factor = 2;
	else if (all->ry > 200 && all->ry <= 400)
		factor = 2;
	else
		factor = 1;
	return (factor);
}

static void	render_mini_map_pix(t_all *all, int j, int i, int color)
{
	int	x;
	int	y;
	int	factor;

	factor = mini_map_factor(all);
	i = i * factor;
	j = j * factor;
	y = i;
	while (y++ < i + factor)
	{
		x = j;
		while (x < j + factor)
			img_pix_put(&all->mini_map, x++, y, color);
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

void	ft_mini_map(t_all *all)
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
