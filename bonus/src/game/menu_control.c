/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:21:05 by melperri          #+#    #+#             */
/*   Updated: 2021/05/20 10:42:25 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_game_over_control(t_all *all)
{
	if (all->key.escape == 1)
		ft_escape(all);
}

int		ft_game_over_keypress(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		all->key.escape = 1;
	return (0);
}

void	ft_next_lvl_menu_control(t_all *all)
{
	if (all->key.escape == 1)
		ft_escape(all);
	if (all->key.menu == 1)
		ft_load_next_lvl(all);
}

void	ft_menu_control(t_all *all)
{
	if (all->key.escape == 1)
		ft_escape(all);
	if (all->key.menu == 1)
		ft_loop(all);
}

int		ft_menu_keypress(int keysym, t_all *all)
{
	if (keysym == XK_Return)
		all->key.menu = 1;
	if (keysym == XK_Escape)
		all->key.escape = 1;
	return (0);
}
