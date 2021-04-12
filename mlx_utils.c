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

int	handle_keypress(int keysym, t_all *all)
{
	double 	olddirx;
	double	oldplanx;
	double rotspeed = 0.1;
	double movespeed = 0.1;

	if (keysym == XK_Escape)
	{
			mlx_destroy_image(all->mlx_ptr,all->tex_n.mlx_img);
			mlx_destroy_image(all->mlx_ptr,all->tex_s.mlx_img);
			mlx_destroy_image(all->mlx_ptr,all->tex_e.mlx_img);
			mlx_destroy_image(all->mlx_ptr,all->tex_w.mlx_img);
			mlx_destroy_image(all->mlx_ptr,all->sprite_img.mlx_img);
			mlx_destroy_image(all->mlx_ptr,all->img.mlx_img);
			mlx_destroy_window(all->mlx_ptr, all->win_ptr);
			mlx_destroy_display(all->mlx_ptr);
			//free(all->win_ptr);
			free(all->mlx_ptr);
			free_all(all);
			exit(SUCCESS);
	}
	else if (keysym == XK_Return)
	{
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
	}
	else if (keysym == XK_1)
	{
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
//		menu(all);
		return (0);
	}
	else if (keysym == XK_Up || keysym == XK_w)
	{
		if (all->map[(int)all->player.posy][(int)(all->player.posx + all->player.dirx * movespeed)] == '0')
			all->player.posx += all->player.dirx * movespeed * 1.1;
		if (all->map[(int)(all->player.posy + all->player.diry * movespeed)][(int)all->player.posx] == '0')
			all->player.posy += all->player.diry * movespeed * 1.1;
	}
	else if (keysym == XK_Down || keysym == XK_s)
	{
		if (all->map[(int)all->player.posy][(int)(all->player.posx - all->player.dirx * movespeed)] == '0')
			all->player.posx -= all->player.dirx * movespeed * 1.1;
		if (all->map[(int)(all->player.posy - all->player.diry * movespeed)][(int)all->player.posx] == '0')
			all->player.posy -= all->player.diry * movespeed * 1.1;
	}
	else if (keysym == XK_a)
	{
		//voir avec plan
		
		if (all->map[(int)(all->player.posy)][(int)(all->player.posx + all->player.diry * movespeed)] == '0')
			all->player.posx += all->player.diry * movespeed * 1.1;
		if (all->map[(int)(all->player.posy - all->player.dirx * movespeed)][(int)all->player.posx] == '0')
			all->player.posy -= all->player.dirx * movespeed * 1.1;

		/*	if (all->map[(int)(all->player.posy)][(int)(all->player.posx - all->player.planx * movespeed)] == '0')
			all->player.posx -= all->player.planx * movespeed * 1.1;
			if (all->map[(int)(all->player.posy - all->player.plany * movespeed)][(int)all->player.posx] == '0')
			all->player.posy -= all->player.plany * movespeed * 1.1;
		 */
	}
	else if (keysym == XK_d)
	{
		
		if (all->map[(int)(all->player.posy)][(int)(all->player.posx - all->player.diry * movespeed)] == '0')
			all->player.posx -= all->player.diry * movespeed * 1.1;
		if (all->map[(int)(all->player.posy - all->player.dirx * movespeed)][(int)all->player.posx] == '0')
			all->player.posy += all->player.dirx * movespeed * 1.1;

		/*	if (all->map[(int)(all->player.posy)][(int)(all->player.posx + all->player.planx * movespeed)] == '0')
			all->player.posx += all->player.planx * movespeed * 1.1;
			if (all->map[(int)(all->player.posy + all->player.plany * movespeed)][(int)all->player.posx] == '0')
			all->player.posy += all->player.plany * movespeed * 1.1;
		 */
	}
	else if (keysym == XK_Left || keysym == XK_q)
	{
		olddirx = all->player.dirx;
		all->player.dirx = all->player.dirx * cos(-rotspeed) - all->player.diry * sin(-rotspeed);
		all->player.diry = olddirx * sin(-rotspeed) + all->player.diry * cos(-rotspeed);
		oldplanx = all->player.planx;
		all->player.planx = all->player.planx * cos(-rotspeed) - all->player.plany * sin(-rotspeed);
		all->player.plany = oldplanx * sin(-rotspeed) + all->player.plany * cos(-rotspeed);
	}
	else if (keysym == XK_Right || keysym == XK_e)
	{
		olddirx = all->player.dirx;
		all->player.dirx = all->player.dirx * cos(rotspeed) - all->player.diry * sin(rotspeed);
		all->player.diry = olddirx * sin(rotspeed) + all->player.diry * cos(rotspeed);
		oldplanx = all->player.planx;
		all->player.planx = all->player.planx * cos(rotspeed) - all->player.plany * sin(rotspeed);
		all->player.plany = oldplanx * sin(rotspeed) + all->player.plany * cos(rotspeed);
	}
	else if(keysym == XK_t)
	{
		ft_debug(all);
	}
	render(all);
	return (0);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put( t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	render_background(t_img *img, t_all *all, int color)
{
	int	i;
	int	j;

	(void)color;
	i = 0;
	while (i < all->ry / 2)
	{
		j = 0;
		while (j < all->rx)
			img_pix_put(img, j++, i, BLACK_PIXEL);
		++i;
	}
	while (i < all->ry)
	{
		j = 0;
		while (j < all->rx)
			img_pix_put(img, j++, i, GREY_PIXEL);
		++i;
	}
}

int	menu(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->menu.mlx_img, ((all->rx / 2) - (418 / 2)), 0);
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 2) / 10)),
			all->ry / 2, WHITE_PIXEL, "WELCOME TO THE WORLD OF WARCUB!!!");
	mlx_string_put(all->mlx_ptr, all->win_ptr, ((all->rx / 2 - (all->rx / 8) / 10)),
			(all->ry / 2 + ((all->ry / 2) / 8)), WHITE_PIXEL, "PRESS ENTER");
	return (0);
}

