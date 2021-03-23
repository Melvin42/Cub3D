#!/bin/bash

clang -Wall -Wextra -Werror pars_map.c libft/get_next_line.c libft/libft.a -lmlx -lXext -lX11 && ./a.out map.cub
