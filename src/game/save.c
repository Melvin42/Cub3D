/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:30:59 by melperri          #+#    #+#             */
/*   Updated: 2021/05/24 13:18:16 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_init_save(t_all *all)
{
	all->mlx_ptr = mlx_init();
	if (all->mlx_ptr == NULL)
		return (check_error(all, MLX_ERROR));
	if (ft_load_all_img(all) < 0)
		return (-1);
	return (0);
}

static void	fill_header_part_two(t_bmp_header *bmp, char header[54])
{
	header[18] = (unsigned char)(bmp->width_px);
	header[19] = (unsigned char)(bmp->width_px >> 8);
	header[20] = (unsigned char)(bmp->width_px >> 16);
	header[21] = (unsigned char)(bmp->width_px >> 24);
	header[22] = (unsigned char)(bmp->height_px);
	header[23] = (unsigned char)(bmp->height_px >> 8);
	header[24] = (unsigned char)(bmp->height_px >> 16);
	header[25] = (unsigned char)(bmp->height_px >> 24);
	header[26] = (unsigned char)(bmp->num_planes);
	header[27] = (unsigned char)(bmp->num_planes >> 8);
	header[28] = (unsigned char)(bmp->bits_per_pixel);
	header[29] = (unsigned char)(bmp->bits_per_pixel >> 8);
	header[34] = (unsigned char)(bmp->image_size_bytes);
	header[35] = (unsigned char)(bmp->image_size_bytes >> 8);
	header[36] = (unsigned char)(bmp->image_size_bytes >> 16);
	header[37] = (unsigned char)(bmp->image_size_bytes >> 24);
}

static void	fill_header_part_one(t_bmp_header *bmp, char header[54])
{
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(bmp->size);
	header[3] = (unsigned char)(bmp->size >> 8);
	header[4] = (unsigned char)(bmp->size >> 16);
	header[5] = (unsigned char)(bmp->size >> 24);
	header[10] = (unsigned char)(bmp->offset);
	header[11] = (unsigned char)(bmp->offset >> 8);
	header[12] = (unsigned char)(bmp->offset >> 16);
	header[13] = (unsigned char)(bmp->offset >> 24);
	header[14] = (unsigned char)(bmp->dib_header_size);
	header[15] = (unsigned char)(bmp->dib_header_size >> 8);
	header[16] = (unsigned char)(bmp->dib_header_size >> 16);
	header[17] = (unsigned char)(bmp->dib_header_size >> 24);
	fill_header_part_two(bmp, header);
}

static void	set_header_struct(t_all *all, t_bmp_header *bmp, char header[54])
{
	bmp->size = (all->rx * all->ry * 4) + 54;
	bmp->reserved1 = 0;
	bmp->reserved2 = 0;
	bmp->offset = 54;
	bmp->dib_header_size = 40;
	bmp->width_px = all->rx;
	bmp->height_px = all->ry;
	bmp->num_planes = 1;
	bmp->bits_per_pixel = 32;
	bmp->compression = 0;
	bmp->image_size_bytes = all->rx * all->ry * 4;
	bmp->x_resolution_ppm = 0;
	bmp->y_resolution_ppm = 0;
	bmp->num_colors = 0;
	bmp->important_colors = 0;
	fill_header_part_one(bmp, header);
}

int	ft_save(t_all *all)
{
	t_bmp_header	bmp;
	int				i;
	int				fd;
	char			header[54];

	ft_bzero(header, 54);
	set_header_struct(all, &bmp, header);
	ft_init_save(all);
	render_background(all);
	raycast(all);
	fd = open("save.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	write(fd, header, 54);
	i = all->ry;
	while (--i >= 0)
		write(fd, &(all->img.addr[i * all->rx * 4]), all->rx * 4);
	close(fd);
	return (0);
}
