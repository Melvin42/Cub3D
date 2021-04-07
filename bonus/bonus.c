#include "../cub3d.h"

int		render_life(t_all *all)
{
	int	drawstart;
	int	drawend;
	int	x;
	int	y;

	if (all->win_ptr == NULL)
		return (1);
	drawstart = (all->ry / 2);
	drawend = (all->ry / 2) + (all->ry / 3);
	y = 10;
	x = drawstart - 1;
	while (x < drawend + 1)
		img_pix_put(&all->img, x++, y - 1, WHITE_PIXEL);
	while (y <= 30)
	{
		x = drawstart - 1;
		img_pix_put(&all->img, x, y, WHITE_PIXEL);
		x++;
		while (x < drawend)
		{
			img_pix_put(&all->img, x++, y, RED_PIXEL);
		}
		img_pix_put(&all->img, x, y, WHITE_PIXEL);
		y++;
	}
	x = drawstart - 1;
	while (x < drawend + 1)
		img_pix_put(&all->img, x++, y, WHITE_PIXEL);
	return (0);
}
