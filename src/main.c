/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:51 by melperri          #+#    #+#             */
/*   Updated: 2021/04/23 09:31:27 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_all(t_all *all)
{
	*all = (t_all){NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 0, 0,
			(t_player){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_ray){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_texture){0, 0, 0, 0, 0, 0},
			NULL,
			(t_img){NULL, NULL, 0, 0, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0, 0, 0},
			(t_rgb){-1, -1, -1},
			(t_rgb){-1, -1, -1}};
}

static int	ft_pars_all(t_all *all, char **av)
{
	if (check_map_name(all, av[1]) < 0)
		return (-1);
	if (ft_pars_file(all, av) < 0)
		return (-1);
	if (pos_sprites(all) < 0)
		return (-1);
	if (check_rgb(all) < 0)
		return (-1);
	all->floor_color = encode_rgb(all->floor.red,
								all->floor.green, all->floor.blue);
	all->ceiling_color = encode_rgb(all->ceiling.red,
								all->ceiling.green, all->ceiling.blue);
	if (check_resolution_value(all) < 0)
		return (-1);
	if (all->player.flag == 0)
		return (check_error(all, NO_PLAYER_ERROR));
	return (0);
}

static void	ft_loop(t_all all)
{
	render(&all);
	mlx_hook(all.win_ptr, ClientMessage, StructureNotifyMask,
			&ft_exit_cross, &all);
	mlx_hook(all.win_ptr, FocusIn, FocusChangeMask, &render, &all);
	mlx_hook(all.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &all);
	mlx_loop(all.mlx_ptr);
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
	if (ac < 2 && ac > 3)
		return (check_error(&all, ARG_ERROR));
	if (ft_pars_all(&all, av) < 0)
		return (0);
	if (ac == 3)
		return (ft_save(&all));
	else
	{
		if (ft_init_game(&all) < 0)
			return (0);
		ft_loop(all);
	}
	return (0);
}
