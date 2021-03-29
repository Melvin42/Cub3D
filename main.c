#include "cub3d.h"

int	main(int ac, char **av)
{
	int			fd;
	int			n;
	t_data		data;

	data = (t_data){NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL,
			(t_player){0, 0, 0, 0, 0, 0, 0.66, 0, 0, 0, 0, 0}, (t_img){NULL, NULL, 0, 0, 0},
			(t_rgb){-1, -1, -1}, (t_rgb){-1, -1, -1}};
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
/*
	printf("rx = %15d\n", data.rx);
	printf("ry = %15d\n", data.ry);
	printf("north = %35s\n", data.north);
	printf("south = %35s\n", data.south);
	printf("west = %35s\n", data.west);
	printf("east = %35s\n", data.east);
	printf("sprite = %35s\n", data.sprite);
	printf("floor red = %7d\n", data.floor.red);
	printf("floor green = %5d\n", data.floor.green);
	printf("floor blue = %4d\n", data.floor.blue);
	printf("ceiling red = %5d\n", data.ceiling.red);
	printf("ceiling green = %d\n", data.ceiling.green);
	printf("ceiling blue = %2d\n", data.ceiling.blue);
	int i = -1;
	while (data.map[++i])
		printf("map = %s\n", data.map[i]);
	printf("map = %s\n", data.map[i]);
	printf("posx = %f\n", data.player.posx);
	printf("posy = %f\n", data.player.posy);
	printf("dirx = %f\n", data.player.dirx);
	printf("diry = %f\n", data.player.diry);
*/	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (check_error(MLX_ERROR));
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.rx, data.ry, "Cub3D");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (check_error(MLX_ERROR));
	}
//	menu(&data);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.rx, data.ry);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
					&data.img.line_len, &data.img.endian);
	render_background(&data.img, &data, BLACK_PIXEL);
	raycast(&data);
//	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
