/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_lvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:48:37 by melperri          #+#    #+#             */
/*   Updated: 2021/05/20 11:49:49 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int			ft_load_next_lvl(t_all *all)
{
	ft_free_all(all);
	if (!(all->av_next = malloc(sizeof(char *) * 3)))
		return (-1);
	ft_memset(all->av_next, 0, sizeof(**all->av_next));
	if (!(all->av_next[1] = malloc(sizeof(char) * 18)))
		return (-1);
	ft_strcpy(all->av_next[1], "./maps/dragon.cub");
	main(2, all->av_next);
	return (0);
}
