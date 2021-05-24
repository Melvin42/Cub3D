/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_attack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:07:55 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 15:06:52 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

int	render_attack_one(t_all *all)
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
	all->weapon.x_start = 368;
	all->weapon.y_start = 104;
	all->weapon.x_end = 516;
	all->weapon.y_end = 304;
	ft_render_weapon(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack++;
	ft_player_attack(all);
	ft_move_dragon(all);
	ft_control(all);
	return (0);
}

int	render_attack_two(t_all *all)
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
	all->weapon.x_start = 258;
	all->weapon.y_start = 104;
	all->weapon.x_end = 368;
	all->weapon.y_end = 304;
	ft_render_weapon(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack++;
	ft_move_dragon(all);
	ft_control(all);
	return (0);
}

int	render_attack_three(t_all *all)
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
	all->weapon.x_start = 186;
	all->weapon.y_start = 104;
	all->weapon.x_end = 258;
	all->weapon.y_end = 304;
	ft_render_weapon(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack++;
	ft_move_dragon(all);
	ft_control(all);
	return (0);
}

int	render_attack_four(t_all *all)
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
	all->weapon.x_start = 135;
	all->weapon.y_start = 104;
	all->weapon.x_end = 186;
	all->weapon.y_end = 304;
	ft_render_weapon(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	all->key.attack = 0;
	ft_move_dragon(all);
	ft_control(all);
	ft_loop(all);
	return (0);
}
