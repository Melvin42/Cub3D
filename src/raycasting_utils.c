#include "../inc/cub3d.h"

void	sort_sprites(t_all *all)
{
	int			i;
	int			j;
	t_sprite	swap;

	i = 0;
	while (i < all->numsprites)
	{
		j = i + 1;
		while (j < all->numsprites)
		{
			if (all->sprite[i].dist < all->sprite[j].dist)
			{
				swap = all->sprite[i];
				all->sprite[i] = all->sprite[j];
				all->sprite[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int		render(t_all *all)
{
	if (all->win_ptr == NULL)// mettre le bon retour d'erreur
		return (1);
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (1);
	render_background(&all->img, all, BLACK_PIXEL);
	raycast(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	return (0);
}
