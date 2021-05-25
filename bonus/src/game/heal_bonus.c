/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:02:17 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 13:56:56 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_pick_up_heal(t_all *all, int i, int hp_win)
{
	all->player.hp += hp_win;
	all->sprite[i].num = 0;
}

static void	ft_pos_item_heal(t_all *all, int i, int hp_win)
{
	if (((int)all->player.posy == (int)all->sprite[i].y)
		&& ((int)(all->player.posx) == (int)all->sprite[i].x))
		ft_pick_up_heal(all, i, hp_win);
	else if (((int)all->player.posy == (int)all->sprite[i].y)
		&& ((int)(all->player.posx) == (int)all->sprite[i].x))
		ft_pick_up_heal(all, i, hp_win);
	else if (((int)(all->player.posy) == (int)all->sprite[i].y)
		&& ((int)all->player.posx == (int)all->sprite[i].x))
		ft_pick_up_heal(all, i, hp_win);
	else if (((int)(all->player.posy) == (int)all->sprite[i].y)
		&& ((int)all->player.posx == (int)all->sprite[i].x))
		ft_pick_up_heal(all, i, hp_win);
}

void	ft_heal(t_all *all)
{
	int	hp_win;
	int	i;

	hp_win = 4;
	if (all->player.hp == 99)
		hp_win = 1;
	else if (all->player.hp == 98)
		hp_win = 2;
	else if (all->player.hp == 97)
		hp_win = 3;
	i = -1;
	if (all->player.hp < 100)
		while (++i < all->numsprites)
			if (all->sprite[i].num == 8)
				ft_pos_item_heal(all, i, hp_win);
}
