/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_loops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:48:19 by melperri          #+#    #+#             */
/*   Updated: 2021/05/04 17:50:22 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_attack_one_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &render_attack_one, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &render_attack_one, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, &all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_attack_two_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &render_attack_two, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &render_attack_two, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, &all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_attack_three_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &render_attack_three, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &render_attack_three, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, &all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_attack_four_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &render_attack_four, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &render_attack_four, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, &all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}
