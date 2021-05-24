/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_next_lvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:48:37 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:11:23 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	ft_load_next_lvl(t_all *all)
{
	char	*test[3];

	ft_free_all(all);
	test[0] = "./cub3D";
	test[1] = "./maps/dragon.cub";
	test[2] = NULL;
	main(2, test);
	return (0);
}
