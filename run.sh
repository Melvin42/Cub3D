#!/bin/bash

clang -Wall -Wextra -Werror -lm main.c pars_path.c pars_map.c pars_file.c mlx_utils.c libft/get_next_line.c libft/libft.a -lmlx -lXext -lX11 && ./a.out little.cub | cat -e
