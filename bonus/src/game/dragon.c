/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:46:19 by melperri          #+#    #+#             */
/*   Updated: 2021/05/05 18:00:00 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_move_dragon(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->numsprites)
	{
		if (all->sprite[i].num == 9)
		{
			if (all->player.posy < all->sprite[i].y)
				all->sprite[i].y -= 0.1;
			else if (all->player.posy > all->sprite[i].y)
				all->sprite[i].y += 0.1;
			if (all->player.posx < all->sprite[i].x)
				all->sprite[i].x -= 0.1;
			else if (all->player.posx > all->sprite[i].x)
				all->sprite[i].x += 0.1;
		}
	}
	ft_damage(all);
}
