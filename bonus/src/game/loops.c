/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:41:32 by melperri          #+#    #+#             */
/*   Updated: 2021/05/19 18:24:21 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_game_over_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &ft_game_over_render, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &ft_game_over_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &ft_game_over_keypress, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_next_lvl_loop(t_all *all)
{
	all->key.menu = 0;
	ft_free_to_go_next_lvl(all);
	ft_load_next_lvl(all);
	mlx_loop_hook(all->mlx_ptr, &ft_next_lvl_menu_render, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask,
			&ft_next_lvl_menu_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &ft_menu_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_menu_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &ft_menu_render, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &ft_menu_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &ft_menu_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &render, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, &all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}
