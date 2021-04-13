#include "cub3d.h"

void	ft_debug(t_all *all)
{
	//printf("\n\n\nplayer struc pos x = %f\n", all->player.posx);
	//printf("player struc pos x  = %f\n", all->player.posx);
	//printf("player struc pos y  = %f\n", all->player.posy);
	//printf("player struc dir x = %f\n", all->player.dirx);
	//printf("player struc dir y = %f\n", all->player.diry);
	//printf("player struc plan x = %f\n", all->player.planx);
	//printf("player struc plan y = %f\n", all->player.plany);
	//printf("player struc camera = %f\n", all->player.camerax);
	//printf("player struc raydirx = %f\n", all->player.raydirx);
	//printf("player struc raydiry = %f\n", all->player.raydiry);
	//printf("ray struc delta dist x = %f\n", all->ray.delta_dist_x);
	//printf("ray struc delta dist y = %f\n", all->ray.delta_dist_y);
	//printf("ray struc side dist x = %f\n", all->ray.side_dist_x);
	//printf("ray struc side dist y = %f\n", all->ray.side_dist_y);
	//printf("ray struc perpwalldist = %f\n", all->ray.perpwalldist);
	//printf("ray struc step = %f\n", all->ray.step);
	//printf("ray struc step x = %d\n", all->ray.step_y);
	//printf("ray struc step y = %d\n", all->ray.step_x);
	printf("map[y][x] = %c\n", all->map[all->ray.map_y][all->ray.map_x]);
	printf("ray struc map x = %d\n", all->ray.map_x);
	printf("ray struc map y = %d\n", all->ray.map_y);
	//printf("ray struc drawstart = %d\n", all->ray.drawstart);
	//printf("ray struc drawend = %d\n", all->ray.drawend);
	//printf("ray struc lineheight = %d\n", all->ray.lineheight);
	//printf("ray struc hit = %d\n", all->ray.hit);
	//printf("ray struc side = %d\n", all->ray.side);
}

void	ft_escape(t_all *all)
{
	mlx_destroy_image(all->mlx_ptr,all->tex_n.mlx_img);
	mlx_destroy_image(all->mlx_ptr,all->tex_s.mlx_img);
	mlx_destroy_image(all->mlx_ptr,all->tex_e.mlx_img);
	mlx_destroy_image(all->mlx_ptr,all->tex_w.mlx_img);
	mlx_destroy_image(all->mlx_ptr,all->sprite_img.mlx_img);
	mlx_destroy_image(all->mlx_ptr,all->img.mlx_img);
	mlx_destroy_window(all->mlx_ptr, all->win_ptr);
	mlx_destroy_display(all->mlx_ptr);
	free(all->mlx_ptr);
	free_all(all);
	exit(SUCCESS);
}

int	handle_keypress(int keysym, t_all *all)
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
	else if(keysym == XK_t) // penser a envever
		ft_debug(all);
	render(all);
	return (0);
}

