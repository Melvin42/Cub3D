#include "cub3d.h"

void	set_all(t_all *all)
{
	*all = (t_all){NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL,
			(t_player){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_ray){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_texture){0, 0, 0, 0, 0, 0},
			(t_sprite){0, 0, 0},
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

int	main(int ac, char **av)
{
	int			fd;
	int			n;
	int			texture_width = TEXTURE_WIDTH;
	int			texture_height = TEXTURE_HEIGHT;
	int			sprite_width = SPRITE_WIDTH;
	int			sprite_height = SPRITE_HEIGHT;
	int			menu_width;
	int			menu_height;
	t_all		all;

	//mlx_get_screen_size taille de la fenetre  get_screen_size taille de l'ecran
	set_all(&all);
	if (ac != 2)
		return (check_error(ARG_ERROR));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (check_error(fd));
	n = count_line(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (read_file(n, fd, &all) < 0)
	{
		close(fd);
		free_all(&all);
		return (0);
	}
	close(fd);
	if (check_map(&all) < 0)
	{
		free_all(&all);
		return (0);
	}
	int	x, y;
	y = -1;
	while (all.map[++y])
	{
		x = -1;
		while (all.map[y][++x])
		{
			if (all.map[y][x] == '2')
			{
				all.sprite.x = (double)x;
				all.sprite.y = (double)y;
				//all.map[y][x] = '0';
			}
		}
	}
//	printf("x = %f\n", all.sprite.x);
//	printf("y = %f\n", all.sprite.y);
	all.mlx_ptr = mlx_init();
	if (all.mlx_ptr == NULL)
		return (check_error(MLX_ERROR));
	int	resx;
	int	resy;
	mlx_get_screen_size(all.mlx_ptr, &resx, &resy);
	if (all.rx > resx)
		all.rx = resx;
	if (all.ry > resy)
		all.ry = resy;

	all.win_ptr = mlx_new_window(all.mlx_ptr, all.rx, all.ry, "Cub3D");
	if (all.win_ptr == NULL)
	{
		free(all.win_ptr);
		return (check_error(MLX_ERROR));
	}
	menu_width = 418;
	menu_height = 402;
	all.menu.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, "./worldofwarcub.xpm", &menu_width, &menu_height);
	all.menu.addr = mlx_get_data_addr(all.menu.mlx_img, &all.menu.bpp,
					&all.menu.line_len, &all.menu.endian);
	menu(&all);
	all.img.mlx_img = mlx_new_image(all.mlx_ptr, all.rx, all.ry);
	all.img.addr = mlx_get_data_addr(all.img.mlx_img, &all.img.bpp,
					&all.img.line_len, &all.img.endian);
	
	all.tex_n.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.north, &texture_width, &texture_height);
	all.tex_n.addr = mlx_get_data_addr(all.tex_n.mlx_img, &all.tex_n.bpp,
					&all.tex_n.line_len, &all.tex_n.endian);
	all.tex_s.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.south, &texture_width, &texture_height);
	all.tex_s.addr = mlx_get_data_addr(all.tex_s.mlx_img, &all.tex_s.bpp,
					&all.tex_s.line_len, &all.tex_s.endian);
	all.tex_e.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.east, &texture_width, &texture_height);
	all.tex_e.addr = mlx_get_data_addr(all.tex_e.mlx_img, &all.tex_e.bpp,
					&all.tex_e.line_len, &all.tex_e.endian);
	all.tex_w.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.west, &texture_width, &texture_height);
	all.tex_w.addr = mlx_get_data_addr(all.tex_w.mlx_img, &all.tex_w.bpp,
					&all.tex_w.line_len, &all.tex_w.endian);
	all.sprite_img.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.path_sprite, &sprite_width, &sprite_height);
	all.sprite_img.addr = mlx_get_data_addr(all.sprite_img.mlx_img, &all.sprite_img.bpp,
					&all.sprite_img.line_len, &all.sprite_img.endian);
	render_background(&all.img, &all, BLACK_PIXEL);
	mlx_hook(all.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &all);
	mlx_loop(all.mlx_ptr);
	return (0);
}
