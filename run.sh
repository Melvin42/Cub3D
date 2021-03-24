#!/bin/bash

clang -Wall -Wextra -Werror main.c pars_path.c pars_map.c pars_file.c libft/get_next_line.c libft/libft.a -lmlx -lXext -lX11 && ./a.out map.cub | cat -e
