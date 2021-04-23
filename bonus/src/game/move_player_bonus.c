/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:07 by melperri          #+#    #+#             */
/*   Updated: 2021/04/23 09:09:32 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	move_up(t_all *all)
{
	if (all->map[(int)all->player.posy]
				[(int)(all->player.posx + all->player.dirx * MOVESPEED)] == '0')
		all->player.posx += all->player.dirx * MOVESPEED;
	if (all->map[(int)(all->player.posy + all->player.diry * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy += all->player.diry * MOVESPEED;
}

void	move_down(t_all *all)
{
	if (all->map[(int)all->player.posy]
				[(int)(all->player.posx - all->player.dirx * MOVESPEED)] == '0')
		all->player.posx -= all->player.dirx * MOVESPEED;
	if (all->map[(int)(all->player.posy - all->player.diry * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy -= all->player.diry * MOVESPEED;
}

void	move_left(t_all *all)
{
	if (all->map[(int)all->player.posy]
			[(int)(all->player.posx - all->player.planx * MOVESPEED)] == '0')
		all->player.posx -= all->player.planx * MOVESPEED;
	if (all->map[(int)(all->player.posy - all->player.plany * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy -= all->player.plany * MOVESPEED;
}

void	move_right(t_all *all)
{
	if (all->map[(int)all->player.posy]
			[(int)(all->player.posx + all->player.planx * MOVESPEED)] == '0')
		all->player.posx += all->player.planx * MOVESPEED;
	if (all->map[(int)(all->player.posy + all->player.plany * MOVESPEED)]
				[(int)all->player.posx] == '0')
		all->player.posy += all->player.plany * MOVESPEED;
}
