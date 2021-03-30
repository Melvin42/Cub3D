#include "cub3d.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
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
		raycast(data);
	}
	else if (keysym == XK_1)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		menu(data);
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
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

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render_col(t_data *data, int x, int drawstart, int drawend, int color)
{
	if (data->win_ptr == NULL)
		return (1);
	int	i = drawstart;
	(void)color;
	//	printf("drawstart %d\n", drawstart);
	//	printf("drawend %d\n", drawend);
	while (i < drawend)
		img_pix_put(&data->img, x, i++, RED_PIXEL); 
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
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
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->rx / 2, data->ry / 2, 255, "BIENVENUE");
	mlx_string_put(data->mlx_ptr, data->win_ptr, data->rx / 2, data->ry / 2+20, 255, "Appuyez sur entree");
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, data, BLACK_PIXEL);
	//	render_rect(&data->img, (t_rect){data->rx - 100, data->ry - 100, 100, 100, GREEN_PIXEL});
	//	render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});
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
