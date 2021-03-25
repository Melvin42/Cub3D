#ifndef CUB3D_H
# define CUB3D_H
# define MLX_ERROR -5
# define PARS_ERROR -4
# define MALLOC_ERROR -3
# define ARG_ERROR -2 
# define FD_ERROR -1
# define STR_MLX_ERROR "Error\nmlx error.\n"
# define STR_PARS_ERROR "Error\nFile .cub isn't well formated.\n"
# define STR_MALLOC_ERROR "Error\nA malloc doesn't work fine.\n"
# define STR_ARG_ERROR "Error\nBad number of arguments.\n"
# define STR_FD_ERROR "Error\nFile descriptor = -1.\n"
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# include "libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdint.h>

/*******************************************************************************
**==============================> STRUCT <====================================**
*******************************************************************************/

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}				t_rect;

typedef struct	s_rgb
{
	int	red;
	int	green;
	int	blue;
}				t_rgb;

typedef struct	s_player
{
	int flag;
	int	posx;
	int	posy;
	int	dirx;
	int	diry;
}				t_player;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		rx;
	int 	ry;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	**map;
	t_player	player;
	t_img	img;
	t_rgb	floor;
	t_rgb	ceiling;
}				t_data;

/*******************************************************************************
**=============================> PARSING <====================================**
*******************************************************************************/

int				check_error(int i);
int				check_resolution(char *line, t_data *data);
int				check_north_path(char *line, t_data *data);
int				check_south_path(char *line, t_data *data);
int				check_west_path(char *line, t_data *data);
int				check_east_path(char *line, t_data *data);
int				check_sprite_path(char *line, t_data *data);
int				check_floor_color(char *line, t_data *data);
int				check_ceiling_color(char *line, t_data *data);
int				extract_map(char *line, t_data *data, int n);
int				check_map(t_data *data);
void			set_player(t_data *data, int x, int y);
int				dispatcher(char *line, t_data *data, int n);
int 			only_space(char *line);
int				read_file(int n, int fd, t_data *data);
int				count_line(int fd);
void			free_data(t_data *data);

/*******************************************************************************
**=============================>   MLX   <====================================**
*******************************************************************************/

int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, void *data);
int		encode_rgb(uint8_t red, uint8_t green, uint8_t blue);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, t_data *data, int color);
int		render(t_data *data);

#endif
