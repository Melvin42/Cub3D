#include "../inc/cub3d.h"

void		img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void		render_background(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->ry / 2)
	{
		j = 0;
		while (j < all->rx)
			img_pix_put(&all->img, j++, i, all->ceiling_color);
		++i;
	}
	while (i < all->ry)
	{
		j = 0;
		while (j < all->rx)
			img_pix_put(&all->img, j++, i, all->floor_color);
		++i;
	}
}

int			ft_new_mlx_img(t_all *all, t_img *img, int res_x, int res_y)
{
	img->mlx_img = mlx_new_image(all->mlx_ptr, res_x, res_y);
	if (img->mlx_img == NULL)
		return (check_error(all, MLX_ERROR));
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
								&img->line_len, &img->endian);
	if (img->addr == NULL)
		return (check_error(all, MLX_ERROR));
	return (0);
}

int			ft_mlx_xpm_to_img(t_all *all, t_img *tex, char *path)
{
	int	res_x;
	int	res_y;

	tex->mlx_img = mlx_xpm_file_to_image(all->mlx_ptr, path, &res_x, &res_y);
	if (tex->mlx_img == NULL)
		return (check_error(all, MLX_ERROR));
	tex->addr = mlx_get_data_addr(tex->mlx_img, &tex->bpp,
								&tex->line_len, &tex->endian);
	if (tex->addr == NULL)
		return (check_error(all, MLX_ERROR));
	return (0);
}

int			ft_load_all_img(t_all *all)
{
	if (ft_new_mlx_img(all, &all->img, all->rx, all->ry) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_n, all->north) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_s, all->south) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_e, all->east) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->tex_w, all->west) < 0)
		return (check_error(all, MLX_ERROR));
	if (ft_mlx_xpm_to_img(all, &all->sprite_img, all->path_sprite) < 0)
		return (check_error(all, MLX_ERROR));
	return (0);
}
