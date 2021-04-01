#include "cub3d.h"

void	set_data(t_data *data)
{
	*data = (t_data){NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL,
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
	t_data		data;

	set_data(&data);
	if (ac != 2)
		return (check_error(ARG_ERROR));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (check_error(fd));
	n = count_line(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (read_file(n, fd, &data) < 0)
	{
		close(fd);
		free_data(&data);
		return (0);
	}
	close(fd);
	if (check_map(&data) < 0)
	{
		free_data(&data);
		return (0);
	}
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (check_error(MLX_ERROR));
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.rx, data.ry, "Cub3D");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (check_error(MLX_ERROR));
	}
	menu(&data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.rx, data.ry);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
					&data.img.line_len, &data.img.endian);
	
	data.tex_n.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.south, &texture_width, &texture_height);
	data.tex_n.addr = mlx_get_data_addr(data.tex_n.mlx_img, &data.tex_n.bpp,
					&data.tex_n.line_len, &data.tex_n.endian);
	data.tex_s.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.south, &texture_width, &texture_height);
	data.tex_s.addr = mlx_get_data_addr(data.tex_s.mlx_img, &data.tex_s.bpp,
					&data.tex_s.line_len, &data.tex_s.endian);
	data.tex_e.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.south, &texture_width, &texture_height);
	data.tex_e.addr = mlx_get_data_addr(data.tex_e.mlx_img, &data.tex_e.bpp,
					&data.tex_e.line_len, &data.tex_e.endian);
	data.tex_w.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.south, &texture_width, &texture_height);
	data.tex_w.addr = mlx_get_data_addr(data.tex_w.mlx_img, &data.tex_w.bpp,
					&data.tex_w.line_len, &data.tex_w.endian);
	render_background(&data.img, &data, BLACK_PIXEL);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
