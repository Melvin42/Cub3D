/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:28:49 by melperri          #+#    #+#             */
/*   Updated: 2021/04/22 19:29:07 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_error(t_all *all, int error)
{
	ft_free_all(all);
	if (error == NO_PLAYER_ERROR)
	{
		write(1, STR_NO_PLAYER_ERROR, ft_strlen(STR_NO_PLAYER_ERROR));
		return (0);
	}
	else if (error == MALLOC_ERROR)
	{
		write(1, STR_MALLOC_ERROR, ft_strlen(STR_MALLOC_ERROR));
		return (-1);
	}
	else if (error == ARG_ERROR)
	{
		write(1, STR_ARG_ERROR, ft_strlen(STR_ARG_ERROR));
		return (-1);
	}
	else if (error == FD_ERROR)
	{
		write(1, STR_FD_ERROR, ft_strlen(STR_FD_ERROR));
		return (-1);
	}
	else if (error == PARS_ERROR)
	{
		write(1, STR_PARS_ERROR, ft_strlen(STR_PARS_ERROR));
		return (-1);
	}
	else if (error == MLX_ERROR)
	{
		write(1, STR_MLX_ERROR, ft_strlen(STR_MLX_ERROR));
		return (-1);
	}
	else if (error == FOLDER_ERROR)
	{
		write(1, STR_FOLDER_ERROR, ft_strlen(STR_FOLDER_ERROR));
		return (-1);
	}
	else if (error == MAP_ERROR)
	{
		write(1, STR_MAP_ERROR, ft_strlen(STR_MAP_ERROR));
		return (-1);
	}
	else if (error == RES_ERROR)
	{
		write(1, STR_RES_ERROR, ft_strlen(STR_RES_ERROR));
		return (-1);
	}
	else if (error == NAME_ERROR)
	{
		write(1, STR_NAME_ERROR, ft_strlen(STR_NAME_ERROR));
		return (-1);
	}
	else if (error == SAVE_ERROR)
	{
		write(1, STR_SAVE_ERROR, ft_strlen(STR_SAVE_ERROR));
		return (-1);
	}
	else if (error == PATH_ERROR)
	{
		write(1, STR_PATH_ERROR, ft_strlen(STR_PATH_ERROR));
		return (-1);
	}
	else if (error == EMPTY_LINE_ERROR)
	{
		write(1, STR_EMPTY_LINE_ERROR, ft_strlen(STR_EMPTY_LINE_ERROR));
		return (-1);
	}
	else
		return (0);
}

void	ft_free_all(t_all *all)
{
	if (all->north)
		free(all->north);
	if (all->south)
		free(all->south);
	if (all->west)
		free(all->west);
	if (all->east)
		free(all->east);
	if (all->path_sprite)
		free(all->path_sprite);
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
			if (all->sprite_img.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->sprite_img.mlx_img);
			if (all->img.mlx_img)
				mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
			mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		}
		mlx_destroy_display(all->mlx_ptr);
		free(all->mlx_ptr);
	}
}
