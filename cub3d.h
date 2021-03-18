#ifndef CUB3D_H
# define CUB3D_H
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define ERROR_ARG -2 
# define MLX_ERROR 1
# define STR_ERROR_ARG "Error\nBad number of arguments.\n"
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0x0000

# include "libft/libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct	s_data
{
		void	*mlx_ptr;
		void	*win_ptr;
}				t_data;

typedef struct	s_rect
{
  int	x;
  int	y;
  int	width;
  int	height;
  int	color;
}				t_rect;

#endif
