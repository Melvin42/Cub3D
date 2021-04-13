#include "cub3d.h"

void	sort_sprites(t_all *all)
{
	int			i;
	int			j;
	t_sprite	swap;

	i = -1;
	if (all->numsprites < 2) // utile?
		return ;
	while (++i < all->numsprites)
	{
		j = i + 1;
		if (all->sprite[i].dist < all->sprite[j].dist)
		{
			swap = all->sprite[i];
			all->sprite[i] = all->sprite[j];
			all->sprite[j] = swap;
			i = -1;
		}
		else
			j++;
	}
}

void	render_sprite(t_all *all, double *Zbuffer)
{
	int	i;
	int	d;
	int	y;
	int		stripe;

	i = -1;
	while (++i < all->numsprites)
	{
		all->sprite[i].dist = ((all->player.posx - all->sprite[i].x) * (all->player.posx - all->sprite[i].x)
				+ (all->player.posy - all->sprite[i].y) * (all->player.posy - all->sprite[i].y));
	}
	i = -1;
	sort_sprites(all);
	while (++i < all->numsprites)
	{
		all->spritex = all->sprite[i].x - all->player.posx + 0.5;
		all->spritey = all->sprite[i].y - all->player.posy + 0.5;
		all->invdet = 1.0 / (all->player.planx * all->player.diry - all->player.dirx * all->player.plany);
		all->transformx = all->invdet * (all->player.diry * all->spritex - all->player.dirx * all->spritey);
		all->transformy = all->invdet * (-all->player.plany * all->spritex + all->player.planx * all->spritey);
		all->spritescreenx = (int)(all->rx / 2) * (1 + all->transformx / all->transformy);
		all->spriteheight = abs((int)(all->ry / all->transformy));
		all->drawstarty = -all->spriteheight / 2 + all->ry / 2;
		if (all->drawstarty < 0)
			all->drawstarty = 0;
		all->drawendy = all->spriteheight / 2 + all->ry / 2;
		if (all->drawendy >= all->ry)
			all->drawendy = all->ry - 1;
		all->spritewidth = abs((int)(all->ry / all->transformy));
		all->drawstartx = -all->spritewidth / 2 + all->spritescreenx;
		if (all->drawstartx < 0)
			all->drawstartx = 0;
		all->drawendx = all->spritewidth / 2 + all->spritescreenx;
		if (all->drawendx >= all->rx)
			all->drawendx= all->rx - 1;
		stripe = all->drawstartx;
		while (stripe < all->drawendx)
		{
			all->texture.tex_x = (int)(256 * (stripe - (-all->spritewidth / 2 + all->spritescreenx)) * SPRITE_WIDTH / all->spritewidth) / 256;
			if (all->transformy > 0 && stripe > 0 && stripe < all->rx && all->transformy < Zbuffer[stripe])
			{
				y = all->drawstarty;
				while (y < all->drawendy)
				{
					d = y * 256 - all->ry * 128 + all->spriteheight * 128;
					all->texture.tex_y = ((d * SPRITE_HEIGHT) / all->spriteheight) / 256;
					all->texture.color = *((int *)all->sprite_img.addr + (SPRITE_WIDTH * all->texture.tex_y + all->texture.tex_x));
					if ((all->texture.color & 0x00FFFFFF) != 0)
						img_pix_put(&all->img, stripe, y, all->texture.color);
					y++;
				}
			}
			stripe++;
		}
	}
}

