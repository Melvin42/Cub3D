/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 07:34:31 by melperri          #+#    #+#             */
/*   Updated: 2021/04/28 08:31:16 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

/*
********************************************************************************
**================================> DEFINE <==================================**
********************************************************************************
*/

# define CUB3D_H
# define STR_MLX_ERROR "Error\nmlx error.\n"
# define STR_PARS_ERROR "Error\nFile .cub isn't well formated.\n"
# define STR_FOLDER_ERROR "Error\nBad path, or .cub is a folder or empty.\n"
# define STR_MALLOC_ERROR "Error\nA malloc doesn't work fine.\n"
# define STR_ARG_ERROR "Error\nBad number of arguments.\n"
# define STR_FD_ERROR "Error\nFile descriptor = -1.\n"
# define STR_MAP_ERROR "Error\nThere is a problem in the map.\n"
# define STR_RES_ERROR "Error\nBad resolution.\n"
# define STR_NAME_ERROR "Error\nmap isn't a .cub.\n"
# define STR_SAVE_ERROR "Error\nthird argument isn't --save.\n"
# define STR_PATH_ERROR "Error\nBad texture or sprite path.\n"
# define STR_EMPTY_LINE_ERROR "Error\nEmpty line in the map.\n"
# define STR_NO_PLAYER_ERROR "Error\nThere is no player.\n"
# define MOVESPEED 0.1
# define ROTSPEED 0.1
# define WHITE_PIXEL 0XFFFFF
# define RED_PIXEL 0XFF0000

/*
********************************************************************************
**===============================> INCLUDE <==================================**
********************************************************************************
*/

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/X.h>
# include <stdint.h>
# include <math.h>
# include <linux/kernel.h>

/*
********************************************************************************
**================================> ENUM <====================================**
********************************************************************************
*/

enum	e_error
{
	NO_PLAYER_ERROR = -13,
	EMPTY_LINE_ERROR,
	PATH_ERROR,
	SAVE_ERROR,
	NAME_ERROR,
	RES_ERROR,
	MAP_ERROR,
	FOLDER_ERROR,
	MLX_ERROR,
	PARS_ERROR,
	MALLOC_ERROR,
	ARG_ERROR,
	FD_ERROR,
	SUCCESS,
};

/*
********************************************************************************
**==============================> STRUCT <====================================**
********************************************************************************
*/

typedef struct	s_bmp_header
{
	uint32_t	size;
	uint16_t	reserved1;
	uint16_t	reserved2;
	uint32_t	offset;
	uint32_t	dib_header_size;
	int32_t		width_px;
	int32_t		height_px;
	uint16_t	num_planes;
	uint16_t	bits_per_pixel;
	uint32_t	compression;
	uint32_t	image_size_bytes;
	int32_t		x_resolution_ppm;
	int32_t		y_resolution_ppm;
	uint32_t	num_colors;
	uint32_t	important_colors;

}				t_bmp_header;

typedef struct	s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			res_x;
	int			res_y;
}				t_img;

typedef struct	s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct	s_player
{
	int			flag;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		camerax;
	double		raydirx;
	double		raydiry;
}				t_player;

typedef struct	s_ray
{
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perpwalldist;
	double		step;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			drawstart;
	int			drawend;
	int			lineheight;
	int			hit;
	int			side;
}				t_ray;

typedef struct	s_texture
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			color;
}				t_texture;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			num;
	double		dist;
	int			texture;
}				t_sprite;

typedef struct	s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			rx;
	int			ry;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*path_sprite_two;
	char		*path_sprite_three;
	char		*path_sprite_four;
	char		*path_sprite_five;
	char		*path_sprite_six;
	char		*path_sprite_seven;
	char		*path_sprite_eight;
	char		*path_sprite_nine;
	int			numsprites;
	char		**map;
	int			map_malloc_size;
	int			map_height;
	int			map_width_max;
	double		invdet;
	double		transformx;
	double		transformy;
	double		spritex;
	double		spritey;
	int			stripe;
	int			spritescreenx;
	int			spritewidth;
	int			spriteheight;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	double		*zbuffer;
	int			ceiling_color;
	int			floor_color;
	int			flag_map;
	int			index;
	int			tex_width;
	int			tex_height;
	int			dragon_frame;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	t_sprite	*sprite;
	t_img		img;
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
	t_img		sprite_two_img;
	t_img		sprite_three_img;
	t_img		sprite_four_img;
	t_img		sprite_five_img;
	t_img		sprite_six_img;
	t_img		sprite_seven_img;
	t_img		sprite_eight_img;
	t_img		sprite_dragon_one;
	t_img		sprite_dragon_two;
	t_img		sprite_dragon_three;
	t_img		sprite_dragon_four;
	t_img		sprite_dragon_five;
	t_img		sprite_dragon_six;
	t_img		sprite_dragon_seven;
	t_img		sprite_dragon_eight;
	t_img		sprite_dragon_nine;
	t_img		sprite_dragon_ten;
	t_rgb		floor;
	t_rgb		ceiling;
}				t_all;

