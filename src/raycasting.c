#include "../inc/cub3d.h"

void	ft_set_step(t_all *all)
{
	if (all->player.raydirx < 0)
	{
		all->ray.step_x = -1;
		all->ray.side_dist_x = (all->player.posx - (double)all->ray.map_x)
							* all->ray.delta_dist_x;
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.side_dist_x = ((double)all->ray.map_x + 1.0 - all->player.posx)
							* all->ray.delta_dist_x;
	}
	if (all->player.raydiry < 0)
	{
		all->ray.step_y = -1;
		all->ray.side_dist_y = (all->player.posy - (double)all->ray.map_y)
							* all->ray.delta_dist_y;
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.side_dist_y = ((double)all->ray.map_y + 1.0 - all->player.posy)
							* all->ray.delta_dist_y;
	}
}

void	ft_search_hit(t_all *all)
{
	all->ray.hit = 0;
	while (all->ray.hit == 0)
	{
		if (all->ray.side_dist_x < all->ray.side_dist_y)
		{
			all->ray.side_dist_x += all->ray.delta_dist_x;
			all->ray.map_x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.side_dist_y += all->ray.delta_dist_y;
			all->ray.map_y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->map[all->ray.map_y][all->ray.map_x] == '1')
			all->ray.hit = 1;
	}
}

void	ft_calc_ray(t_all *all)
{
	if (all->ray.side == 0)
		all->ray.perpwalldist = (double)(((double)all->ray.map_x
							- all->player.posx
							+ (double)(1 - all->ray.step_x) / 2)
							/ all->player.raydirx);
	else
		all->ray.perpwalldist = (double)(((double)all->ray.map_y
							- all->player.posy
							+ (double)(1 - all->ray.step_y) / 2)
							/ all->player.raydiry);
	all->ray.lineheight = (int)((double)all->ry / all->ray.perpwalldist);
	all->ray.drawstart = -(all->ray.lineheight) / 2 + all->ry / 2;
	if (all->ray.drawstart < 0)
		all->ray.drawstart = 0;
	all->ray.drawend = all->ray.lineheight / 2 + all->ry / 2;
	if (all->ray.drawend >= all->ry)
		all->ray.drawend = all->ry - 1;
}

void	ft_search_pix_in_img(t_all *all)
{
	if (all->ray.side == 0)
		all->texture.wall_x = all->player.posy + all->ray.perpwalldist
							* all->player.raydiry;
	else
		all->texture.wall_x = all->player.posx + all->ray.perpwalldist
							* all->player.raydirx;
	all->texture.wall_x -= floor(all->texture.wall_x);
	if (all->texture.wall_x < 0)	//regler le segfault dans les coins;
		all->texture.wall_x = 0;
//	else if (all->texture.wall_x > all->map_width_max - 1)
//		all->texture.wall_x = all->map_width_max - 1;
	all->texture.tex_x = (int)(all->texture.wall_x * (double)TEXTURE_WIDTH);
	if (all->ray.side == 0 && all->player.raydirx > 0)
		all->texture.tex_x = TEXTURE_WIDTH - all->texture.tex_x - 1;
	if (all->ray.side == 1 && all->player.raydiry > 0)
		all->texture.tex_x = TEXTURE_WIDTH - all->texture.tex_x - 1;
	all->ray.step = 1.0 * (double)TEXTURE_HEIGHT / (double)all->ray.lineheight;
	all->texture.tex_pos = ((double)all->ray.drawstart - (double)all->ry / 2
						+ (double)all->ray.lineheight / 2) * all->ray.step;
}

void	raycast(t_all *all)
{
	int		x;
	int		i;

	if (all->zbuffer)
		free(all->zbuffer);
	if (!(all->zbuffer = (double *)malloc(sizeof(double) * (all->rx))))
		return ;
	i = -1;
	while (++i < all->rx - 1)
		all->zbuffer[i] = 0;
	x = -1;
	while (++x < all->rx)
	{
		all->player.camerax = 2.0 * (double)x / (double)all->rx - 1.0;
		ft_set_raycast_vars(all);
		ft_set_step(all);
		ft_search_hit(all);
		ft_calc_ray(all);
		ft_search_pix_in_img(all);
		ft_render_side(all, x);
		all->zbuffer[x] = all->ray.perpwalldist;
	}
	render_sprite(all);
}
