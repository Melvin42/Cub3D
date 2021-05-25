/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:42:09 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 13:48:12 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	ft_dispatch_s(char *line, t_all *all)
{
	if (*line == 'S' && line[1] == 'O')
		return (check_south_path(line, all));
	else if (*line == 'S' && line[1] == '2')
		return (check_sprite_two_path(line, all));
	else if (*line == 'S' && line[1] == '3')
		return (check_sprite_three_path(line, all));
	else if (*line == 'S' && line[1] == '4')
		return (check_sprite_four_path(line, all));
	else if (*line == 'S' && line[1] == '5')
		return (check_sprite_five_path(line, all));
	else if (*line == 'S' && line[1] == '6')
		return (check_sprite_six_path(line, all));
	else if (*line == 'S' && line[1] == '7')
		return (check_sprite_seven_path(line, all));
	else if (*line == 'S' && line[1] == '8')
		return (check_sprite_eight_path(line, all));
	else if (*line == 'S' && line[1] == '9')
		return (check_sprite_nine_path(line, all));
	else
		return (0);
}

int	dispatcher(char *line, t_all *all)
{
	if (*line == 'R')
		return (check_resolution_path(line, all));
	else if (*line == 'N')
		return (check_north_path(line, all));
	else if (*line == 'W')
		return (check_west_path(line, all));
	else if (*line == 'E')
		return (check_east_path(line, all));
	else if (*line == 'S'
		&& (line[1] == 'O' || (line[1] >= '2' && line[1] <= '9')))
	{
		if (ft_dispatch_s(line, all) < 0)
			return (-1);
	}
	else if (*line == 'C')
		return (check_skybox_path(line, all));
	else if (*line == 'F')
		return (check_floor_path(line, all));
	else if ((*line == ' ') || (*line >= '1' && *line <= '9'))
		return (extract_map(line, all));
	else
		return (check_error(all, PARS_ERROR));
	return (0);
}
