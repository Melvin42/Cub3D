/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_two_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:34:50 by melperri          #+#    #+#             */
/*   Updated: 2021/05/25 11:38:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_free_gnl_line(char **line)
{
	free(*line);
	*line = NULL;
}

void	ft_finish_gnl(int fd, char *line)
{
	ft_free_gnl_line(&line);
	while (get_next_line(fd, &line) > 0)
		ft_free_gnl_line(&line);
	ft_free_gnl_line(&line);
}
