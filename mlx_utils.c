#include "cub3d.h"

int	handle_keypress(int keysym, t_all *all)
{
	double 	olddirx;
	double	oldplanx;
	double rotspeed = 0.1;
	double movespeed = 0.1;

	if (keysym == XK_Escape)
	{
		mlx_destroy_image(all->mlx_ptr,all->img.mlx_img);
		mlx_destroy_display(all->mlx_ptr);
		mlx_destroy_window(all->mlx_ptr, all->win_ptr);
		free(all->win_ptr);
		free(all->mlx_ptr);
		free_all(all);
		exit(1);
	}
	else if (keysym == XK_Return)
	{
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
	}
	else if (keysym == XK_1)
	{
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
		menu(all);
		return (0);
	}
	else if (keysym == XK_Up || keysym == XK_w)
	{
		if (all->map[(int)all->player.posy][(int)(all->player.posx + all->player.dirx * movespeed)] == '0')
			all->player.posx += all->player.dirx * movespeed;
		if (all->map[(int)(all->player.posy + all->player.diry * movespeed)][(int)all->player.posx] == '0')
			all->player.posy += all->player.diry * movespeed;
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		if (all->map[(int)all->player.posy][(int)(all->player.posx - all->player.diry * movespeed)] == '0')
			all->player.posx -= all->player.dirx * movespeed;
		if (all->map[(int)(all->player.posy - all->player.diry * movespeed)][(int)all->player.posx] == '0')
			all->player.posy -= all->player.diry * movespeed;
	}
	else if (keysym == XK_a)
	{
		if (all->map[(int)(all->player.posy)][(int)(all->player.posx + all->player.diry * movespeed)] == '0')
			all->player.posx += all->player.diry * movespeed;
		if (all->map[(int)(all->player.posy - all->player.dirx * movespeed)][(int)all->player.posx] == '0')
			all->player.posy -= all->player.dirx * movespeed;
	}
	else if (keysym == XK_d)
	{
		if (all->map[(int)(all->player.posy)][(int)(all->player.posx - all->player.diry * movespeed)] == '0')
			all->player.posx -= all->player.diry * movespeed;
		if (all->map[(int)(all->player.posy - all->player.dirx * movespeed)][(int)all->player.posx] == '0')
			all->player.posy += all->player.dirx * movespeed;
	}
	else if (keysym == XK_Left || keysym == XK_q)
	{
		olddirx = all->player.dirx;
		all->player.dirx = all->player.dirx * cos(-rotspeed) - all->player.diry * sin(-rotspeed);
		all->player.diry = olddirx * sin(-rotspeed) + all->player.diry * cos(-rotspeed);
		oldplanx = all->player.planx;
//		printf("%f\n", all->player.planx);
//		printf("%f\n", all->player.plany);
//		all->player.planx = -all->player.diry;
//		all->player.plany = all->player.dirx;
		all->player.planx = all->player.planx * cos(-rotspeed) - all->player.plany * sin(-rotspeed);
		all->player.plany = oldplanx * sin(-rotspeed) + all->player.plany * cos(-rotspeed);
	}
	else if (keysym == XK_Right || keysym == XK_e)
	{
		olddirx = all->player.dirx;
		all->player.dirx = all->player.dirx * cos(rotspeed) - all->player.diry * sin(rotspeed);
		all->player.diry = olddirx * sin(rotspeed) + all->player.diry * cos(rotspeed);
		oldplanx = all->player.planx;
//		all->player.planx = -all->player.diry;
//		all->player.plany = all->player.dirx;
//		printf("%f\n", all->player.planx);
//		printf("%f\n", all->player.plany);
		all->player.planx = all->player.planx * cos(rotspeed) - all->player.plany * sin(rotspeed);
		all->player.plany = oldplanx * sin(rotspeed) + all->player.plany * cos(rotspeed);
	}
	raycast(all);
	return (0);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int	i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_col(t_all *all, int x, int drawstart, int drawend, int color)
{
	if (all->win_ptr == NULL)
		return (1);
	while (drawstart < drawend)
		img_pix_put(&all->img, x, drawstart++, color); 
	return (0);
}

int	render_tex_n(t_all *all, int x, int drawstart, int drawend, double step)
{
	if (all->win_ptr == NULL)
		return (1);
	while (drawstart < drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += step;
		all->texture.color = *((int *)all->tex_n.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, drawstart++, all->texture.color);
	}
	return (0);
}

int	render_tex_s(t_all *all, int x, int drawstart, int drawend, double step)
{
	if (all->win_ptr == NULL)
		return (1);
	while (drawstart < drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += step;
		all->texture.color = *((int *)all->tex_s.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, drawstart++, all->texture.color);
	}
	return (0);
}

int	render_tex_e(t_all *all, int x, int drawstart, int drawend, double step)
{
	if (all->win_ptr == NULL)
		return (1);
	while (drawstart < drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += step;
		all->texture.color = *((int *)all->tex_e.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, drawstart++, all->texture.color);
	}
	return (0);
}

int	render_tex_w(t_all *all, int x, int drawstart, int drawend, double step)
{
	if (all->win_ptr == NULL)
		return (1);
	while (drawstart < drawend)
	{
		all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
		all->texture.tex_pos += step;
		all->texture.color = *((int *)all->tex_w.addr + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
		img_pix_put(&all->img, x, drawstart++, all->texture.color);
	}
	return (0);
}

int	render_tex(t_all *all, uint32_t buffer[all->ry][all->rx])
{
	int	i = -1;
	int j = -1;

	if (all->win_ptr == NULL)
		return (1);
	while (++i < all->ry)
	{
		j = -1;
		while (++j < all->rx)
		{
			img_pix_put(&all->img, j, i, buffer[i][j]);
		}
	}
	return (0);
}

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
		img_pix_put(&all->img, x++, y - 1, BLACK_PIXEL);
	while (y <= 30)
	{
		x = drawstart - 1;
		img_pix_put(&all->img, x, y, BLACK_PIXEL);
		x++;
		while (x < drawend)
		{
			img_pix_put(&all->img, x++, y, RED_PIXEL);
		}
		img_pix_put(&all->img, x, y, BLACK_PIXEL);
		y++;
	}
	x = drawstart - 1;
	while (x < drawend + 1)
		img_pix_put(&all->img, x++, y, BLACK_PIXEL);
	return (0);
}
void	render_background(t_img *img, t_all *all, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->ry)
	{
		j = 0;
		while (j < all->rx)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	menu(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_string_put(all->mlx_ptr, all->win_ptr, all->rx / 2, all->ry / 2, WHITE_PIXEL, "BIENVENUE");
	mlx_string_put(all->mlx_ptr, all->win_ptr, all->rx / 2, all->ry / 2+20, WHITE_PIXEL, "APPUYEZ SUR ENTREE");
	return (0);
}

int	render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	render_background(&all->img, all, BLACK_PIXEL);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	return (0);
}

int		raycast(t_all *all)
{
	int		x;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	step; // a mettre dans t_texture attention a sed stepx stepy
//	uint32_t		buffer[all->ry][all->rx];

	x = -1;
	render_background(&all->img, all, BLACK_PIXEL);
	while (++x < all->rx)
	{
		all->player.camerax = 2 * (double)x / (double)all->rx - 1;

		all->player.raydirx = all->player.dirx + all->player.planx * all->player.camerax;
		all->player.raydiry = all->player.diry + all->player.plany * all->player.camerax;
		mapx = (int)(all->player.posx);
		mapy = (int)(all->player.posy);
/*		if (all->player.raydiry == 0)
			all->raycast.delta_dist_x = 0;
		else
		{
			if (all->player.raydirx == 0)
				all->raycast.delta_dist_x = 1;
			else
				all->raycast.delta_dist_x = ft_abs(1.0 / all->player.raydirx);
		}
		if (all->player.raydirx == 0)
			all->raycast.delta_dist_y = 0;
		else
		{
			if (all->player.raydiry == 0)
				all->raycast.delta_dist_y = 1;
			else
				all->raycast.delta_dist_y = ft_abs(1.0 / all->player.raydiry);
		}
*/
		//all->raycast.delta_dist_x = fabs(1.0 / all->player.raydirx);
		//all->raycast.delta_dist_y = fabs(1.0 / all->player.raydiry);
		all->raycast.delta_dist_x = sqrt(1.0 + (all->player.raydiry * all->player.raydiry) / (all->player.raydirx * all->player.raydirx));
		all->raycast.delta_dist_y = sqrt(1.0 + (all->player.raydirx * all->player.raydirx) / (all->player.raydiry * all->player.raydiry));

		hit = 0;
		if (all->player.raydirx < 0)
		{
			stepx = -1;
			all->raycast.side_dist_x = (all->player.posx - (double)mapx) * all->raycast.delta_dist_x;
		}
		else
		{
			stepx = 1;
			all->raycast.side_dist_x = ((double)mapx + 1.0 - all->player.posx) * all->raycast.delta_dist_x;
		}
		if (all->player.raydiry < 0)
		{
			stepy = -1;
			all->raycast.side_dist_y = (all->player.posy - (double)mapy) * all->raycast.delta_dist_y;
		}
		else
		{
			stepy = 1;
			all->raycast.side_dist_y = ((double)mapy + 1.0 - all->player.posy) * all->raycast.delta_dist_y;
		}
		while (hit == 0)
		{
			if (all->raycast.side_dist_x < all->raycast.side_dist_y)
			{
				all->raycast.side_dist_x += all->raycast.delta_dist_x;
				mapx += stepx;
				side = 0;
			}
			else
			{
				all->raycast.side_dist_y += all->raycast.delta_dist_y;
				mapy += stepy;
				side = 1;
			}
			if (all->map[mapy][mapx] > '0')
				hit = 1;
		}
		if (side == 0)
			all->raycast.perpwalldist = ((double)mapx - all->player.posx + (1 - (double)stepx) / 2) / (all->player.raydirx);
		else
			all->raycast.perpwalldist = ((double)mapy - all->player.posy + (1 - (double)stepy) / 2) / (all->player.raydiry);
		lineheight = (int)((double)all->ry / all->raycast.perpwalldist);
		drawstart = -lineheight / 2 + all->ry / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + all->ry / 2;
		if (drawend >= all->ry)
			drawend = all->ry - 1; 
		if (side == 0)
			all->texture.wall_x = all->player.posy + all->raycast.perpwalldist * all->player.raydiry;
		else
			all->texture.wall_x = all->player.posx + all->raycast.perpwalldist * all->player.raydirx;
		all->texture.wall_x -= floor(all->texture.wall_x);
		all->texture.tex_x = (int)(all->texture.wall_x * (double)TEXTURE_WIDTH);
		
		if (side == 0 && all->player.raydirx > 0)
			all->texture.tex_x = (double)TEXTURE_WIDTH - all->texture.tex_x - 1;
		if (side == 1 && all->player.raydiry > 0)
			all->texture.tex_x = (double)TEXTURE_WIDTH - all->texture.tex_x - 1;

		step = 1.0 * (double)TEXTURE_HEIGHT / lineheight;
		all->texture.tex_pos = (drawstart - (double)all->ry / 2 + lineheight / 2) * step;
	//	int	d;
		int	y;
		y = drawstart;
/*		while (y < drawend)
		{
			d = y * 256 - all->ry * 128 + lineheight * 128;
			all->texture.tex_y = (((d * TEXTURE_HEIGHT) / lineheight) / 256);
			all->texture.tex_pos = all->texture.tex_y * TEXTURE_WIDTH + all->texture.tex_x;
			all->texture.color = *(((int *)all->tex_s.addr) + (int)all->texture.tex_pos);
			buffer[y][x] = all->texture.color;
			y++;
		}
*/		
/*		while (y < drawend)
		{
			all->texture.tex_y = (int)all->texture.tex_pos & (TEXTURE_HEIGHT - 1);
			all->texture.tex_pos += step;
			all->texture.color = *(((int *)all->tex_s.addr) + (TEXTURE_HEIGHT * all->texture.tex_y + all->texture.tex_x));
			buffer[y][x] = all->texture.color;
			y++;
		}
*/	
		if (side == 0 && stepx == -1)
		{
			render_col(all, x, 0, drawstart, CYAN_PIXEL);
			render_tex_e(all, x, drawstart, drawend, step);
			//render_tex(all, buffer);
			render_col(all, x, drawend, all->ry, GREY_PIXEL);
		}
		else if (side == 0 && stepx == 1)
		{
			render_col(all, x, 0, drawstart, CYAN_PIXEL);
			render_tex_w(all, x, drawstart, drawend, step);
			//render_tex(all, buffer);
			render_col(all, x, drawend, all->ry, GREY_PIXEL);
		}
		else if (side == 1 && stepy == -1)
		{
			render_col(all, x, 0, drawstart, CYAN_PIXEL);
			render_tex_s(all, x, drawstart, drawend, step);
			//render_tex(all, buffer);
			render_col(all, x, drawend, all->ry, GREY_PIXEL);
		}
		else
		{
			render_col(all, x, 0, drawstart, CYAN_PIXEL);
			render_tex_n(all, x, drawstart, drawend, step);
			//render_tex(all, buffer);
			render_col(all, x, drawend, all->ry, GREY_PIXEL);
		}
//		render_life(all);
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, all->rx / 2, 25, BLACK_PIXEL, "100%");
/*	int i = -1;
	int j = -1;
	while (++i < all->ry)
	{
		j = -1;
		while (++j < all->rx)
		{
			buffer[i][j] = 0;
		}
	}*/
	return (0);
}
