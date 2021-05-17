/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:29:15 by melperri          #+#    #+#             */
/*   Updated: 2021/05/11 15:23:28 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_destroy_img_tex(t_all *all)
{
	if (all->tex_n.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->tex_n.mlx_img);
	if (all->tex_s.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->tex_s.mlx_img);
	if (all->tex_e.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->tex_e.mlx_img);
	if (all->tex_w.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->tex_w.mlx_img);
}

static void	ft_destroy_img_sprite(t_all *all)
{
	if (all->sprite_two_img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_two_img.mlx_img);
	if (all->sprite_three_img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_three_img.mlx_img);
	if (all->sprite_four_img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_four_img.mlx_img);
	if (all->sprite_five_img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_five_img.mlx_img);
	if (all->sprite_six_img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_six_img.mlx_img);
	if (all->sprite_seven_img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_seven_img.mlx_img);
	if (all->sprite_eight_img.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_eight_img.mlx_img);
}

static void	ft_destroy_img_dragon(t_all *all)
{
	if (all->sprite_dragon_one.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_one.mlx_img);
	if (all->sprite_dragon_two.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_two.mlx_img);
	if (all->sprite_dragon_three.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_three.mlx_img);
	if (all->sprite_dragon_four.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_four.mlx_img);
	if (all->sprite_dragon_five.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_five.mlx_img);
	if (all->sprite_dragon_six.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_six.mlx_img);
	if (all->sprite_dragon_seven.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_seven.mlx_img);
	if (all->sprite_dragon_eight.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_eight.mlx_img);
	if (all->sprite_dragon_nine.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_nine.mlx_img);
	if (all->sprite_dragon_ten.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_dragon_ten.mlx_img);
}

static void	ft_free_path(t_all *all)
{
	free(all->north);
	free(all->south);
	free(all->west);
	free(all->east);
	free(all->path_two);
	free(all->path_three);
	free(all->path_four);
	free(all->path_five);
	free(all->path_six);
	free(all->path_seven);
	free(all->path_eight);
	free(all->path_nine);
}

void		ft_free_all(t_all *all)
{
	ft_free_path(all);
	free(all->zbuffer);
	while (all->index-- > 0)
	{
		if (all->map[all->index])
			free(all->map[all->index]);
	}
	free(all->map);
	free(all->sprite);
	if (all->mlx_ptr)
	{
		if (all->win_ptr)
		{
			ft_destroy_img_tex(all);
			ft_destroy_img_sprite(all);
			ft_destroy_img_dragon(all);
			if (all->img.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
			mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		}
		mlx_destroy_display(all->mlx_ptr);
		free(all->mlx_ptr);
	}
}
