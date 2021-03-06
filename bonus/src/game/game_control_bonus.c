/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:45 by melperri          #+#    #+#             */
/*   Updated: 2021/05/25 14:32:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	ft_exit_cross(t_all *all)
{
	ft_free_all(all);
	system("pkill -n aplay");
	exit(SUCCESS);
	return (0);
}

void	ft_escape(t_all *all)
{
	ft_free_all(all);
	system("pkill -n aplay");
	exit(SUCCESS);
}

void	ft_control(t_all *all)
{
	if (all->key.escape == 1)
		ft_escape(all);
	if (all->key.up == 1)
		move_up(all);
	if (all->key.down == 1)
		move_down(all);
	if (all->key.left == 1)
		move_left(all);
	if (all->key.right == 1)
		move_right(all);
	if (all->key.rot_left == 1)
		rotate_left(all);
	if (all->key.rot_right == 1)
		rotate_right(all);
	if (all->key.attack == 1)
		ft_attack_one_loop(all);
	if (all->key.attack == 2)
		ft_attack_two_loop(all);
	if (all->key.attack == 3)
		ft_attack_three_loop(all);
	if (all->key.attack == 4)
		ft_attack_four_loop(all);
	if (all->key.menu == 0)
		ft_menu_loop(all);
}

int	handle_keypress(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		all->key.escape = 1;
	if (keysym == XK_w)
		all->key.up = 1;
	if (keysym == XK_s)
		all->key.down = 1;
	if (keysym == XK_a)
		all->key.left = 1;
	if (keysym == XK_d)
		all->key.right = 1;
	if (keysym == XK_Left || keysym == XK_q)
		all->key.rot_left = 1;
	if (keysym == XK_Right || keysym == XK_e)
		all->key.rot_right = 1;
	if (keysym == XK_Up)
		all->key.sprint = 1;
	if (keysym == XK_f)
		all->key.attack = 1;
	if (keysym == XK_c)
		all->key.cameray += 1.0;
	if (keysym == XK_v && all->key.cameray > 0.5)
		all->key.cameray -= 1.0;
	if (keysym == XK_p)
		all->key.menu = 0;
	return (0);
}

int	handle_keyrelease(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		all->key.escape = 0;
	if (keysym == XK_w)
		all->key.up = 0;
	if (keysym == XK_s)
		all->key.down = 0;
	if (keysym == XK_a)
		all->key.left = 0;
	if (keysym == XK_d)
		all->key.right = 0;
	if (keysym == XK_Left || keysym == XK_q)
		all->key.rot_left = 0;
	if (keysym == XK_Right || keysym == XK_e)
		all->key.rot_right = 0;
	if (keysym == XK_Up)
		all->key.sprint = 0;
	return (0);
}
