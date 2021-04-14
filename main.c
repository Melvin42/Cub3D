#include "cub3d.h"

static void	set_all(t_all *all)
{
	*all = (t_all){NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL,
			(t_player){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_ray){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_texture){0, 0, 0, 0, 0, 0},
			NULL,
			(t_img){NULL, NULL, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0},
			(t_img){NULL, NULL, 0, 0, 0},
			(t_rgb){-1, -1, -1},
			(t_rgb){-1, -1, -1}};
}

int			check_resolution_value(t_all *all)
{
	if (all->rx == 0 || all->ry == 0)
		return (check_error(RES_ERROR));
	if (all->rx > INT_MAX || all->rx < 0)
			all->rx = INT_MAX;
	if (all->ry > INT_MAX || all->ry < 0)
			all->ry = INT_MAX;
	return (0);
}

void		rectify_resolution_value(t_all *all)
{
	int	resx;
	int	resy;

	mlx_get_screen_size(all->mlx_ptr, &resx, &resy);
	if (all->rx >= resx)
		all->rx = resx;
	if (all->ry >= resy)
		all->ry = resy;
}

int			ft_new_mlx_img(t_all *all, t_img *img, int res_x, int res_y)
{
	img->mlx_img = mlx_new_image(all->mlx_ptr, res_x, res_y);
	if (img->mlx_img == NULL)
		return (check_error(MLX_ERROR));
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
								&img->line_len, &img->endian);
	if (img->addr == NULL)
		return (check_error(MLX_ERROR));
	return (0);
}

int			ft_mlx_xpm_to_img(t_all *all, t_img *tex, char *path, int res_x, int res_y)
{
	tex->mlx_img = mlx_xpm_file_to_image(all->mlx_ptr, path, &res_x, &res_y);
	if (tex->mlx_img == NULL)
		return (check_error(MLX_ERROR));
	tex->addr = mlx_get_data_addr(tex->mlx_img, &tex->bpp,
								&tex->line_len, &tex->endian);
	if (tex->addr == NULL)
		return (check_error(MLX_ERROR));
	return (0);
}

int	ft_pars(t_all *all, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (check_error(fd));
	all->map_malloc_size = count_line(fd, all);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (read_file(fd, all) < 0)
	{
		close(fd);
//		free(all);
		return (-1);
	}
	close(fd);
	if (check_map(all) < 0)
	{
//		free(all);
		return (-1);
	}
	return (0);
}

int	ft_load_all_img(t_all *all)
{
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (-1);
	if (ft_mlx_xpm_to_img(all, &all->tex_n, all->north, TEXTURE_WIDTH, TEXTURE_HEIGHT) < 0)
		return (-1);
	if (ft_mlx_xpm_to_img(all, &all->tex_s, all->south, TEXTURE_WIDTH, TEXTURE_HEIGHT) < 0)
		return (-1);
	if (ft_mlx_xpm_to_img(all, &all->tex_e, all->east, TEXTURE_WIDTH, TEXTURE_HEIGHT) < 0)
		return (-1);
	if (ft_mlx_xpm_to_img(all, &all->tex_w, all->west, TEXTURE_WIDTH, TEXTURE_HEIGHT) < 0)
		return (-1);
	if (ft_mlx_xpm_to_img(all, &all->sprite_img, all->path_sprite, SPRITE_WIDTH, SPRITE_HEIGHT) < 0)
		return (-1);
	return (0);
}

int	ft_save(void)
{
	return (0);
}

void	ft_loop(t_all all)
{
	mlx_hook(all.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &all);
	mlx_loop(all.mlx_ptr);
}

int		ft_init_game(t_all *all)
{
	all->mlx_ptr = mlx_init();
	if (all->mlx_ptr == NULL)
		return (check_error(MLX_ERROR));
	rectify_resolution_value(all);
	all->win_ptr = mlx_new_window(all->mlx_ptr, all->rx, all->ry, "Cub3D");
	if (all->win_ptr == NULL)
	{
//		free(all->win_ptr);
		return (check_error(MLX_ERROR));
	}
	if (ft_load_all_img(all) < 0)
	{
//		free(all);
		return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_all	all;

	set_all(&all);
	if (ac < 2 && ac > 3)
		return (check_error(ARG_ERROR));
	if (ac == 3)
		return (ft_save());
	else
	{
		if (ft_pars(&all, av) < 0)
			return (0);
		pos_sprites(&all);
		check_resolution_value(&all);
		if (ft_init_game(&all) < 0)
			return (0);
		//system("aplay -c 2 -t wav -r 48000 ./bonus/trap.wav &");
		ft_loop(all);
	}
	return (0);
}
