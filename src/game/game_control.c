/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:45 by melperri          #+#    #+#             */
/*   Updated: 2021/04/23 09:14:46 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int			ft_exit_cross(t_all *all)
{
	ft_free_all(all);
	exit(0);
	return (0);
}

static void	ft_escape(t_all *all)
{
	ft_free_all(all);
	exit(SUCCESS);
}

int			handle_keypress(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		ft_escape(all);
	else if (keysym == XK_Up || keysym == XK_w)
		move_up(all);
	else if (keysym == XK_Down || keysym == XK_s)
		move_down(all);
	else if (keysym == XK_a)
		move_left(all);
	else if (keysym == XK_d)
		move_right(all);
	else if (keysym == XK_Left || keysym == XK_q)
		rotate_left(all);
	else if (keysym == XK_Right || keysym == XK_e)
		rotate_right(all);
	render(all);
	return (0);
}
