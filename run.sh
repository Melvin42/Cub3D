#!/bin/bash

clang -Wall -Wextra -Werror -g -lm -fsanitize=address main.c bonus/bonus.c render_texture.c check_error.c color.c pars_path.c pars_map.c pars_file.c cub_utils.c mlx_utils.c move_player.c rotate_player.c game_control.c raycasting.c raycasting_utils.c sprite.c save.c libft/get_next_line.c libft/libft.a -lmlx -lXext -lX11 && ./a.out maps/map.cub | cat -e
