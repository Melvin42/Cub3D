/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:04:52 by melperri          #+#    #+#             */
/*   Updated: 2021/04/24 09:46:08 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	menu(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->menu.mlx_img, ((all->rx / 2) - (418 / 2)), 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 2) / 10)),
			all->ry / 2, WHITE_PIXEL, "WELCOME TO THE WORLD OF WARCUB!!!");
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 8) / 10)),
			(all->ry / 2 + ((all->ry / 2) / 8)), WHITE_PIXEL, "PRESS ENTER");
	return (0);
}

/*
**	int			menu_width;
**	int			menu_height;
**	menu_width = 418;
**	menu_height = 402;
**	all.menu.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, "./worldofwarcub.xpm", &menu_width, &menu_height);
**	all.menu.addr = mlx_get_data_addr(all.menu.mlx_img, &all.menu.bpp,
**					&all.menu.line_len, &all.menu.endian);
**	menu(&all);
*/

//	mlx_mouse_hide(all.mlx_ptr, all.win_ptr);

int		render_life(t_all *all)
{
	int	drawstart;
	int	drawend;
	int	x;
	int	y;

	if (all->win_ptr == NULL)
		return (1);
	drawstart = (all->ry / 2 - all->ry / 3);
	drawend = (all->ry / 2) + (all->ry / 3);
	y = 10;
	x = drawstart - 1;
	while (x < drawend + 1)
		img_pix_put(&all->img, x++, y - 1, WHITE_PIXEL);
	while (y <= 30)
	{
		x = drawstart - 1;
		img_pix_put(&all->img, x, y, WHITE_PIXEL);
		x++;
		while (x < drawend)
		{
			img_pix_put(&all->img, x++, y, RED_PIXEL);
		}
		img_pix_put(&all->img, x, y, WHITE_PIXEL);
		y++;
	}
	x = drawstart - 1;
	while (x < drawend + 1)
		img_pix_put(&all->img, x++, y, WHITE_PIXEL);
	return (0);
}
