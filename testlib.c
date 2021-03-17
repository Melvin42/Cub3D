#include <stdlib.h>
#include <mlx.h>

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Cub3D");
	int	i;

	i = 0;
	while (i < 500)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, 30, 200);
		i++;
	}
	mlx_string_put(mlx_ptr, win_ptr, 25, 25, 255, "HELLO");

//	mlx_new_image();
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
