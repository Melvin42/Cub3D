#include "../inc/cub3d.h"

int	ft_init_save(t_all *all)
{
	all->mlx_ptr = mlx_init();
	if (all->mlx_ptr == NULL)
		return (check_error(all, MLX_ERROR));
//	all->win_ptr = mlx_new_window(all->mlx_ptr, all->rx, all->ry, "ta mere");
	if (ft_load_all_img(all) < 0)
		return (-1);
	return (0);
}

int		ft_render_save(t_all *all)
{
	render_background(all);
	raycast(all);
//	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.mlx_img, 0, 0);
	return (0);
}

int	ft_save(t_all *all, char **av)
{
	int	fd;
	
	t_bmp_header	bmp;
	(void)av;
	char	header[54] = {0};
	ft_init_save(all);
	ft_render_save(all);
	fd = open("save.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

	bmp.size = (all->rx * all->ry * 4) + 54;
	bmp.reserved1 = 0;
	bmp.reserved2 = 0;
	bmp.offset = 54;
	bmp.dib_header_size = 40;
	bmp.width_px= all->rx;
	bmp.height_px = all->ry;
	bmp.num_planes = 256;
	bmp.bits_per_pixel = 32;
	bmp.compression = 0;
	bmp.image_size_bytes = all->rx * all->ry * 4;
	bmp.x_resolution_ppm = 0;
	bmp.y_resolution_ppm = 0;
	bmp.num_colors = 0;
	bmp.important_colors = 0;

	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(bmp.size);
	header[3] = (unsigned char)(bmp.size >> 8);
	header[4] = (unsigned char)(bmp.size >> 16);
	header[5] = (unsigned char)(bmp.size >> 24);
	header[6] = (unsigned char)(bmp.reserved1);
	header[7] = (unsigned char)(bmp.reserved1 >> 8);
	header[8] = (unsigned char)(bmp.reserved2);
	header[9] = (unsigned char)(bmp.reserved2 >> 8);
	header[10] = (unsigned char)(bmp.offset);
	header[11] = (unsigned char)(bmp.offset >> 8);
	header[12] = (unsigned char)(bmp.offset >> 16);
	header[13] = (unsigned char)(bmp.offset >> 24);
	header[14] = (unsigned char)(bmp.dib_header_size);
	header[15] = (unsigned char)(bmp.dib_header_size >> 8);
	header[16] = (unsigned char)(bmp.dib_header_size >> 16);
	header[17] = (unsigned char)(bmp.dib_header_size >> 24);
	header[18] = (unsigned char)(bmp.width_px);
	header[19] = (unsigned char)(bmp.width_px >> 8);
	header[20] = (unsigned char)(bmp.width_px >> 16);
	header[21] = (unsigned char)(bmp.width_px >> 24);
	header[22] = (unsigned char)(bmp.height_px);
	header[23] = (unsigned char)(bmp.height_px >> 8);
	header[24] = (unsigned char)(bmp.height_px >> 16);
	header[25] = (unsigned char)(bmp.height_px >> 24);
	header[26] = (unsigned char)(bmp.num_planes);
	header[27] = (unsigned char)(bmp.num_planes >> 8);
	header[28] = (unsigned char)(bmp.bits_per_pixel);
	header[29] = (unsigned char)(bmp.bits_per_pixel >> 8);
	header[30] = (unsigned char)(bmp.compression);
	header[31] = (unsigned char)(bmp.compression >> 8);
	header[32] = (unsigned char)(bmp.compression >> 16);
	header[33] = (unsigned char)(bmp.compression >> 24);
	header[34] = (unsigned char)(bmp.image_size_bytes);
	header[35] = (unsigned char)(bmp.image_size_bytes >> 8);
	header[36] = (unsigned char)(bmp.image_size_bytes >> 16);
	header[37] = (unsigned char)(bmp.image_size_bytes >> 24);
	header[38] = (unsigned char)(bmp.x_resolution_ppm);
	header[39] = (unsigned char)(bmp.x_resolution_ppm >> 8);
	header[40] = (unsigned char)(bmp.x_resolution_ppm >> 16);
	header[41] = (unsigned char)(bmp.x_resolution_ppm >> 24);
	header[42] = (unsigned char)(bmp.y_resolution_ppm);
	header[43] = (unsigned char)(bmp.y_resolution_ppm >> 8);
	header[44] = (unsigned char)(bmp.y_resolution_ppm >> 16);
	header[45] = (unsigned char)(bmp.y_resolution_ppm >> 24);
	header[46] = (unsigned char)(bmp.num_colors);
	header[47] = (unsigned char)(bmp.num_colors >> 8);
	header[48] = (unsigned char)(bmp.num_colors >> 16);
	header[49] = (unsigned char)(bmp.num_colors >> 24);
	header[50] = (unsigned char)(bmp.important_colors);
	header[51] = (unsigned char)(bmp.important_colors >> 8);
	header[52] = (unsigned char)(bmp.important_colors >> 16);
	header[53] = (unsigned char)(bmp.important_colors >> 24);

	write(fd, header, sizeof(header));

	int	i;
	int j;

	j = all->ry;
	while (j > 0)
	{
		i = -1;
		while (++i < all->rx)
		{
			write(fd, &all->img.addr[i], 1);//sizeof(all->img.addr[i]));
		}
		j--;
	}
	close(fd);
	return (0);

}
