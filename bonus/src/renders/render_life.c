/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:29:40 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 21:14:22 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_put_string_life(t_all *all)
{
	char hp[5];

	if (all->player.hp == 100)
	{
		hp[0] = '1';
		hp[1] = '0';
		hp[2] = '0';
		hp[3] = '%';
		hp[4] = '\0';
	}
	else
	{
		hp[0] = ' ';
		hp[1] = all->player.hp / 10 + 48;
		hp[2] = all->player.hp % 10 + 48;
		hp[3] = '%';
		hp[4] = '\0';
	}
	mlx_string_put(all->mlx_ptr, all->win_ptr, all->rx / 2, 25, 0XFFFFFF, hp);
}

void	render_life(t_all *all)
{
	int	drawstart;
	int	drawend;
	int	red_drawend;
	int	x;
	int	y;

	drawstart = all->rx / 3;
	drawend = all->rx - all->rx / 3;
	red_drawend = (((all->rx / 3) * all->player.hp) / 100) + all->rx / 3;
	y = 10 - 1;
	x = drawstart - 1;
	while (x < drawend + 1)
		img_pix_put(&all->img, x++, y, WHITE_PIXEL);
	while (++y <= 30)
	{
		x = drawstart - 1;
		img_pix_put(&all->img, x, y, WHITE_PIXEL);
		while (++x <= red_drawend)
			img_pix_put(&all->img, x, y, RED_PIXEL);
		img_pix_put(&all->img, drawend, y, WHITE_PIXEL);
	}
	x = drawstart - 1;
	while (x < drawend + 1)
		img_pix_put(&all->img, x++, y, WHITE_PIXEL);
}
