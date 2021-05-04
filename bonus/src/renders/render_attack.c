/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:07:55 by melperri          #+#    #+#             */
/*   Updated: 2021/05/04 18:40:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int		render_attack_one(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	ft_skybox(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){368, 104, 516, 304});
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack++;
	ft_player_attack(all);
	ft_move_dragon(all);
	ft_control(all);
	return (0);
}

int		render_attack_two(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	ft_skybox(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){258, 104, 368, 304});
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack++;
	ft_move_dragon(all);
	ft_control(all);
	return (0);
}

int		render_attack_three(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	ft_skybox(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){186, 104, 258, 304});
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack++;
	ft_move_dragon(all);
	ft_control(all);
	return (0);
}

int		render_attack_four(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	ft_skybox(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){135, 104, 186, 304});
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack = 0;
	ft_move_dragon(all);
	ft_control(all);
	ft_loop(all);
	return (0);
}
