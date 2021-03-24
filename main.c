#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_param	param;
	int		n;

	param = (t_param){0, 0, NULL, NULL, NULL, NULL, NULL,
			(t_rgb){-1, -1, -1}, (t_rgb){-1, -1, -1}, NULL};
	if (ac != 2)
		return (check_error(ARG_ERROR));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (check_error(fd));
	n = count_line(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (read_file(n, fd, &param) < 0)
	{
		close(fd);
		free_param(&param);
		return (0);
	}
	if (check_map(&param) < 0)
	{
		close(fd);
		free_param(&param);
		return (0);
	}
	close(fd);

	printf("rx = %15d\n", param.rx);
	printf("ry = %15d\n", param.ry);
	printf("north = %35s\n", param.north);
	printf("south = %35s\n", param.south);
	printf("west = %35s\n", param.west);
	printf("east = %35s\n", param.east);
	printf("sprite = %35s\n", param.sprite);
	printf("floor red = %7d\n", param.floor.red);
	printf("floor green = %5d\n", param.floor.green);
	printf("floor blue = %4d\n", param.floor.blue);
	printf("ceiling red = %5d\n", param.ceiling.red);
	printf("ceiling green = %d\n", param.ceiling.green);
	printf("ceiling blue = %2d\n", param.ceiling.blue);
	int i = -1;
	while (param.map[++i])
		printf("map = %s\n", param.map[i]);
	printf("map = %s\n", param.map[i]);
	free_param(&param);
	return (0);
}