int	render(t_all *all)
{
	if (all->win_ptr == NULL)
		return (1);
	mlx_destroy_image(all->mlx_ptr, all->img.mlx_img);
	all->img.mlx_img = mlx_new_image(all->mlx_ptr, all->rx, all->ry);
	all->img.addr = mlx_get_data_addr(all->img.mlx_img, &all->img.bpp,
			&all->img.line_len, &all->img.endian);
	render_background(&all->img, all, BLACK_PIXEL);
	raycast(all);
//	render_life(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
//	mlx_string_put(all->mlx_ptr, all->win_ptr, all->rx / 2, 25, WHITE_PIXEL, "100%");
	return (0);
}

void	sort_sprites(t_all *all)
{
	int	i;
	int	j;
	t_sprite	swap;
	i = -1;
	if (all->numsprites < 2)
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

int		raycast(t_all *all)
{
	int		x;
	int		y;
	int		d;
	double	Zbuffer[all->rx];
	double	invdet;
	double	transformx;
	double	transformy;
	double	spritex;
	double	spritey;
	int		stripe;
	int		spritescreenx;
	int		spritewidth;
	int		spriteheight;
	int		drawstartx;
	int		drawstarty;
	int		drawendx;
	int		drawendy;
	int		i;

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
			if ((all->ray.map_y < all->map_height && all->ray.map_x < all->map_width_max) || (all->ray.map_y >= 0 && all->ray.map_x >= 0))
			{
				if (all->map[all->ray.map_y][all->ray.map_x] == '1')
					all->ray.hit = 1;
			}
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
	/*
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
	*/
		if (all->ray.side == 0)// && all->ray.step_x == -1)
		{
			render_tex_e(all, x, all->ray.drawstart);
		}
		else if (all->ray.side == 0)// && all->ray.step_x == 1)
		{
			render_tex_w(all, x, all->ray.drawstart);
		}
		else if (all->ray.side == 1)// && all->ray.step_y == -1)
		{
			render_tex_s(all, x, all->ray.drawstart);
		}
		else if (all->ray.side == 1)// && all->ray.step_y == 1)
		{
			render_tex_n(all, x, all->ray.drawstart);
		}
		Zbuffer[x] = all->ray.perpwalldist;
	}
/*******************************************************************************
******************************   SPRITE   **************************************
*******************************************************************************/
	i = -1;
	while (++i < all->numsprites)
	{
		all->sprite[i].dist = ((all->player.posx - all->sprite[i].x) * (all->player.posx - all->sprite[i].x)
				+ (all->player.posy - all->sprite[i].y) * (all->player.posy - all->sprite[i].y));
	}
	i = -1;
	sort_sprites(all);
	i = -1;
	while (++i < all->numsprites)
	{
		spritex = all->sprite[i].x - all->player.posx + 0.5;
		spritey = all->sprite[i].y - all->player.posy + 0.5;
		invdet = 1.0 / (all->player.planx * all->player.diry - all->player.dirx * all->player.plany);
		transformx = invdet * (all->player.diry * spritex - all->player.dirx * spritey);
		transformy = invdet * (-all->player.plany * spritex + all->player.planx * spritey);
		spritescreenx = (int)(all->rx / 2) * (1 + transformx / transformy);
		spriteheight = abs((int)(all->ry / transformy));
		drawstarty = -spriteheight / 2 + all->ry / 2;
		if (drawstarty < 0)
			drawstarty = 0;
		drawendy = spriteheight / 2 + all->ry / 2;
		if (drawendy >= all->ry)
			drawendy = all->ry - 1;
		spritewidth = abs((int)(all->ry / transformy));
		drawstartx = -spritewidth / 2 + spritescreenx;
		if (drawstartx < 0)
			drawstartx = 0;
		drawendx = spritewidth / 2 + spritescreenx;
		if (drawendx >= all->rx)
			drawendx= all->rx - 1;
		stripe = drawstartx;
		while (stripe < drawendx)
		{
			all->texture.tex_x = (int)(256 * (stripe - (-spritewidth / 2 + spritescreenx)) * SPRITE_WIDTH / spritewidth) / 256; // cast
			if (transformy > 0 && stripe > 0 && stripe < all->rx && transformy < Zbuffer[stripe])
			{
				y = drawstarty;
				while (y < drawendy)
				{
					d = y * 256 - all->ry * 128 + spriteheight * 128;
					all->texture.tex_y = ((d * SPRITE_HEIGHT) / spriteheight) / 256;
					all->texture.color = *((int *)all->sprite_img.addr + (SPRITE_WIDTH * all->texture.tex_y + all->texture.tex_x));
					if ((all->texture.color & 0x00FFFFFF) != 0)
						img_pix_put(&all->img, stripe, y, all->texture.color);
					y++;
				}
			}
			stripe++;
		}
	}
	return (0);
}
