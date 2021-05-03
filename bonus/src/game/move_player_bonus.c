/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:07 by melperri          #+#    #+#             */
/*   Updated: 2021/05/03 16:26:50 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_damage(t_all *all)
{
	int		hp_lost;
	double	dist_contact;
	int		i;

	hp_lost = 1;
	dist_contact = 0.05;
	i = -1;
	while (++i < all->numsprites)
	{
		if ((all->sprite[i].num >= 3 && all->sprite[i].num <= 6) ||  all->sprite[i].num == 9)
		{
			if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx + dist_contact) == (int)all->sprite[i].x))
				all->player.hp -= hp_lost;
			else if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx - dist_contact) == (int)all->sprite[i].x))
				all->player.hp -= hp_lost;
			else if (((int)(all->player.posy + dist_contact) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
				all->player.hp -= hp_lost;
			else if (((int)(all->player.posy - dist_contact) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
				all->player.hp -= hp_lost;
		}
	}
	if (all->player.hp <= 0)
		ft_game_over_loop(all);;
}

void	ft_player_attack(t_all *all)
{
	double	dist_contact;
	int		i;

	dist_contact = 0.15;
	i = -1;
	while (++i < all->numsprites)
	{
		if (all->sprite[i].num >= 3 && all->sprite[i].num <= 6)
		{
			if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx + dist_contact) == (int)all->sprite[i].x))
			{
				all->map[(int)all->sprite[i].y][(int)all->sprite[i].x] = '0';
				all->sprite[i].num = 0;
			}
			else if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx - dist_contact) == (int)all->sprite[i].x))
			{
				all->map[(int)all->sprite[i].y][(int)all->sprite[i].x] = '0';
				all->sprite[i].num = 0;
			}
			else if (((int)(all->player.posy + dist_contact) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
			{
				all->map[(int)all->sprite[i].y][(int)all->sprite[i].x] = '0';
				all->sprite[i].num = 0;
			}
			else if (((int)(all->player.posy - dist_contact) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
			{
				all->map[(int)all->sprite[i].y][(int)all->sprite[i].x] = '0';
				all->sprite[i].num = 0;
			}
		}
	}
	dist_contact = 0.5;
	if ((all->map[(int)all->player.posy][((int)(all->player.posx + dist_contact))] == '1') && (int)(all->player.posx + dist_contact) < all->map_width_max - 1)
	{
		all->map[(int)all->player.posy][((int)(all->player.posx + dist_contact))] = '0';
	}
	else if ((all->map[((int)all->player.posy)][((int)(all->player.posx - dist_contact))] == '1') && (int)(all->player.posx - dist_contact) > 0)
	{
		all->map[((int)all->player.posy)][((int)(all->player.posx - dist_contact))] = '0';
	}
	else if	((all->map[((int)(all->player.posy + dist_contact))][((int)all->player.posx)] == '1') && (int)(all->player.posy + dist_contact) < all->map_height - 1)
	{
		all->map[((int)(all->player.posy + dist_contact))][((int)all->player.posx)] = '0';
	}
	else if ((all->map[((int)(all->player.posy - dist_contact))][((int)all->player.posx)] == '1') && (int)(all->player.posy - dist_contact) > 0)
	{
		all->map[((int)(all->player.posy - dist_contact))][((int)all->player.posx)] = '0';
	}
}

static void	ft_heal(t_all *all)
{
	int		hp_win;
	int	i = -1;

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
		while (++i < all->numsprites)
		{
			if (all->sprite[i].num == 8)
			{
				if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx) == (int)all->sprite[i].x))
				{
					all->player.hp += hp_win;
					all->sprite[i].num = 0;
				}
				else if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx) == (int)all->sprite[i].x))
				{
					all->player.hp += hp_win;
					all->sprite[i].num = 0;
				}
				else if (((int)(all->player.posy) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
				{
					all->player.hp += hp_win;
					all->sprite[i].num = 0;
				}
				else if (((int)(all->player.posy) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
				{
					all->player.hp += hp_win;
					all->sprite[i].num = 0;
				}
			}
		}
	}
}
/*
void	ft_end_lvl(t_all *all)
{
	int	i = -1;

	while (++i < all->numsprites)
	{
		if (all->sprite[i].num == 2)
		{
			if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx) == (int)all->sprite[i].x))
			{
			
			}
			else if (((int)all->player.posy == (int)all->sprite[i].y) && ((int)(all->player.posx) == (int)all->sprite[i].x))
			{
			}
			else if (((int)(all->player.posy) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
			{
			}
			else if (((int)(all->player.posy) == (int)all->sprite[i].y) && ((int)all->player.posx == (int)all->sprite[i].x))
			{
			}
		}
	}
}
*/
void	move_up(t_all *all)
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
}

void	move_down(t_all *all)
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
}

void	move_left(t_all *all)
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
}

void	move_right(t_all *all)
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
}
