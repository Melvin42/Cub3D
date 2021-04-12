#ifndef CUB3D_H
# define CUB3D_H
# define RES_ERROR -8
# define MAP_ERROR -7
# define FOLDER_ERROR -6
# define MLX_ERROR -5
# define PARS_ERROR -4
# define MALLOC_ERROR -3
# define ARG_ERROR -2 
# define FD_ERROR -1
# define SUCCESS 1
# define STR_MLX_ERROR "Error\nmlx error.\n"
# define STR_PARS_ERROR "Error\nFile .cub isn't well formated.\n"
# define STR_FOLDER_ERROR "Error\n.cub is a folder.\n"
# define STR_MALLOC_ERROR "Error\nA malloc doesn't work fine.\n"
# define STR_ARG_ERROR "Error\nBad number of arguments.\n"
# define STR_FD_ERROR "Error\nFile descriptor = -1.\n"
# define STR_MAP_ERROR "Error\nThere is a problem in the map.\n"
# define STR_RES_ERROR "Error\nBad resolution.\n"
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define CYAN_PIXEL 0xFFFF
# define YELLOW_PIXEL 0xFFFF00
# define GREY_PIXEL 0x808080
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x0
# define TEXTURE_WIDTH 256
# define TEXTURE_HEIGHT 256
# define SPRITE_WIDTH 1024
# define SPRITE_HEIGHT 1024

# include "libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <X11/X.h>
# include <stdint.h>
# include <math.h>

/*******************************************************************************
**==============================> STRUCT <====================================**
*******************************************************************************/

typedef struct	s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	uint32_t		color;
}				t_rect;

typedef struct	s_rgb
{
	int			red;
	int			green;
	int			blue;
}				t_rgb;

typedef struct	s_player
{
	int 		flag;
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
	double		dist;
	int			texture;
}				t_sprite;

typedef struct	s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			rx;
	int 		ry;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*path_sprite;
	int			numsprites;
	char		**map;
	int			map_malloc_size;
	int			map_height;
	int			map_width_max;
	t_player	player;
	t_ray		ray;
	t_texture	texture;
	t_sprite	*sprite;
	t_img		menu;
	t_img		img;
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
	t_img		sprite_img;
	t_rgb		floor;
	t_rgb		ceiling;
}				t_all;

/*******************************************************************************
**=============================> PARSING <====================================**
*******************************************************************************/

int				check_error(int i);
int				check_resolution(char *line, t_all *all);
int				check_north_path(char *line, t_all *all);
int				check_south_path(char *line, t_all *all);
int				check_west_path(char *line, t_all *all);
int				check_east_path(char *line, t_all *all);
int				check_sprite_path(char *line, t_all *all);
int				check_floor_color(char *line, t_all *all);
int				check_ceiling_color(char *line, t_all *all);
int				extract_map(char *line, t_all *all);
int				is_map_open(t_all *all);
int				check_map(t_all *all);
int				set_player(t_all *all, int x, int y);
int				dispatcher(char *line, t_all *all);
int 			only_space(char *line);
int				read_file(int fd, t_all *all);
int				count_line(int fd, t_all *all);
int				pos_sprites(t_all *all);
void			free_all(t_all *all);

/*******************************************************************************
**=============================>   MLX   <====================================**
*******************************************************************************/

int				handle_keypress(int keysym, t_all *all);
int				encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void			img_pix_put(t_img *img, int x, int y, int color);

/*******************************************************************************
**=============================>   RENDER  <==================================**
*******************************************************************************/

void			render_background(t_img *img, t_all *all, int color);
int				render_tex_n(t_all *all, int x, int y);
int				render_tex_s(t_all *all, int x, int y);
int				render_tex_e(t_all *all, int x, int y);
int				render_tex_w(t_all *all, int x, int y);
int				render(t_all *all);
int				menu(t_all *all);
int				raycast(t_all *all);

#endif
