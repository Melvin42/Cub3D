/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:40 by melperri          #+#    #+#             */
/*   Updated: 2021/04/28 10:02:46 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_set_raycast_vars(t_all *all)
{
	all->player.raydirx = all->player.dirx + all->player.planx
						* all->player.camerax;
	all->player.raydiry = all->player.diry + all->player.plany
						* all->player.camerax;
	all->ray.map_x = (int)(all->player.posx);
	all->ray.map_y = (int)(all->player.posy);
	all->ray.delta_dist_x = fabs(1.0 / all->player.raydirx);
	all->ray.delta_dist_y = fabs(1.0 / all->player.raydiry);
	all->ray.hit = 0;
}

void	render_sprite(t_all *all)
{
	int	i;

	ft_calc_sprite_dist(all);
	sort_sprites(all);
	i = -1;
	while (++i < all->numsprites)
	{
		ft_set_sprite_vars(all, i);
		ft_calc_sprite_ray(all);
		if (all->sprite[i].num == 2)
		{
			ft_search_pix_in_sprite(all, all->sprite_two_img);
		}
		else if (all->sprite[i].num == 3)
		{
			ft_search_pix_in_sprite(all, all->sprite_three_img);
		}
		else if (all->sprite[i].num == 4)
		{
			ft_search_pix_in_sprite(all, all->sprite_four_img);
		}
		else if (all->sprite[i].num == 5)
		{
			ft_search_pix_in_sprite(all, all->sprite_five_img);
		}
		else if (all->sprite[i].num == 6)
		{
			ft_search_pix_in_sprite(all, all->sprite_six_img);
		}
		else if (all->sprite[i].num == 7)
		{
			ft_search_pix_in_sprite(all, all->sprite_seven_img);
		}
		else if (all->sprite[i].num == 8)
		{
			ft_search_pix_in_sprite(all, all->sprite_eight_img);
		}
		else if (all->sprite[i].num == 9)
		{
			if (all->dragon_frame == 1)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_one);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 2)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_two);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 3)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_three);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 4)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_four);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 5)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_five);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 6)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_six);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 7)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_seven);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 8)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_eight);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 9)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_nine);
				all->dragon_frame++;
			}
			else if (all->dragon_frame == 10)
			{
				ft_search_pix_in_sprite(all, all->sprite_dragon_ten);
				all->dragon_frame = 1;
			}
		}
	}
}

void	ft_chose_tex(t_all *all)
{
	if (all->ray.hit == 1)
	{
		if (all->ray.side == 0 && all->ray.step_x == -1)
		{
			all->tex_width = all->tex_e.res_x;
			all->tex_height = all->tex_e.res_y;
		}
		else if (all->ray.side == 0 && all->ray.step_x == 1)
		{
			all->tex_width = all->tex_w.res_x;
			all->tex_height = all->tex_w.res_y;
		}
		else if (all->ray.side == 1 && all->ray.step_y == -1)
		{
			all->tex_width = all->tex_s.res_x;
			all->tex_height = all->tex_s.res_y;
		}
		else if (all->ray.side == 1 && all->ray.step_y == 1)
		{
			all->tex_width = all->tex_n.res_x;
			all->tex_height = all->tex_n.res_y;
		}
	}
}

void	ft_render_side(t_all *all, int x)
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

int		render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	render_background(all);
	raycast(all);
	render_life(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	char hp[5];

	if (all->player.hp == 100)
	{
		hp[0] = '1';
		hp[1] = '0';
		hp[2] = '0';
		hp[3] = '%';
		hp[4] = '\0';
	}
	else
	{
		hp[0] = ' ';
		hp[1] = all->player.hp / 10 + 48;
		hp[2] = all->player.hp % 10 + 48;
		hp[3] = '%';
		hp[4] = '\0';
	}
	mlx_string_put(all->mlx_ptr, all->win_ptr, all->rx / 2, 25, 0XFFFFFF, hp);
	usleep(85000);
	return (0);
}