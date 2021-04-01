#include "cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	double 	olddirx;
	double	oldplanx;
	double rotspeed = 0.1;
	double movespeed = 0.1;

	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr,data->img.mlx_img);
		mlx_destroy_display(data->mlx_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->win_ptr);
		free(data->mlx_ptr);
		free_data(data);
		exit(1);
	}
	else if (keysym == XK_Return)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	}
	else if (keysym == XK_1)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		menu(data);
		return (0);
	}
	else if (keysym == XK_Up || keysym == XK_w)
	{
		if (data->map[(int)data->player.posy][(int)(data->player.posx + data->player.dirx * movespeed)] == '0')
			data->player.posx += data->player.dirx * movespeed;
		if (data->map[(int)(data->player.posy + data->player.diry * movespeed)][(int)data->player.posx] == '0')
			data->player.posy += data->player.diry * movespeed;
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		if (data->map[(int)data->player.posy][(int)(data->player.posx - data->player.diry * movespeed)] == '0')
			data->player.posx -= data->player.dirx * movespeed;
		if (data->map[(int)(data->player.posy - data->player.diry * movespeed)][(int)data->player.posx] == '0')
			data->player.posy -= data->player.diry * movespeed;
	}
	else if (keysym == XK_a)
	{
		if (data->map[(int)(data->player.posy)][(int)(data->player.posx + data->player.diry * movespeed)] == '0')
			data->player.posx += data->player.diry * movespeed;
		if (data->map[(int)(data->player.posy - data->player.dirx * movespeed)][(int)data->player.posx] == '0')
			data->player.posy -= data->player.dirx * movespeed;
	}
	else if (keysym == XK_d)
	{
		if (data->map[(int)(data->player.posy)][(int)(data->player.posx - data->player.diry * movespeed)] == '0')
			data->player.posx -= data->player.diry * movespeed;
		if (data->map[(int)(data->player.posy - data->player.dirx * movespeed)][(int)data->player.posx] == '0')
			data->player.posy += data->player.dirx * movespeed;
	}
	else if (keysym == XK_Left || keysym == XK_q)
	{
		olddirx = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(-rotspeed) - data->player.diry * sin(-rotspeed);
		data->player.diry = olddirx * sin(-rotspeed) + data->player.diry * cos(-rotspeed);
		oldplanx = data->player.planx;
		data->player.planx = data->player.planx * cos(-rotspeed) - data->player.plany * sin(-rotspeed);
		data->player.plany = oldplanx * sin(-rotspeed) + data->player.plany * cos(-rotspeed);
	}
	else if (keysym == XK_Right || keysym == XK_e)
	{
		olddirx = data->player.dirx;
		data->player.dirx = data->player.dirx * cos(rotspeed) - data->player.diry * sin(rotspeed);
		data->player.diry = olddirx * sin(rotspeed) + data->player.diry * cos(rotspeed);
		oldplanx = data->player.planx;
		data->player.planx = data->player.planx * cos(rotspeed) - data->player.plany * sin(rotspeed);
		data->player.plany = oldplanx * sin(rotspeed) + data->player.plany * cos(rotspeed);
	}
	raycast(data);
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

