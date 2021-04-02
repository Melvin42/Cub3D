#include "cub3d.h"

void	set_all(t_all *all)
{
	*all = (t_all){NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL,
			(t_player){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_raycast){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			(t_texture){0, 0, 0, 0, 0, 0},
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
	t_all		all;

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
	all.mlx_ptr = mlx_init();
	if (all.mlx_ptr == NULL)
		return (check_error(MLX_ERROR));
	all.win_ptr = mlx_new_window(all.mlx_ptr, all.rx, all.ry, "Cub3D");
	if (all.win_ptr == NULL)
	{
		free(all.win_ptr);
		return (check_error(MLX_ERROR));
	}
	menu(&all);
	all.img.mlx_img = mlx_new_image(all.mlx_ptr, all.rx, all.ry);
	all.img.addr = mlx_get_data_addr(all.img.mlx_img, &all.img.bpp,
					&all.img.line_len, &all.img.endian);
	
	all.tex_n.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.south, &texture_width, &texture_height);
	all.tex_n.addr = mlx_get_data_addr(all.tex_n.mlx_img, &all.tex_n.bpp,
					&all.tex_n.line_len, &all.tex_n.endian);
	all.tex_s.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.south, &texture_width, &texture_height);
	all.tex_s.addr = mlx_get_data_addr(all.tex_s.mlx_img, &all.tex_s.bpp,
					&all.tex_s.line_len, &all.tex_s.endian);
	all.tex_e.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.south, &texture_width, &texture_height);
	all.tex_e.addr = mlx_get_data_addr(all.tex_e.mlx_img, &all.tex_e.bpp,
					&all.tex_e.line_len, &all.tex_e.endian);
	all.tex_w.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, all.south, &texture_width, &texture_height);
	all.tex_w.addr = mlx_get_data_addr(all.tex_w.mlx_img, &all.tex_w.bpp,
					&all.tex_w.line_len, &all.tex_w.endian);
	render_background(&all.img, &all, BLACK_PIXEL);
	mlx_hook(all.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &all);
	mlx_loop(all.mlx_ptr);
	return (0);
}
