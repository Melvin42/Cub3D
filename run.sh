#!/bin/bash

clang -Wall -Wextra -Werror -g -lm -fsanitize=address main.c bonus/bonus.c render_texture.c pars_path.c pars_map.c pars_file.c mlx_utils.c move_player.c rotate_player.c game_control.c raycasting.c libft/get_next_line.c libft/libft.a -lmlx -lXext -lX11 && ./a.out maps/map.cub | cat -e
