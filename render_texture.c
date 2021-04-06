#include "cub3d.h"

int	render_tex_n(t_all *all, int x, int y)
{
	if (all->win_ptr == NULL)
		return (1);
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_n.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}

int	render_tex_s(t_all *all, int x, int y)
{
	if (all->win_ptr == NULL)
		return (1);
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_s.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}

int	render_tex_e(t_all *all, int x, int y)
{
	if (all->win_ptr == NULL)
		return (1);
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_e.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}

int	render_tex_w(t_all *all, int x, int y)
{
	if (all->win_ptr == NULL)
		return (1);
	while (y < all->ray.drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += all->ray.step;
		all->texture.color = *((int *)all->tex_w.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, y++, all->texture.color);
	}
	return (0);
}
