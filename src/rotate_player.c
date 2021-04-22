/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:53 by melperri          #+#    #+#             */
/*   Updated: 2021/04/22 19:30:54 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_all *all)
{
	double	olddirx;
	double	oldplanx;

	olddirx = all->player.dirx;
	all->player.dirx = all->player.dirx * cos(-ROTSPEED)
					- all->player.diry * sin(-ROTSPEED);
	all->player.diry = olddirx * sin(-ROTSPEED)
					+ all->player.diry * cos(-ROTSPEED);
	oldplanx = all->player.planx;
	all->player.planx = all->player.planx * cos(-ROTSPEED)
					- all->player.plany * sin(-ROTSPEED);
	all->player.plany = oldplanx * sin(-ROTSPEED)
					+ all->player.plany * cos(-ROTSPEED);
}

void	rotate_right(t_all *all)
{
	double	olddirx;
	double	oldplanx;

	olddirx = all->player.dirx;
	all->player.dirx = all->player.dirx * cos(ROTSPEED)
					- all->player.diry * sin(ROTSPEED);
	all->player.diry = olddirx * sin(ROTSPEED)
					+ all->player.diry * cos(ROTSPEED);
	oldplanx = all->player.planx;
	all->player.planx = all->player.planx * cos(ROTSPEED)
					- all->player.plany * sin(ROTSPEED);
	all->player.plany = oldplanx * sin(ROTSPEED)
					+ all->player.plany * cos(ROTSPEED);
}
