/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:07 by melperri          #+#    #+#             */
/*   Updated: 2021/05/19 23:31:39 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_end_lvl(t_all *all)
{
	double	d;
	int	i;

	d = 0.05;
	i = -1;
	while (++i < all->numsprites)
		if (all->sprite[i].num == 2)
		{
			if (((int)all->player.posy == (int)all->sprite[i].y)
				&& ((int)(all->player.posx + d) == (int)all->sprite[i].x))
			{
				ft_next_lvl_loop(all);
			}
			else if (((int)all->player.posy == (int)all->sprite[i].y)
				&& ((int)(all->player.posx - d) == (int)all->sprite[i].x))
			{
				ft_next_lvl_loop(all);
			}
			else if (((int)(all->player.posy + d) == (int)all->sprite[i].y)
				&& ((int)all->player.posx == (int)all->sprite[i].x))
			{
				ft_next_lvl_loop(all);
			}
			else if (((int)(all->player.posy - d) == (int)all->sprite[i].y)
				&& ((int)all->player.posx == (int)all->sprite[i].x))
			{
				ft_next_lvl_loop(all);
			}
		}
}

void		move_up(t_all *all)
{
	float	movespeed;

	movespeed = 0.1;
	if (all->key.sprint == 1)
		movespeed = 0.3;
	if (all->map[(int)all->player.posy]
				[(int)(all->player.posx + all->player.dirx * movespeed)] == '0')
		all->player.posx += all->player.dirx * movespeed;
	if (all->map[(int)(all->player.posy + all->player.diry * movespeed)]
				[(int)all->player.posx] == '0')
		all->player.posy += all->player.diry * movespeed;
	ft_damage(all);
	ft_heal(all);
	ft_end_lvl(all);
}

void		move_down(t_all *all)
{
	float	movespeed;

	movespeed = 0.1;
	if (all->key.sprint == 1)
		movespeed = 0.3;
	if (all->map[(int)all->player.posy]
				[(int)(all->player.posx - all->player.dirx * movespeed)] == '0')
		all->player.posx -= all->player.dirx * movespeed;
	if (all->map[(int)(all->player.posy - all->player.diry * movespeed)]
				[(int)all->player.posx] == '0')
		all->player.posy -= all->player.diry * movespeed;
	ft_damage(all);
	ft_heal(all);
	ft_end_lvl(all);
}

void		move_left(t_all *all)
{
	float	movespeed;

	movespeed = 0.1;
	if (all->key.sprint == 1)
		movespeed = 0.3;
	if (all->map[(int)all->player.posy]
			[(int)(all->player.posx - all->player.planx * movespeed)] == '0')
		all->player.posx -= all->player.planx * movespeed;
	if (all->map[(int)(all->player.posy - all->player.plany * movespeed)]
				[(int)all->player.posx] == '0')
		all->player.posy -= all->player.plany * movespeed;
	ft_damage(all);
	ft_heal(all);
	ft_end_lvl(all);
}

void		move_right(t_all *all)
{
	float	movespeed;

	movespeed = 0.1;
	if (all->key.sprint == 1)
		movespeed = 0.3;
	if (all->map[(int)all->player.posy]
			[(int)(all->player.posx + all->player.planx * movespeed)] == '0')
		all->player.posx += all->player.planx * movespeed;
	if (all->map[(int)(all->player.posy + all->player.plany * movespeed)]
				[(int)all->player.posx] == '0')
		all->player.posy += all->player.plany * movespeed;
	ft_damage(all);
	ft_heal(all);
	ft_end_lvl(all);
}