int	render_col(t_data *data, int x, int drawstart, int drawend, int color)
{
	if (data->win_ptr == NULL)
		return (1);
	while (drawstart < drawend)
		img_pix_put(&data->img, x, drawstart++, color); 
	return (0);
}
/*
int	render_tex(t_data *data, int x, int drawstart, int drawend, void *img_ptr)
{
	if (data->win_ptr == NULL)
		return (1);
	while (drawstart < drawend)
		img_pix_put(&data->img, x, drawstart++, color); 
	return (0);
}
*/
void	render_background(t_img *img, t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->ry)
	{
		j = 0;
		while (j < data->rx)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	menu(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->rx / 2, data->ry / 2, WHITE_PIXEL, "BIENVENUE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->rx / 2, data->ry / 2+20, WHITE_PIXEL, "APPUYEZ SUR ENTREE");
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, data, BLACK_PIXEL);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int		raycast(t_data *data)
{
	int	x;
	int	y;
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

	x = -1;
	render_background(&data->img, data, BLACK_PIXEL);
	while (++x < data->rx)
	{
		data->player.camerax = 2 * (double)x / (double)data->rx - 1;

		data->player.raydirx = data->player.dirx + data->player.planx * data->player.camerax;
		data->player.raydiry = data->player.diry + data->player.plany * data->player.camerax;
		mapx = (int)(data->player.posx);
		mapy = (int)(data->player.posy);
/*		if (data->player.raydiry == 0)
			data->raycast.delta_dist_x = 0;
		else
		{
			if (data->player.raydirx == 0)
				data->raycast.delta_dist_x = 1;
			else
				data->raycast.delta_dist_x = ft_abs(1.0 / data->player.raydirx);
		}
		if (data->player.raydirx == 0)
			data->raycast.delta_dist_y = 0;
		else
		{
			if (data->player.raydiry == 0)
				data->raycast.delta_dist_y = 1;
			else
				data->raycast.delta_dist_y = ft_abs(1.0 / data->player.raydiry);
		}
*/
		//data->raycast.delta_dist_x = fabs(1.0 / data->player.raydirx);
		//data->raycast.delta_dist_y = fabs(1.0 / data->player.raydiry);
		data->raycast.delta_dist_x = sqrt(1.0 + (data->player.raydiry * data->player.raydiry) / (data->player.raydirx * data->player.raydirx));
		data->raycast.delta_dist_y = sqrt(1.0 + (data->player.raydirx * data->player.raydirx) / (data->player.raydiry * data->player.raydiry));

		hit = 0;
		if (data->player.raydirx < 0)
		{
			stepx = -1;
			data->raycast.side_dist_x = (data->player.posx - (double)mapx) * data->raycast.delta_dist_x;
		}
		else
		{
			stepx = 1;
			data->raycast.side_dist_x = ((double)mapx + 1.0 - data->player.posx) * data->raycast.delta_dist_x;
		}
		if (data->player.raydiry < 0)
		{
			stepy = -1;
			data->raycast.side_dist_y = (data->player.posy - (double)mapy) * data->raycast.delta_dist_y;
		}
		else
		{
			stepy = 1;
			data->raycast.side_dist_y = ((double)mapy + 1.0 - data->player.posy) * data->raycast.delta_dist_y;
		}
		while (hit == 0)
		{
			if (data->raycast.side_dist_x < data->raycast.side_dist_y)
			{
				data->raycast.side_dist_x += data->raycast.delta_dist_x;
				mapx += stepx;
				side = 0;
			}
			else
			{
				data->raycast.side_dist_y += data->raycast.delta_dist_y;
				mapy += stepy;
				side = 1;
			}
			if (data->map[mapy][mapx] > '0')
				hit = 1;
		}
	//	printf("SIDE = %d\n", side);
		if (side == 0)
			data->raycast.perpwalldist = ((double)mapx - data->player.posx + (1 - (double)stepx) / 2) / (data->player.raydirx);
		else
			data->raycast.perpwalldist = ((double)mapy - data->player.posy + (1 - (double)stepy) / 2) / (data->player.raydiry);
		lineheight = (int)((double)data->ry / data->raycast.perpwalldist);
		drawstart = -lineheight / 2 + data->ry / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + data->ry / 2;
		if (drawend >= data->ry)
			drawend = data->ry - 1; 
		if (side == 0)
			data->texture.wall_x = (int)(data->player.posy + data->raycast.perpwalldist * data->player.raydiry);
		else
			data->texture.wall_x = (int)(data->player.posx + data->raycast.perpwalldist * data->player.raydirx);
		data->texture.wall_x -= floor(data->texture.wall_x);
		data->texture.tex_x = (int)(data->texture.wall_x * (double)TEXTURE_WIDTH);
		step = 1.0 * (double)TEXTURE_HEIGHT / lineheight;
		data->texture.tex_pos = (drawstart - (double)data->ry / 2 + lineheight / 2) * step;
		y = drawstart;
	/*	int	d;
		while (y < drawend)
		{
			d = y * 256 - data->ry * 128 + lineheight * 128;
			data->texture.tex_y = (((d * TEXTURE_HEIGHT) / lineheight) / 256);
			data->texture.tex_pos = data->texture.tex_y * TEXTURE_WIDTH + data->texture.tex_x;
			data->texture.color = *(((int *)data->tex.addr) + (int)data->texture.tex_pos);
			img_pix_put(&data->img, x, y, data->texture.color);
			y++;
		}
	*/
		if (side == 0 && stepx == -1)
		{
			render_col(data, x, 0, drawstart, CYAN_PIXEL);
			while (y < drawend)
			{
				data->texture.tex_y = (int)data->texture.tex_pos & (TEXTURE_HEIGHT - 1);
				data->texture.tex_pos += step;
				data->texture.color = *((int *)data->tex_e.addr + (TEXTURE_HEIGHT * data->texture.tex_y + data->texture.tex_x));
				img_pix_put(&data->img, x, y, data->texture.color);
				y++;
			}
			data->tex_e.addr+=4;
			render_col(data, x, drawend, data->ry, GREY_PIXEL);
		}
		else if (side == 0 && stepx == 1)
		{
			render_col(data, x, 0, drawstart, CYAN_PIXEL);
			while (y < drawend)
			{
				data->texture.tex_y = (int)data->texture.tex_pos & (TEXTURE_HEIGHT - 1);
				data->texture.tex_pos += step;
				data->texture.color = *((int *)data->tex_w.addr + (TEXTURE_HEIGHT * data->texture.tex_y + data->texture.tex_x));
				img_pix_put(&data->img, x, y, data->texture.color);
				y++;
			}
			data->tex_w.addr+=4;
			render_col(data, x, drawend, data->ry, GREY_PIXEL);
		}
		else if (side == 1 && stepy == -1)
		{
			render_col(data, x, 0, drawstart, CYAN_PIXEL);
			while (y < drawend)
			{
				data->texture.tex_y = (int)data->texture.tex_pos & (TEXTURE_HEIGHT - 1);
				data->texture.tex_pos += step;
				data->texture.color = *((int *)data->tex_s.addr + (TEXTURE_HEIGHT * data->texture.tex_y + data->texture.tex_x));
				img_pix_put(&data->img, x, y, data->texture.color);
				y++;
			}
			data->tex_s.addr+=4;
			render_col(data, x, drawend, data->ry, GREY_PIXEL);
		}
		else
		{
			render_col(data, x, 0, drawstart, CYAN_PIXEL);
			while (y < drawend)
			{
				data->texture.tex_y = (int)data->texture.tex_pos & (TEXTURE_HEIGHT - 1);
				data->texture.tex_pos += step;
				data->texture.color = *((int *)data->tex_n.addr + (TEXTURE_HEIGHT * data->texture.tex_y + data->texture.tex_x));
				img_pix_put(&data->img, x, y, data->texture.color);
				y++;
			}
			data->tex_n.addr+=4;
			render_col(data, x, drawend, data->ry, GREY_PIXEL);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
