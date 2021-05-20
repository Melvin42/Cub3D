/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:41:29 by melperri          #+#    #+#             */
/*   Updated: 2021/05/20 14:53:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	ft_load_tex(t_all *all)
{
	if (ft_mlx_xpm_to_img(all, &all->tex_n, all->north) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_s, all->south) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_e, all->east) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_w, all->west) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_floor, all->floor) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_skybox, all->skybox) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_new_mlx_img(all, &all->skybox_scale, all->rx, all->ry / 2) < 0)
		return (check_error(all, MLX_ERROR));
	ft_img_scale(&all->skybox_scale, &all->tex_skybox);
	return (0);
}

static int	ft_load_sprite(t_all *all)
{
	if (ft_mlx_xpm_to_img(all, &all->sprite_two_img, all->path_two) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_three_img, all->path_three) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_four_img, all->path_four) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_five_img, all->path_five) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_six_img, all->path_six) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_seven_img, all->path_seven) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_eight_img, all->path_eight) < 0)
		return (check_error(all, MLX_ERROR));
	return (0);
}

static int	ft_load_dragon_part_one(t_all *all)
{
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_one, all->path_nine) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_two,
							"./sprites/dragon/dragon2.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_three,
							"./sprites/dragon/dragon3.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_four,
							"./sprites/dragon/dragon4.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_five,
							"./sprites/dragon/dragon5.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	return (0);
}

static int	ft_load_dragon_part_two(t_all *all)
{
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_six,
							"./sprites/dragon/dragon6.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_seven,
							"./sprites/dragon/dragon7.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_eight,
							"./sprites/dragon/dragon8.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_nine,
							"./sprites/dragon/dragon9.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_dragon_ten,
							"./sprites/dragon/dragon10.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	return (0);
}

int			ft_load_all_img(t_all *all)
{
	int	factor;

	factor = mini_map_factor(all);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->menu, "./menu/menu.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_new_mlx_img(all, &all->menu_scale, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_load_tex(all) < 0)
		return (-1);
	if (ft_load_sprite(all) < 0)
		return (-1);
	if (ft_load_dragon_part_one(all) < 0)
		return (-1);
	if (ft_load_dragon_part_two(all) < 0)
		return (-1);
	if (ft_new_mlx_img(all, &all->mini_map,
					all->map_width_max * factor, all->map_height * factor) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_axe, "./sprites/axe.xpm") < 0)
		return (check_error(all, MLX_ERROR));
	ft_img_scale(&all->menu_scale, &all->menu);
	return (0);
}
