#ifndef CUB3D_H
# define CUB3D_H
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define PARS_ERROR -4
# define MALLOC_ERROR -3
# define ARG_ERROR -2 
# define FD_ERROR -1
# define MLX_ERROR 1
# define STR_ARG_ERROR "Error\nBad number of arguments.\n"
# define STR_MALLOC_ERROR "Error\nA malloc doesn't work fine.\n"
# define STR_FD_ERROR "Error\nFile descriptor = -1.\n"
# define STR_PARS_ERROR "Error\nFile .cub isn't well formated.\n"
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# include "libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdint.h>

typedef struct	s_img
{
  void	*mlx_img;
  char	*addr;
  int	bpp;
  int	line_len;
  int	endian;
}				t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_data;

typedef struct	s_rect
{
  int	x;
  int	y;
  int	width;
  int	height;
  int	color;
}				t_rect;

typedef struct	s_param
{
	int		rx;
	int 	ry;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*ground;
	char	*ceiling;
	char	**map;
}				t_param;

#endif
