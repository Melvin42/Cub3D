/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:29:15 by melperri          #+#    #+#             */
/*   Updated: 2021/04/24 10:50:51 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_free_all_part_two(t_all *all)
{
	if (all->sprite)
		free(all->sprite);
	if (all->mlx_ptr)
	{
		if (all->win_ptr)
		{
			if (all->tex_n.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->tex_n.mlx_img);
			if (all->tex_s.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->tex_s.mlx_img);
			if (all->tex_e.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->tex_e.mlx_img);
			if (all->tex_w.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->tex_w.mlx_img);
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
			if (all->sprite_nine_img.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->sprite_nine_img.mlx_img);
			if (all->img.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
			mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		}
		mlx_destroy_display(all->mlx_ptr);
		free(all->mlx_ptr);
	}
}

void		ft_free_all(t_all *all)
{
	if (all->north)
		free(all->north);
	if (all->south)
		free(all->south);
	if (all->west)
		free(all->west);
	if (all->east)
		free(all->east);
	if (all->path_sprite_two)
		free(all->path_sprite_two);
	if (all->path_sprite_three)
		free(all->path_sprite_three);
	if (all->path_sprite_four)
		free(all->path_sprite_four);
	if (all->path_sprite_five)
		free(all->path_sprite_five);
	if (all->path_sprite_six)
		free(all->path_sprite_six);
	if (all->path_sprite_seven)
		free(all->path_sprite_seven);
	if (all->path_sprite_eight)
		free(all->path_sprite_eight);
	if (all->path_sprite_nine)
		free(all->path_sprite_nine);
	if (all->zbuffer)
		free(all->zbuffer);
	if (all->map)
	{
		all->index--;
		while (all->index >= 0)
		{
			free(all->map[all->index]);
			all->index--;
		}
		free(all->map);
	}
	ft_free_all_part_two(all);
}
