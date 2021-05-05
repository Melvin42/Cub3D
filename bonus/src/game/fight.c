/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:40:03 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 19:09:48 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void		ft_damage(t_all *all)
{
	double	d;
	int		i;

	d = 0.05;
	i = -1;
	while (++i < all->numsprites)
		if ((all->sprite[i].num >= 3 && all->sprite[i].num <= 6)
			|| all->sprite[i].num == 9)
		{
			if (((int)all->player.posy == (int)all->sprite[i].y)
					&& ((int)(all->player.posx + d) == (int)all->sprite[i].x))
				all->player.hp -= 1;
			else if (((int)all->player.posy == (int)all->sprite[i].y)
					&& ((int)(all->player.posx - d) == (int)all->sprite[i].x))
				all->player.hp -= 1;
			else if (((int)(all->player.posy + d) == (int)all->sprite[i].y)
					&& ((int)all->player.posx == (int)all->sprite[i].x))
				all->player.hp -= 1;
			else if (((int)(all->player.posy - d) == (int)all->sprite[i].y)
					&& ((int)all->player.posx == (int)all->sprite[i].x))
				all->player.hp -= 1;
		}
	if (all->player.hp <= 0)
		ft_game_over_loop(all);
}

static void	ft_del_sprite(t_all *all, int i)
{
	all->map[(int)all->sprite[i].y][(int)all->sprite[i].x] = '0';
	all->sprite[i].num = 0;
}

static void	ft_del_wall(t_all *all)
{
	double	d;

	d = 0.5;
	if ((all->map[(int)all->player.posy]
				[((int)(all->player.posx + d))] == '1')
				&& (int)(all->player.posx + d) < all->map_width_max - 1)
		all->map[(int)all->player.posy][((int)(all->player.posx + d))] = '0';
	else if ((all->map[((int)all->player.posy)]
				[((int)(all->player.posx - d))] == '1')
				&& (int)(all->player.posx - d) > 0)
		all->map[((int)all->player.posy)][((int)(all->player.posx - d))] = '0';
	else if ((all->map[((int)(all->player.posy + d))]
				[((int)all->player.posx)] == '1')
				&& (int)(all->player.posy + d) < all->map_height - 1)
		all->map[((int)(all->player.posy + d))][((int)all->player.posx)] = '0';
	else if ((all->map[((int)(all->player.posy - d))]
				[((int)all->player.posx)] == '1')
				&& (int)(all->player.posy - d) > 0)
		all->map[((int)(all->player.posy - d))][((int)all->player.posx)] = '0';
}

void		ft_player_attack(t_all *all)
{
	double	d;
	int		i;

	d = 0.15;
	i = -1;
	while (++i < all->numsprites)
	{
		if (all->sprite[i].num >= 3 && all->sprite[i].num <= 6)
		{
			if (((int)all->player.posy == (int)all->sprite[i].y)
					&& ((int)(all->player.posx + d) == (int)all->sprite[i].x))
				ft_del_sprite(all, i);
			else if (((int)all->player.posy == (int)all->sprite[i].y)
					&& ((int)(all->player.posx - d) == (int)all->sprite[i].x))
				ft_del_sprite(all, i);
			else if (((int)(all->player.posy + d) == (int)all->sprite[i].y)
					&& ((int)all->player.posx == (int)all->sprite[i].x))
				ft_del_sprite(all, i);
			else if (((int)(all->player.posy - d) == (int)all->sprite[i].y)
					&& ((int)all->player.posx == (int)all->sprite[i].x))
				ft_del_sprite(all, i);
		}
	}
	ft_del_wall(all);
}
