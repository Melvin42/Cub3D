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
	int	i = drawstart;
	(void)color;
	while (i < drawend)
		img_pix_put(&data->img, x, i++, RED_PIXEL); 
	return (0);
}

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

double	ft_abs(double n)
{
	if (n < 0)
		return (n * -1);
	else 
		return (n);
}
int		raycast(t_data *data)
{
	int	x;
	double	deltadistx;
	double	deltadisty;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty; 
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	x = -1;
	render_background(&data->img, data, BLACK_PIXEL);
	while (++x < data->rx)
	{
		data->player.camerax = 2 * (double)x / (double)data->rx - 1;
		printf("camera %f\n", data->player.camerax);
		printf("planx %f\n", data->player.planx);
		printf("plany %f\n", data->player.plany);

		data->player.raydirx = data->player.dirx + data->player.planx * data->player.camerax;
		data->player.raydiry = data->player.diry + data->player.plany * data->player.camerax;
		printf("raydirx %f\n", data->player.raydirx);
		printf("raydiry %f\n", data->player.raydirx);
		mapx = (int)(data->player.posx);
		mapy = (int)(data->player.posy);
/*		1f (data->player.raydiry == 0)
			deltadistx = 0;
		else
		{
			if (data->player.raydirx == 0)
				deltadistx = 1;
			else
				deltadistx = ft_abs(1.0 / data->player.raydirx);
		}
		if (data->player.raydirx == 0)
			deltadisty = 0;
		else
		{
			if (data->player.raydiry == 0)
				deltadisty = 1;
			else
				deltadisty = ft_abs(1.0 / data->player.raydiry);
		}
*/
		deltadistx = ft_abs(1.0 / data->player.raydirx);
		deltadisty = ft_abs(1.0 / data->player.raydiry);

		hit = 0;
		if (data->player.raydirx < 0)
		{
			stepx = -1;
			sidedistx = (data->player.posx - (double)mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = ((double)mapx + 1.0 - data->player.posx) * deltadistx;
		}
		if (data->player.raydiry < 0)
		{
			stepy = -1;
			sidedisty = (data->player.posy - (double)mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = ((double)mapy + 1.0 - data->player.posy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (data->map[mapy][mapx] > '0')
				hit = 1;
		}
		if (side == 0)
			perpwalldist = ((double)mapx - data->player.posx + (1 - (double)stepx) / 2) / (data->player.raydirx);
		else
			perpwalldist = ((double)mapy - data->player.posy + (1 - (double)stepy) / 2) / (data->player.raydiry);
		printf("perp = %f\n", perpwalldist);
		printf("dirx = %f\n", data->player.dirx);
		printf("diry = %f\n", data->player.diry);
		printf("posx = %f\n", data->player.posx);
		printf("posy = %f\n", data->player.posy);
		lineheight = (int)((double)data->ry / perpwalldist);
		printf("lineheight = %d\n", lineheight);
		drawstart = -lineheight / 2 + data->ry / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + data->ry / 2;
		if (drawend >= data->ry)
			drawend = data->ry - 1; 
		render_col(data, x, drawstart, drawend, RED_PIXEL);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
