#include "../inc/cub3d.h"

static void	ft_escape(t_all *all)
{
//	system("pkill -9 aplay");
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
