/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:29:15 by melperri          #+#    #+#             */
/*   Updated: 2021/05/20 00:08:47 by melperri         ###   ########.fr       */
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
	if (all->tex_floor.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->tex_floor.mlx_img);
	if (all->tex_skybox.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->tex_skybox.mlx_img);
	if (all->skybox_scale.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->skybox_scale.mlx_img);
	if (all->menu.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->menu.mlx_img);
	if (all->menu_scale.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->menu_scale.mlx_img);
	if (all->sprite_axe.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->sprite_axe.mlx_img);
	if (all->mini_map.mlx_img)
		mlx_destroy_image(all->mlx_ptr, all->mini_map.mlx_img);
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
	all->north = NULL;
	free(all->south);
	all->south = NULL;
	free(all->west);
	all->west = NULL;
	free(all->east);
	all->east = NULL;
	free(all->path_two);
	all->path_two = NULL;
	free(all->path_three);
	all->path_three = NULL;
	free(all->path_four);
	all->path_four = NULL;
	free(all->path_five);
	all->path_five = NULL;
	free(all->path_six);
	all->path_six = NULL;
	free(all->path_seven);
	all->path_seven = NULL;
	free(all->path_eight);
	all->path_eight = NULL;
	free(all->path_nine);
	all->path_nine = NULL;
	free(all->skybox);
	all->skybox = NULL;
	free(all->floor);
	all->floor = NULL;
}

void		ft_free_all(t_all *all)
{
	ft_free_path(all);
	free(all->zbuffer);
	all->zbuffer = NULL;
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

void		ft_free_to_go_next_lvl(t_all *all)
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

int			ft_load_next_lvl(t_all *all)
{
	char **av;

	all->flag_map = 0;
	all->index = 0;
	all->map_malloc_size = 0;
	all->map_width_max = 0;
	all->map_height = 0;
	all->player.flag = 0;
	if (!(av = malloc(sizeof(char *) * 3)))
		return (-1);
	ft_memset(av, 0, sizeof(**av));
	if (!(av[1] = malloc(sizeof(char) * 18)))
		return (-1);
	ft_strcpy(av[1], "./maps/dragon.cub");
	main(2, av);
	free(av[1]); //free dans fonction free et mettre dans structure pour ca
	free(av);
	return (0);
}
