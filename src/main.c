#include "../inc/cub3d.h"

static void	set_all(t_all *all)
{
	*all = (t_all){NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0, 0,
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

int	ft_pars(t_all *all, char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (check_error(all, fd));
	all->map_malloc_size = count_line(fd, all);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (read_file(fd, all) < 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (!all->map)
		return (check_error(all, FOLDER_ERROR));
	if (check_map(all) < 0)
		return (-1);
	if (is_map_open(all) < 0)
		return (-1);
	replace_space_by_one(all);
	return (0);
}

int	ft_exit_cross(t_all *all)
{
	ft_free_all(all);
	exit(0);
	return (0);
}
void	ft_loop(t_all all)
{
	mlx_hook(all.win_ptr, ClientMessage, StructureNotifyMask, &ft_exit_cross, &all);
	mlx_hook(all.win_ptr, FocusIn, FocusChangeMask, &render, &all);
	mlx_hook(all.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &all);
	mlx_loop(all.mlx_ptr);
}

int		ft_init_game(t_all *all)
{
	all->mlx_ptr = mlx_init();
	if (all->mlx_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	rectify_resolution_value(all);
	all->win_ptr = mlx_new_window(all->mlx_ptr, all->rx, all->ry, "Cub3D");
	if (all->win_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	if (ft_load_all_img(all) < 0)
		return (-1);
	return (0);
}

int		check_map_name(t_all *all, char *arg)
{
	size_t	i;

	i = ft_strlen((const char *)arg);
	if (i < 4)
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != 'b')
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != 'u')
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != 'c')
		return (check_error(all, NAME_ERROR));
	if (arg[--i] != '.')
		return (check_error(all, NAME_ERROR));
	return (0);
}

int		check_xpm_path(t_all *all, char *path)
{
	size_t	i;

	i = ft_strlen((const char *)path);
	if (i < 4)
		return (check_error(all, PATH_ERROR));
	if (path[--i] != 'm')
		return (check_error(all, PATH_ERROR));
	if (path[--i] != 'p')
		return (check_error(all, PATH_ERROR));
	if (path[--i] != 'x')
		return (check_error(all, PATH_ERROR));
	if (path[--i] != '.')
		return (check_error(all, PATH_ERROR));
	return (0);
}

int		main(int ac, char **av)
{
	t_all	all;

	set_all(&all);
	if (ac < 2 && ac > 3)
		return (check_error(&all, ARG_ERROR));
	if (check_map_name(&all, av[1]) < 0)
		return (0);
	if (ft_pars(&all, av) < 0)
		return (0);
	if (pos_sprites(&all) < 0)
		return (0);
	if (check_rgb(&all) < 0)
		return (0);
	all.floor_color = encode_rgb(all.floor.red, all.floor.green, all.floor.blue);
	all.ceiling_color = encode_rgb(all.ceiling.red, all.ceiling.green, all.ceiling.blue);
	if (check_resolution_value(&all) < 0)
		return (0);
	if (all.player.flag == 0)
		return (check_error(&all, NO_PLAYER_ERROR));
	if (ac == 3)
		return (ft_save(&all));
	else
	{
		if (ft_init_game(&all) < 0)
			return (0);
	//	system("aplay -c 2 -t wav -r 48000 ./bonus/trap.wav &");
		render(&all);
		ft_loop(all);
	}
	return (0);
}
