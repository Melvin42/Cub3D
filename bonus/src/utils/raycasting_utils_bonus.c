/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:40 by melperri          #+#    #+#             */
/*   Updated: 2021/04/28 18:20:34 by melperri         ###   ########.fr       */
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

void	ft_move_dragon(t_all *all)
{
	int	i = -1;
	while (++i < all->numsprites)
	{
		if (all->sprite[i].num == 9)
		{
			if (all->player.posy < all->sprite[i].y)
				all->sprite[i].y -= 0.1;
			else if (all->player.posy > all->sprite[i].y)
				all->sprite[i].y += 0.1;
			if (all->player.posx < all->sprite[i].x)
				all->sprite[i].x -= 0.1;
			else if (all->player.posx > all->sprite[i].x)
				all->sprite[i].x += 0.1;
		}
	}
	ft_damage(all);
}

void	ft_put_string_life(t_all *all)
{
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
}

void	render_mini_map_pix(t_all *all, int j, int i, int color)
{
	int	x;
	int	y;

	int	k;
	int	l;
	k = i + (((all->ry / 2 - all->ry / 3)) / all->map_height);
	l = j + (((all->rx / 2 - all->rx / 3)) / all->map_width_max);
	y = i;
	while (y < i + k)
	{
		x = j;
		while (x < j + l)
		{
			img_pix_put(&all->mini_map, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_mini_map(t_all *all)
{
	int	i;
	int	j;

	int	h;
	int k;
	h = -1;
	while (++h < all->ry / 2 - all->ry / 3)
	{
		k = 0;
		while (k < all->rx / 2 - all->rx / 3)
			img_pix_put(&all->mini_map, k++, h, YELLOW_PIXEL);
	}
	i = 0;
	while (i < all->map_height)
	{
		j = 0;

		while (j < all->map_width_max)
		{
			if (all->map[i][j] == '1')
			{
				//img_pix_put(&all->mini_map, j, i, WHITE_PIXEL);
				render_mini_map_pix(all, j, i, WHITE_PIXEL);
			}
			else if (all->map[i][j] >= '2' && all->map[i][j] <= '8')
			{
				//img_pix_put(&all->mini_map, j, i, BLACK_PIXEL);
				render_mini_map_pix(all, j, i, BLACK_PIXEL);
			}
			else
			{
				//img_pix_put(&all->mini_map, j, i, GREY_PIXEL);
				render_mini_map_pix(all, j, i, GREY_PIXEL);
			}
			j++;
			int	d = -1;
			while (++d < all->numsprites)
			{
				if (all->sprite[d].num == 9)
					render_mini_map_pix(all, (int)(all->sprite[d].x + 0.5), (int)(all->sprite[d].y + 0.5), RED_PIXEL);
					//img_pix_put(&all->mini_map, (int)all->sprite[d].x, (int)all->sprite[d].y, RED_PIXEL);
			}
			//img_pix_put(&all->mini_map, (int)all->player.posx, (int)all->player.posy, GREEN_PIXEL);
			render_mini_map_pix(all,  (int)(all->player.posx + 0.5), (int)(all->player.posy + 0.5), GREEN_PIXEL);
		}
		++i;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->mini_map.mlx_img, 0, 0);
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
	ft_mini_map(all);
	ft_put_string_life(all);
	usleep(85000);
	ft_move_dragon(all);
	return (0);
}
