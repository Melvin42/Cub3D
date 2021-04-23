#include "../cub3d.h"

system("aplay -c 2 -t wav -r 48000 ./bonus/trap.wav &"); // dans le main avant render
system("pkill -p aplay");// dans ft_escape et exit_cross

int	menu(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->menu.mlx_img, ((all->rx / 2) - (418 / 2)), 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 2) / 10)),
			all->ry / 2, WHITE_PIXEL, "WELCOME TO THE WORLD OF WARCUB!!!");
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 8) / 10)),
			(all->ry / 2 + ((all->ry / 2) / 8)), WHITE_PIXEL, "PRESS ENTER");
	return (0);
}

/*
**	int			menu_width;
**	int			menu_height;
**	menu_width = 418;
**	menu_height = 402;
**	all.menu.mlx_img = mlx_xpm_file_to_image(all.mlx_ptr, "./worldofwarcub.xpm", &menu_width, &menu_height);
**	all.menu.addr = mlx_get_data_addr(all.menu.mlx_img, &all.menu.bpp,
**					&all.menu.line_len, &all.menu.endian);
**	menu(&all);
*/

//	mlx_mouse_hide(all.mlx_ptr, all.win_ptr);

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
/*
	ORDRE DAFFICHAGE

	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
	render_background(&all->img, all, BLACK_PIXEL);
	raycast(all);
	render_life(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, all->rx / 2, 25, WHITE_PIXEL, "100%");
*/
