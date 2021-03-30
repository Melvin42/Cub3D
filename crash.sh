#!/bin/bash

clang -Wall -Wextra -Werror main.c pars_file.c pars_path.c pars_map.c mlx_utils.c libft/get_next_line.c libft/libft.a -lmlx -lXext -lX11 && ./a.out bad.cub | cat -e
