/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:00:41 by melperri          #+#    #+#             */
/*   Updated: 2021/05/17 16:34:03 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void		ft_render_side(t_all *all, int x)
{
	if (all->ray.hit == 1)
	{
		if (all->ray.side == 0 && all->ray.step_x == -1)
			render_tex_e(all, x, all->ray.drawstart);
		else if (all->ray.side == 0 && all->ray.step_x == 1)
			render_tex_w(all, x, all->ray.drawstart);
		else if (all->ray.side == 1 && all->ray.step_y == -1)
			render_tex_s(all, x, all->ray.drawstart);
		else if (all->ray.side == 1 && all->ray.step_y == 1)
			render_tex_n(all, x, all->ray.drawstart);
	}
}

static void	render_dragon(t_all *all)
{
	if (all->dragon_frame == 1)
		ft_search_pix_in_sprite(all, all->sprite_dragon_one);
	else if (all->dragon_frame == 2)
		ft_search_pix_in_sprite(all, all->sprite_dragon_two);
	else if (all->dragon_frame == 3)
		ft_search_pix_in_sprite(all, all->sprite_dragon_three);
	else if (all->dragon_frame == 4)
		ft_search_pix_in_sprite(all, all->sprite_dragon_four);
	else if (all->dragon_frame == 5)
		ft_search_pix_in_sprite(all, all->sprite_dragon_five);
	else if (all->dragon_frame == 6)
		ft_search_pix_in_sprite(all, all->sprite_dragon_six);
	else if (all->dragon_frame == 7)
		ft_search_pix_in_sprite(all, all->sprite_dragon_seven);
	else if (all->dragon_frame == 8)
		ft_search_pix_in_sprite(all, all->sprite_dragon_eight);
	else if (all->dragon_frame == 9)
		ft_search_pix_in_sprite(all, all->sprite_dragon_nine);
	all->dragon_frame++;
	if (all->dragon_frame == 10)
	{
		ft_search_pix_in_sprite(all, all->sprite_dragon_ten);
		all->dragon_frame = 1;
	}
}

void		render_sprite(t_all *all)
{
	int	i;

	sort_sprites(all);
	i = -1;
	while (++i < all->numsprites)
	{
		ft_set_sprite_vars(all, i);
		ft_calc_sprite_ray(all);
		if (all->sprite[i].num == 2)
			ft_search_pix_in_sprite(all, all->sprite_two_img);
		else if (all->sprite[i].num == 3)
			ft_search_pix_in_sprite(all, all->sprite_three_img);
		else if (all->sprite[i].num == 4)
			ft_search_pix_in_sprite(all, all->sprite_four_img);
		else if (all->sprite[i].num == 5)
			ft_search_pix_in_sprite(all, all->sprite_five_img);
		else if (all->sprite[i].num == 6)
			ft_search_pix_in_sprite(all, all->sprite_six_img);
		else if (all->sprite[i].num == 7)
			ft_search_pix_in_sprite(all, all->sprite_seven_img);
		else if (all->sprite[i].num == 8)
			ft_search_pix_in_sprite(all, all->sprite_eight_img);
		else if (all->sprite[i].num == 9)
			render_dragon(all);
	}
}

int			render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0
//	floor_casting(all);
	raycast(all);
	render_life(all);
	all->weapon.x_start = 0;
	all->weapon.y_start = 0;
	all->weapon.x_end = 352;
	all->weapon.y_end = 93;
//	ft_render_weapon(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	ft_move_dragon(all);
	ft_control(all);
	return (0);
}
