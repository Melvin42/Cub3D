#include "cub3d.h"

int	ft_init_save(t_all *all)
{
	all->mlx_ptr = mlx_init();
	if (all->mlx_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	if (ft_load_all_img(all) < 0)
		return (-1);
	return (0);
}

int		ft_render_save(t_all *all)
{
	if (all->win_ptr == NULL)// mettre le bon retour d'erreur
		return (-1);
//	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (-1);
	render_background(&all->img, all, BLACK_PIXEL);
	raycast(all);
	return (0);
}

int	ft_save(t_all *all, char **av)
{
	int	fd;

	if (ft_pars(all, av) < 0)
		return (-1);
	pos_sprites(all);
	if (all->rx <= 0 || all->ry <= 0)
		return (check_error(all, RES_ERROR));
	ft_init_save(all);
	ft_render_save(all);
	fd = open("save.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
//	write(fd, "BM\n", 3);
	int	i;
	int j;
	
	i = 0;
	j = -1;
	while (++j < all->rx)
	{
		//write(fd, (int *)all->img.addr)[i]), 1);
		i += 4;
	}

	
	return (0);

}