void	raycast(t_all *all)
{
	int		x;
	double	*Zbuffer;

	if (!(Zbuffer = malloc(sizeof(double) * (all->rx))))
		return ;
	x = -1;
	while (++x < all->rx)
	{
		all->player.camerax = 2.0 * (double)x / (double)all->rx - 1.0;

		all->player.raydirx = all->player.dirx + all->player.planx * all->player.camerax;
		all->player.raydiry = all->player.diry + all->player.plany * all->player.camerax;
		all->ray.map_x = (int)(all->player.posx);
		all->ray.map_y = (int)(all->player.posy);
		all->ray.delta_dist_x = fabs(1.0 / all->player.raydirx);
		all->ray.delta_dist_y = fabs(1.0 / all->player.raydiry);
		all->ray.hit = 0;
		if (all->player.raydirx < 0)
		{
			all->ray.step_x = -1;
			all->ray.side_dist_x = (all->player.posx - (double)all->ray.map_x) * all->ray.delta_dist_x;
		}
		else
		{
			all->ray.step_x = 1;
			all->ray.side_dist_x = ((double)all->ray.map_x + 1.0 - all->player.posx) * all->ray.delta_dist_x;
		}
		if (all->player.raydiry < 0)
		{
			all->ray.step_y = -1;
			all->ray.side_dist_y = (all->player.posy - (double)all->ray.map_y) * all->ray.delta_dist_y;
		}
		else
		{
			all->ray.step_y = 1;
			all->ray.side_dist_y = ((double)all->ray.map_y + 1.0 - all->player.posy) * all->ray.delta_dist_y;
		}
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
			if (all->ray.map_y == 0 && all->map[all->ray.map_y][all->ray.map_x] == '2')
				all->ray.hit = 2;
			else if (all->ray.map_y == all->map_height - 1 && all->map[all->ray.map_y][all->ray.map_x] == '2')
				all->ray.hit = 2;
			else if (all->ray.map_x == 0 && all->map[all->ray.map_y][all->ray.map_x] == '2')
				all->ray.hit = 2;
			else if (all->ray.map_x == all->map_width_max - 1 && all->map[all->ray.map_y][all->ray.map_x] == '2')
				all->ray.hit = 2;

		}
		if (all->ray.side == 0)
			all->ray.perpwalldist = (double)(((double)all->ray.map_x - all->player.posx + (double)(1 - all->ray.step_x) / 2) / all->player.raydirx);
		else
			all->ray.perpwalldist = (double)(((double)all->ray.map_y - all->player.posy + (double)(1 - all->ray.step_y) / 2) / all->player.raydiry);
		all->ray.lineheight = (int)((double)all->ry / all->ray.perpwalldist);
		all->ray.drawstart = -(all->ray.lineheight) / 2 + all->ry / 2;
		if (all->ray.drawstart < 0)
			all->ray.drawstart = 0;
		all->ray.drawend = all->ray.lineheight / 2 + all->ry / 2;
		if (all->ray.drawend >= all->ry)
			all->ray.drawend = all->ry - 1; 
		if (all->ray.side == 0)
			all->texture.wall_x = all->player.posy + all->ray.perpwalldist * all->player.raydiry;
		else
			all->texture.wall_x = all->player.posx + all->ray.perpwalldist * all->player.raydirx;
		all->texture.wall_x -= floor(all->texture.wall_x);
		all->texture.tex_x = (int)(all->texture.wall_x * (double)TEXTURE_WIDTH);

		if (all->ray.side == 0 && all->player.raydirx > 0)
			all->texture.tex_x = TEXTURE_WIDTH - all->texture.tex_x - 1;
		if (all->ray.side == 1 && all->player.raydiry > 0)
			all->texture.tex_x = TEXTURE_WIDTH - all->texture.tex_x - 1;

		all->ray.step = 1.0 * (double)TEXTURE_HEIGHT / (double)all->ray.lineheight;
		all->texture.tex_pos = ((double)all->ray.drawstart - (double)all->ry / 2 + (double)all->ray.lineheight / 2) * all->ray.step;
		if (all->ray.hit == 1)
		{
			if (all->ray.side == 0 && all->ray.step_x == -1)
			{
				render_tex_e(all, x, all->ray.drawstart);
			}
			else if (all->ray.side == 0 && all->ray.step_x == 1)
			{
				render_tex_w(all, x, all->ray.drawstart);
			}
			else if (all->ray.side == 1 && all->ray.step_y == -1)
			{
				render_tex_s(all, x, all->ray.drawstart);
			}
			else if (all->ray.side == 1 && all->ray.step_y == 1)
			{
				render_tex_n(all, x, all->ray.drawstart);
			}
		}
		Zbuffer[x] = all->ray.perpwalldist;
	}
	render_sprite(all, Zbuffer);
}
