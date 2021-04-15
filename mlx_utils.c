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
