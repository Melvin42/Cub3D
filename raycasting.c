#include "cub3d.h"

void	ft_set_raycast_vars(t_all *all)
{
	all->player.raydirx = all->player.dirx + all->player.planx
						* all->player.camerax;
	all->player.raydiry = all->player.diry + all->player.plany
						* all->player.camerax;
	all->ray.map_x = (int)(all->player.posx);
	all->ray.map_y = (int)(all->player.posy);
	all->ray.delta_dist_x = fabs(1.0 / all->player.raydirx);
	all->ray.delta_dist_y = fabs(1.0 / all->player.raydiry);
	all->ray.hit = 0;
}

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
		if (all->ray.map_y == 0 && all->map[all->ray.map_y][all->ray.map_x] == '2') // a supprimer
			all->ray.hit = 2;
		else if (all->ray.map_y == all->map_height - 1 && all->map[all->ray.map_y][all->ray.map_x] == '2')
			all->ray.hit = 2;
		else if (all->ray.map_x == 0 && all->map[all->ray.map_y][all->ray.map_x] == '2')
			all->ray.hit = 2;
		else if (all->ray.map_x == all->map_width_max - 1 && all->map[all->ray.map_y][all->ray.map_x] == '2')
			all->ray.hit = 2;
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
	all->texture.tex_x = (int)(all->texture.wall_x * (double)TEXTURE_WIDTH);
	if (all->ray.side == 0 && all->player.raydirx > 0)
		all->texture.tex_x = TEXTURE_WIDTH - all->texture.tex_x - 1;
	if (all->ray.side == 1 && all->player.raydiry > 0)
		all->texture.tex_x = TEXTURE_WIDTH - all->texture.tex_x - 1;
	all->ray.step = 1.0 * (double)TEXTURE_HEIGHT / (double)all->ray.lineheight;
	all->texture.tex_pos = ((double)all->ray.drawstart - (double)all->ry / 2
						+ (double)all->ray.lineheight / 2) * all->ray.step;
}

void	ft_render_side(t_all *all, int x)
{
	if (all->ray.hit == 1)
	{
		if (all->ray.side == 0 && all->ray.step_x == -1)
			render_tex_e(all, x, all->ray.drawstart);
		else if (all->ray.side == 0 && all->ray.step_x == 1)
			render_tex_w(all, x, all->ray.drawstart);
		else if (all->ray.side == 1 && all->ray.step_y == -1)
			render_tex_s(all, x, all->ray.drawstart);
		else if (all->ray.side == 1 && all->ray.step_y == 1)
			render_tex_n(all, x, all->ray.drawstart);
	}
}

void	raycast(t_all *all)
{
	int		x;
	double	*zbuffer;

	if (!(zbuffer = malloc(sizeof(double) * (all->rx))))
		return ;
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
		zbuffer[x] = all->ray.perpwalldist;
	}
	render_sprite(all, zbuffer);
}
