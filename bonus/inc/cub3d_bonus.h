/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 07:34:31 by melperri          #+#    #+#             */
/*   Updated: 2021/05/25 16:27:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H

/*
********************************************************************************
**================================> DEFINE <==================================**
********************************************************************************
*/

# define CUB3D_BONUS_H
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
# define ROTSPEED 0.07
# define BLACK_PIXEL 0X0
# define WHITE_PIXEL 0XFFFFFF
# define RED_PIXEL 0XFF0000
# define GREEN_PIXEL 0XFF00
# define GREY_PIXEL 0X808080
# define YELLOW_PIXEL 0XFFFF00

/*
********************************************************************************
**===============================> INCLUDE <==================================**
********************************************************************************
*/

# include "../../libft/inc/libft.h"
# include "../../minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/X.h>
# include <stdint.h>
# include <math.h>

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

typedef struct s_weapon
{
	int			x_start;
	int			y_start;
	int			x_end;
	int			y_end;
}	t_weapon;

typedef struct s_key
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			rot_left;
	int			rot_right;
	int			escape;
	int			sprint;
	int			attack;
	int			menu;
	int			game_over;
	double		cameray;
}	t_key;

typedef struct s_bmp_header
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

}	t_bmp_header;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			res_x;
	int			res_y;
}	t_img;

typedef struct s_player
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
	int			hp;
}	t_player;

typedef struct s_ray
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
}	t_ray;

typedef struct s_floor_ray
{
	float		raydirx0;
	float		raydiry0;
	float		raydirx1;
	float		raydiry1;
	int			p;
	float		posz;
	float		rowdistance;
	float		floorstepx;
	float		floorstepy;
	float		floorx;
	float		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
}	t_floor_ray;

typedef struct s_texture
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			color;
}	t_texture;

typedef struct s_sprite
{
	double		x;
	double		y;
	int			num;
	double		dist;
	int			texture;
}	t_sprite;

typedef struct s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			rx;
	int			ry;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*path_two;
	char		*path_three;
	char		*path_four;
	char		*path_five;
	char		*path_six;
	char		*path_seven;
	char		*path_eight;
	char		*path_nine;
	char		*floor;
	char		*skybox;
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
	char		**av_next;
	t_key		key;
	t_player	player;
	t_weapon	weapon;
	t_ray		ray;
	t_floor_ray	floor_ray;
	t_texture	texture;
	t_sprite	*sprite;
	t_img		img;
	t_img		menu;
	t_img		menu_scale;
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
	t_img		tex_floor;
	t_img		tex_skybox;
	t_img		skybox_scale;
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
	t_img		sprite_axe;
	t_img		mini_map;
}	t_all;

/*
********************************************************************************
**=============================> PARSING <====================================**
********************************************************************************
*/

int				check_save_name(t_all *all, char *arg);
int				check_map_name(t_all *all, char *arg);
int				check_xpm_path(t_all *all, char *path);

int				count_line(int fd, t_all *all);
int				dispatcher(char *line, t_all *all);
int				ft_pars_file(t_all *all, char **av);

int				check_north_path(char *line, t_all *all);
int				check_south_path(char *line, t_all *all);
int				check_west_path(char *line, t_all *all);
int				check_east_path(char *line, t_all *all);
int				check_floor_path(char *line, t_all *all);
int				check_skybox_path(char *line, t_all *all);
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
int				pos_sprites(t_all *all, int i);

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

int				ft_game_over_render(t_all *all);
int				ft_next_lvl_menu_render(t_all *all);
int				ft_menu_render(t_all *all);

void			render_background(t_all *all);
int				render_tex_n(t_all *all, int x, int y);
int				render_tex_s(t_all *all, int x, int y);
int				render_tex_e(t_all *all, int x, int y);
int				render_tex_w(t_all *all, int x, int y);

void			ft_render_side(t_all *all, int x);
void			render_sprite(t_all *all);

int				render(t_all *all);
int				render_attack_one(t_all *all);
int				render_attack_two(t_all *all);
int				render_attack_three(t_all *all);
int				render_attack_four(t_all *all);

int				mini_map_factor(t_all *all);
void			ft_mini_map(t_all *all);

void			render_life(t_all *all);
void			ft_put_string_life(t_all *all);

/*
********************************************************************************
**============================>  RAYCASTING  <================================**
********************************************************************************
*/

void			ft_set_raycast_vars(t_all *all);
void			raycast(t_all *all);
void			ft_chose_tex(t_all *all);
void			ft_skybox(t_all *all);

void			floor_casting(t_all *all);

/*
********************************************************************************
**==============================>  SPRITE  <==================================**
********************************************************************************
*/

void			sort_sprites(t_all *all);

void			ft_calc_sprite_dist(t_all *all);
void			ft_set_sprite_vars(t_all *all, int i);
void			ft_calc_sprite_ray(t_all *all);
void			ft_put_sprite_pix(t_all *all, int stripe, t_img sprite_img);
void			ft_search_pix_in_sprite(t_all *all, t_img sprite_img);

int				ft_render_weapon(t_all *all);

/*
********************************************************************************
**==============================>   GAME   <==================================**
********************************************************************************
*/

int				ft_exit_cross(t_all *all);
void			ft_escape(t_all *all);
void			ft_control(t_all *all);
int				handle_keypress(int keysym, t_all *all);
int				handle_keyrelease(int keysym, t_all *all);

void			move_up(t_all *all);
void			move_down(t_all *all);
void			move_left(t_all *all);
void			move_right(t_all *all);

void			rotate_left(t_all *all);
void			rotate_right(t_all *all);

void			ft_damage(t_all *all);
void			ft_heal(t_all *all);
void			ft_player_attack(t_all *all);
int				ft_save(t_all *all, char **av);

/*
********************************************************************************
**==============================>   ERROR   <=================================**
********************************************************************************
*/

int				check_fd(t_all *all, int fd);
int				check_error(t_all *all, int error);

/*
********************************************************************************
**==============================>   LOOPS   <=================================**
********************************************************************************
*/

void			ft_loop(t_all *all);
void			ft_game_over_loop(t_all *all);
void			ft_menu_loop(t_all *all);
void			ft_next_lvl_loop(t_all *all);
void			ft_attack_one_loop(t_all *all);
void			ft_attack_two_loop(t_all *all);
void			ft_attack_three_loop(t_all *all);
void			ft_attack_four_loop(t_all *all);

/*
********************************************************************************
**==============================>   LOOPS   <=================================**
********************************************************************************
*/

void			ft_game_over_control(t_all *all);
int				ft_game_over_keypress(int keysym, t_all *all);
void			ft_menu_control(t_all *all);
int				ft_menu_keypress(int keysym, t_all *all);
void			ft_next_lvl_menu_control(t_all *all);

void			ft_move_dragon(t_all *all);

/*
********************************************************************************
**==============================>   UTILS   <=================================**
********************************************************************************
*/

void			ft_free_all(t_all *all);
int				ft_load_next_lvl(t_all *all);

int				ft_img_scale(t_img *dst, t_img *src);
int				main(int ac, char **av);

void			ft_free_gnl_line(char **line);
void			ft_finish_gnl(int fd, char *line);

#endif
