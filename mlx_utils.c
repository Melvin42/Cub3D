#include "cub3d.h"

int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	render_background(t_img *img, t_all *all, int color)
{
	int	i;
	int	j;

	(void)color;
	i = 0;
	while (i < all->ry / 2)
	{
		j = 0;
		while (j < all->rx)
			img_pix_put(img, j++, i, BLACK_PIXEL);
		++i;
	}
	while (i < all->ry)
	{
		j = 0;
		while (j < all->rx)
			img_pix_put(img, j++, i, GREY_PIXEL);
		++i;
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
