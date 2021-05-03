/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:51 by melperri          #+#    #+#             */
/*   Updated: 2021/05/03 16:45:58 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

static void	set_all(t_all *all)
{
	ft_memset(all, 0, sizeof(*all));
	all->player.hp = 100;
	all->key.cameray1 = 0.5;
}

static int	ft_pars_all(t_all *all, char **av)
{
	if (check_map_name(all, av[1]) < 0)
		return (-1);
	if (ft_pars_file(all, av) < 0)
		return (-1);
	if (pos_sprites(all) < 0)
		return (-1);
	if (check_resolution_value(all) < 0)
		return (-1);
	if (all->player.flag == 0)
		return (check_error(all, NO_PLAYER_ERROR));
	return (0);
}

int	ft_menu_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->menu_scale.mlx_img, 0, 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 2) / 10)),
			all->ry / 2, WHITE_PIXEL, "WELCOME TO THE WORLD OF WARCUB!!!");
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 8) / 10)),
			(all->ry / 2 + ((all->ry / 2) / 8)), WHITE_PIXEL, "PRESS ENTER");
	ft_menu_control(all);	
	return (0);
}

int	ft_game_over_render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->menu_scale.mlx_img, 0, 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 2) / 10)),
			all->ry / 2, WHITE_PIXEL, "GAME OVER!!!");
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 8) / 10)),
			(all->ry / 2 + ((all->ry / 2) / 8)), WHITE_PIXEL, "PRESS ESCAPE TO LEAVE");
	ft_game_over_control(all);	
	return (0);
}

void	ft_game_over_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &ft_game_over_render, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &ft_game_over_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &ft_game_over_keypress, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_menu_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &ft_menu_render, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &ft_menu_render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &ft_menu_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}

void	ft_loop(t_all *all)
{
	mlx_loop_hook(all->mlx_ptr, &render, all);
	mlx_hook(all->win_ptr, FocusIn, FocusChangeMask, &render, all);
	mlx_hook(all->win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, &all);
	mlx_hook(all->win_ptr, KeyPress, KeyPressMask, &handle_keypress, all);
	mlx_hook(all->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, all);
	mlx_loop(all->mlx_ptr);
}

static int	ft_init_game(t_all *all)
{
	all->mlx_ptr = mlx_init();
	if (all->mlx_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	rectify_resolution_value(all);
	all->win_ptr = mlx_new_window(all->mlx_ptr, all->rx, all->ry, "Cub3D");
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	if (ft_load_all_img(all) < 0)
		return (-1);
	return (0);
}

int			main(int ac, char **av)
{
	t_all	all;

	set_all(&all);
	if (ac < 2 || ac > 3)
		return (check_error(&all, ARG_ERROR));
	if (ft_pars_all(&all, av) < 0)
		return (0);
	if (ac == 3)
		return (ft_save(&all));
	else
	{
		if (ft_init_game(&all) < 0)
			return (0);
		ft_menu_loop(&all);
	//	system("aplay -c 2 -t wav -r 48000 ./music/trap.wav &");
//		ft_loop(all);
	}
	return (0);
}
