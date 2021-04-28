/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:07 by melperri          #+#    #+#             */
/*   Updated: 2021/04/28 10:15:03 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_damage(t_all *all)
{
	int		hp_lost;
	double	dist_contact;

	hp_lost = 4;
	dist_contact = 0.1;
	if (all->map[(int)all->player.posy][(int)(all->player.posx + dist_contact)] == '9')
		all->player.hp -= hp_lost;
	else if (all->map[(int)all->player.posy][(int)(all->player.posx - dist_contact)] == '9')
		all->player.hp -= hp_lost;
	else if (all->map[(int)(all->player.posy + dist_contact)][(int)all->player.posx] == '9')
		all->player.hp -= hp_lost;
	else if (all->map[(int)(all->player.posy - dist_contact)][(int)all->player.posx] == '9')
		all->player.hp -= hp_lost;
	if (all->player.hp == 0)
		ft_escape(all);
}

static void	ft_heal(t_all *all)
{
	int		hp_win;
	double	dist_contact;

	dist_contact = 0.1;
	if (all->player.hp == 99)
		hp_win = 1;
	else if (all->player.hp == 98)
		hp_win = 2;
	else if (all->player.hp == 97)
		hp_win = 3;
	else
		hp_win = 4;
	if (all->player.hp < 100)
	{
		if (all->map[(int)all->player.posy][(int)(all->player.posx + dist_contact)] == '3')
			all->player.hp += hp_win;
		else if (all->map[(int)all->player.posy][(int)(all->player.posx - dist_contact)] == '3')
			all->player.hp += hp_win;
		else if (all->map[(int)(all->player.posy + dist_contact)][(int)all->player.posx] == '3')
			all->player.hp += hp_win;
		else if (all->map[(int)(all->player.posy - dist_contact)][(int)all->player.posx] == '3')
			all->player.hp += hp_win;
	}
}

void	move_up(t_all *all)
{
	if (all->map[(int)all->player.posy]
				[(int)(all->player.posx + all->player.dirx * MOVESPEED)] == '0')
		all->player.posx += all->player.dirx * MOVESPEED;
	if (all->map[(int)(all->player.posy + all->player.diry * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy += all->player.diry * MOVESPEED;
	ft_damage(all);
	ft_heal(all);
}

void	move_down(t_all *all)
{
	if (all->map[(int)all->player.posy]
				[(int)(all->player.posx - all->player.dirx * MOVESPEED)] == '0')
		all->player.posx -= all->player.dirx * MOVESPEED;
	if (all->map[(int)(all->player.posy - all->player.diry * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy -= all->player.diry * MOVESPEED;
	ft_damage(all);
	ft_heal(all);
}

void	move_left(t_all *all)
{
	if (all->map[(int)all->player.posy]
			[(int)(all->player.posx - all->player.planx * MOVESPEED)] == '0')
		all->player.posx -= all->player.planx * MOVESPEED;
	if (all->map[(int)(all->player.posy - all->player.plany * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy -= all->player.plany * MOVESPEED;
	ft_damage(all);
	ft_heal(all);
}

void	move_right(t_all *all)
{
	if (all->map[(int)all->player.posy]
			[(int)(all->player.posx + all->player.planx * MOVESPEED)] == '0')
		all->player.posx += all->player.planx * MOVESPEED;
	if (all->map[(int)(all->player.posy + all->player.plany * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy += all->player.plany * MOVESPEED;
	ft_damage(all);
	ft_heal(all);
}