/*
********************************************************************************
**=============================> PARSING <====================================**
********************************************************************************
*/

int				check_map_name(t_all *all, char *arg);
int				check_xpm_path(t_all *all, char *path);

int				count_line(int fd, t_all *all);
int				dispatcher(char *line, t_all *all);
int				ft_pars_file(t_all *all, char **av);

int				check_north_path(char *line, t_all *all);
int				check_south_path(char *line, t_all *all);
int				check_west_path(char *line, t_all *all);
int				check_east_path(char *line, t_all *all);
int				check_sprite_two_path(char *line, t_all *all);
int				check_sprite_three_path(char *line, t_all *all);
int				check_sprite_four_path(char *line, t_all *all);
int				check_sprite_five_path(char *line, t_all *all);
int				check_sprite_six_path(char *line, t_all *all);
int				check_sprite_seven_path(char *line, t_all *all);
int				check_sprite_eight_path(char *line, t_all *all);
int				check_sprite_nine_path(char *line, t_all *all);

int				check_floor_color(char *line, t_all *all);
int				check_ceiling_color(char *line, t_all *all);
int				check_rgb(t_all *all);
int				check_color_value(t_all *all, int color);

int				check_resolution_path(char *line, t_all *all);
int				check_resolution_value(t_all *all);
void			rectify_resolution_value(t_all *all);

int				extract_map(char *line, t_all *all);
int				check_map(t_all *all);
int				pos_sprites(t_all *all);

int				is_map_open(t_all *all);

int				ft_only_space(char *line);
void			replace_space_by_one(t_all *all);

/*
********************************************************************************
**=============================>   MLX   <====================================**
********************************************************************************
*/
int				encode_rgb(int red, int green, int blue);
void			img_pix_put(t_img *img, int x, int y, int color);
int				ft_new_mlx_img(t_all *all, t_img *img, int res_x, int res_y);
int				ft_mlx_xpm_to_img(t_all *all, t_img *tex, char *path);
int				ft_load_all_img(t_all *all);

/*
********************************************************************************
**=============================>   RENDER  <==================================**
********************************************************************************
*/

void			render_background(t_all *all);
int				render_tex_n(t_all *all, int x, int y);
int				render_tex_s(t_all *all, int x, int y);
int				render_tex_e(t_all *all, int x, int y);
int				render_tex_w(t_all *all, int x, int y);
void			ft_render_side(t_all *all, int x);
int				render(t_all *all);

/*
********************************************************************************
**============================>  RAYCASTING  <================================**
********************************************************************************
*/

void			ft_set_raycast_vars(t_all *all);
void			raycast(t_all *all);
void			ft_chose_tex(t_all *all);

/*
********************************************************************************
**==============================>  SPRITE  <==================================**
********************************************************************************
*/

void			sort_sprites(t_all *all);

void			render_sprite(t_all *all);

void			ft_calc_sprite_dist(t_all *all);
void			ft_set_sprite_vars(t_all *all, int i);
void			ft_calc_sprite_ray(t_all *all);
void			ft_put_sprite_pix(t_all *all, int stripe, t_img sprite_img);
void			ft_search_pix_in_sprite(t_all *all, t_img sprite_img);

/*
********************************************************************************
**==============================>   GAME   <==================================**
********************************************************************************
*/

int				ft_exit_cross(t_all *all);
int				handle_keypress(int keysym, t_all *all);

void			move_up(t_all *all);
void			move_down(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);

void			rotate_left(t_all *all);
void			rotate_right(t_all *all);

int				ft_save(t_all *all);

/*
********************************************************************************
**==============================>   ERROR   <=================================**
********************************************************************************
*/

int				check_fd(t_all *all, int fd);
int				check_error(t_all *all, int error);

void			ft_free_all(t_all *all);

/*
********************************************************************************
**==============================>   BONUS   <=================================**
********************************************************************************
*/

int				render_life(t_all *all);
int				menu(t_all *all);

#endif
