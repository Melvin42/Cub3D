/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:54:57 by melperri          #+#    #+#             */
/*   Updated: 2021/05/04 17:55:39 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	ft_menu_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->menu_scale.mlx_img, 0, 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 2) / 10)),
			all->ry / 2, WHITE_PIXEL, "WELCOME TO THE WORLD OF WARCUB!!!");
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 8) / 10)),
			(all->ry / 2 + ((all->ry / 2) / 8)), WHITE_PIXEL, "PRESS ENTER");
	ft_menu_control(all);	
	return (0);
}

int	ft_game_over_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->menu_scale.mlx_img, 0, 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 2) / 10)),
			all->ry / 2, WHITE_PIXEL, "GAME OVER!!!");
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 8) / 10)),
			(all->ry / 2 + ((all->ry / 2) / 8)), WHITE_PIXEL, "PRESS ESCAPE TO LEAVE");
	ft_game_over_control(all);	
	return (0);
}
