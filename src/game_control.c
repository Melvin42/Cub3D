#include "../inc/cub3d.h"

static void	ft_escape(t_all *all)
{
	system("pkill -9 aplay");
	mlx_destroy_image(all->mlx_ptr, all->tex_n.mlx_img);
	mlx_destroy_image(all->mlx_ptr, all->tex_s.mlx_img);
	mlx_destroy_image(all->mlx_ptr, all->tex_e.mlx_img);
	mlx_destroy_image(all->mlx_ptr, all->tex_w.mlx_img);
	mlx_destroy_image(all->mlx_ptr, all->sprite_img.mlx_img);
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	mlx_destroy_window(all->mlx_ptr, all->win_ptr);
	mlx_destroy_display(all->mlx_ptr);
	ft_free_all(all);
	exit(SUCCESS);
}

int			handle_keypress(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
		ft_escape(all);
	else if (keysym == XK_Up || keysym == XK_w)
		move_up(all);
	else if (keysym == XK_Down || keysym == XK_s)
		move_down(all);
	else if (keysym == XK_a)
		move_left(all);
	else if (keysym == XK_d)
		move_right(all);
	else if (keysym == XK_Left || keysym == XK_q)
		rotate_left(all);
	else if (keysym == XK_Right || keysym == XK_e)
		rotate_right(all);
	render(all);
	return (0);
}
