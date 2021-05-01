/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:40 by melperri          #+#    #+#             */
/*   Updated: 2021/04/30 20:37:17 by melperri         ###   ########.fr       */
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

	i = i * 4;
	j = j * 4;
	y = i;
	while (y < i + 4)
	{
		x = j;
		while (x < j + 4)
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
	while (++h < all->map_height * 4)
	{
		k = 0;
		while (k < all->map_width_max * 4)
			img_pix_put(&all->mini_map, k++, h, YELLOW_PIXEL);
	}
	i = 0;
	while (i < all->map_height)
	{
		j = 0;

		while (j < all->map_width_max)
		{
			if (all->map[i][j] == '1')
				render_mini_map_pix(all, j, i, GREY_PIXEL);
			else if (all->map[i][j] >= '2' && all->map[i][j] <= '8')
				render_mini_map_pix(all, j, i, WHITE_PIXEL);
			else
				render_mini_map_pix(all, j, i, BLACK_PIXEL);
			j++;
			int	d = -1;
			while (++d < all->numsprites)
				if (all->sprite[d].num == 9)
					render_mini_map_pix(all, (int)(all->sprite[d].x), (int)(all->sprite[d].y), RED_PIXEL);
			render_mini_map_pix(all, (int)(all->player.posx), (int)(all->player.posy), GREEN_PIXEL);
		}
		++i;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->mini_map.mlx_img, 0, 0);
}

static int	render_axe_pix(t_all *all, int j, int i, int color, t_weapon axe)
{
	int	x;
	int	y;

	i = i * 3;
	j = j * 3;
	y = i;
	while (y < i + 3)
	{
		x = j;
		while (x < j + 3)
		{
			if ((color & 0x00FFFFFF) != 0)
				img_pix_put(&all->img, all->rx / 2 + (axe.x_end - axe.x_start) * 3 + x, all->ry - (axe.y_end - axe.y_start) * 3 + y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_weapon(t_all *all, t_weapon axe)
{
	int	y;
	int	x;
	int	color;

	y = axe.y_start;
	while (y < axe.y_end)
	{
		x = axe.x_start;
		while (x < axe.x_end)
		{
	  		color = *((int *)all->sprite_axe.addr + (x + y * 626));
			render_axe_pix(all, x - axe.x_start, y - axe.y_start, color, axe);
	  		x++;
		}
		y++;
	}
	return (0);
}

int		ft_weapon_attack(t_all *all)
{
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	render_background(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){368, 104, 516, 304});
	ft_move_dragon(all);
	ft_control(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);

	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	render_background(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){258, 104, 368, 304});
	ft_move_dragon(all);
	ft_control(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);

	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	render_background(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){186, 104, 258, 304});
	ft_move_dragon(all);
	ft_control(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);

	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	render_background(all);
	floor_casting(all);
	raycast(all);
	render_life(all);
	ft_weapon(all, (t_weapon){135, 104, 186, 304});
	ft_move_dragon(all);
	ft_control(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);

	ft_player_attack(all);
	return (0);
}

void	floor_casting(t_all *all)
{
	int	y;
	int	x;
	float raydirx0;
	float raydiry0;
	float raydirx1;
	float raydiry1;
	int	p;
	float posz;
	float rowdistance;
	float floorstepx;
	float floorstepy;
	float floorx;
	float floory;
	int cellx;
	int celly;
	int tx;
	int ty;
	int	color;

	y = all->ry / 2;
	while (y < all->ry)
	{
		raydirx0 = all->player.dirx - all->player.planx;
		raydiry0 = all->player.diry - all->player.plany;
		raydirx1 = all->player.dirx + all->player.planx;
		raydiry1 = all->player.diry + all->player.plany;
		p = y - all->ry / 2;
		posz = 0.5 * all->ry;
		rowdistance = posz / p;
		floorstepx = rowdistance * (raydirx1 - raydirx0) / all->rx;
		floorstepy = rowdistance * (raydiry1 - raydiry0) / all->rx;
		floorx = all->player.posx + rowdistance * raydirx0;
		floory = all->player.posy + rowdistance * raydiry0;
		x = 0;
		while (x < all->rx)
		{
			cellx = (int)floorx;
			celly = (int)floory;
			tx = (int)(all->tex_floor.res_x * (floorx - cellx)) & (all->tex_floor.res_x - 1);
			ty = (int)(all->tex_floor.res_y * (floory - celly)) & (all->tex_floor.res_y - 1);
			floorx += floorstepx;
			floory += floorstepy;
			color = *((int *)all->tex_floor.addr + (all->tex_floor.res_x * ty + tx));
			img_pix_put(&all->img, x, y, color);
			x++;
		}
		y++;
	}

}

int		ft_img_scale(t_img *dst, t_img *src)
{
	int	x;
	int	y;
	int	color;
	double	target_x;
	double	target_y;

	y = -1;
	while (++y < (int)dst->res_y)
	{
		x = -1;
		while (++x < (int)dst->res_x)
		{
			target_x = ((double)x / (double)dst->res_x * (double)src->res_x);
			target_y = ((double)y / (double)dst->res_y * (double)src->res_y);
			target_x = floor(target_x);
			target_y = floor(target_y);
			color = *((int *)src->addr + ((int)target_x + (int)target_y * src->res_x));
			img_pix_put(dst, x, y, color);
		}
	}
	return (0);
}

void	ft_skybox(t_all *all)
{
	int	x;
	int	y;
	int	color;

//	float res_x = 2 * all->map_width_max + 2 * all->map_height;
	//double res_x = all->rx * 8;
	int res_x = all->rx;// * (2 * all->map_width_max + 2 * all->map_height);
	int res_y = (all->ry / 2);
	double	target_x;
	double	target_y;
	y = -1;
	while (++y < all->ry / 2)
	{
		x = -1;
		while (++x < all->rx)
		{
			target_x = ((double)x / (double)res_x * (double)all->skybox_scale.res_x);
			target_y = ((double)y / (double)res_y * (double)all->skybox_scale.res_y);
			target_x = floor(target_x);
			target_y = floor(target_y);
			color = *((int *)all->skybox_scale.addr + ((int)target_x + (int)target_y * all->skybox_scale.res_x));
			img_pix_put(&all->img, x, y, color);
		}
	}
}

int		render(t_all *all)
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
	ft_weapon(all, (t_weapon){0, 0, 352, 93});
	ft_move_dragon(all);
	ft_control(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	ft_mini_map(all);
	ft_put_string_life(all);
	return (0);
}
