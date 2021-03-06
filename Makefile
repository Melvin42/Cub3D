## Name of Project

NAME = cub3D

NAME_BONUS = cub3D

MAP = maps/map.cub

MAP_BONUS = maps/skull.cub

## Color for compilating (pink)

COLOR = \0033[1;35m

## List of Directories

LIB = libft/libft.a
LIB_DIR = libft
LIBX_DIR = minilibx
BONUS_DIR = bonus
INC_DIR = inc
OBJ_DIR = obj
SRC_DIR	= src

# Add dirs here

GAME_DIR		= game
PARSING_DIR		= parsing
RAYCASTING_DIR	= raycasting
UTILS_DIR		= utils
RENDERS_DIR		= renders

## Compilating Utilities

#FAST = -Ofast

#DEBUG = -g3 #-fsanitize=address

FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT

INC = $(./$(INC_DIR)/-I%.h)

CC = clang $(FLAGS) $(INC)

INSTALL_LIBX = $(shell cd minilibx && sh configure && cd ..)

GAME_FT			= game_control move_player rotate_player save

PARSING_FT		= check_ceiling_color check_floor_color check_resolution \
				  pars_map check_file_format check_map_open pars_file \
				  pars_path

RAYCASTING_FT	= raycasting render_texture sprite

UTILS_FT		= check_error color_utils cub_utils free mlx_utils \
				  raycasting_utils

SRC_FT 			= main

## List of Utilities

SRC = $(SRC_FT:%=$(SRC_DIR)/%.c) \
	$(GAME_FT:%=$(SRC_DIR)/$(GAME_DIR)/%.c) \
	$(PARSING_FT:%=$(SRC_DIR)/$(PARSING_DIR)/%.c) \
	$(RAYCASTING_FT:%=$(SRC_DIR)/$(RAYCASTING_DIR)/%.c) \
	$(UTILS_FT:%=$(SRC_DIR)/$(UTILS_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(OBJ_DIR) \
	$(GAME_DIR:%=$(OBJ_DIR)/%) \
	$(PARSING_DIR:%=$(OBJ_DIR)/%) \
	$(RAYCASTING_DIR:%=$(OBJ_DIR)/%) \
	$(UTILS_DIR:%=$(OBJ_DIR)/%)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

bonus: $(LIB)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"
	@make -s -C $(BONUS_DIR)

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)$@ \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) -c $< -o $@
	@echo "$(COLOR)$(@:$(OBJ_DIR)/%=%) \033[100D\033[40C\0033[1;32m[Compiled]\0033[1;37m"

$(NAME):  $(LIB) $(OBJ_DIRS) $(SRC) $(INC)
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@$(CC) $(OBJ) -Llibft -lft -Lminilibx -lmlx -lmlx_Linux -lXext -lX11 -lm -o $@
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"

$(LIB):
	@make -s -C $(LIB_DIR)
	@echo $(INSTALL_LIBX)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -s -C $(LIBX_DIR)
	@make clean -s -C $(LIB_DIR)
	@make clean -s -C $(BONUS_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"
	@make fclean -s -C $(LIB_DIR)

re:	fclean all

define print_aligned_coffee
    @t=$(NAME); \
	l=$${#t};\
	i=$$((8 - l / 2));\
	echo "             \0033[1;32m\033[3C\033[$${i}CAnd Your program \"$(NAME)\" "
endef

coffee: all clean
	@echo ""
	@echo "                                {"
	@echo "                             {   }"
	@echo "                              }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "                           \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "                          \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "                          \0033[1;34m| -.._____..- |"
	@echo "                          |             ;--."
	@echo "                          |            (__  \ "
	@echo "                          |             | )  )"
	@echo "                          |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "                          |             /  / "
	@echo "                          |            (  / "
	@echo "                          \             | "
	@echo "                            -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C                    Take Your Coffee"
	$(call print_aligned_coffee)

play: coffee
	@echo ""         
	@echo ""         
	@echo "                                \0033[0;41m    \0033[0m"         
	@echo "                           \0033[0;41m           \0033[0m"         
	@echo "              \0033[0;41m  \0033[0m        \0033[0;41m                  \0033[0m"         
	@echo "               \0033[0;41m     \0033[0m \0033[0;41m                        \0033[0m"         
	@echo "               \0033[0;41m                                 \0033[0m  \0033[0;41m    \0033[0m"         
	@echo "              \0033[0;41m                                        \0033[0m"         
	@echo "            \0033[0;41m               \0033[0m            \0033[0;41m              \0033[0m"         
	@echo "          \0033[0;41m             \0033[0m      \0033[1;37mWORLD OF\0033[1;34m   \0033[0;41m            \0033[0m"         
	@echo "       \0033[0;41m              \0033[0m        \0033[1;37mWARCUB3D\0033[1;34m    \0033[0;41m             \0033[0m"         
	@echo "     \0033[0;41m              \0033[0m             \0033[0;41m \0033[0m            \0033[0;41m             \0033[0m"         
	@echo "       \0033[0;41m            \0033[0m           \0033[0;41m      \0033[0m          \0033[0;41m             \0033[0m"         
	@echo "          \0033[0;41m        \0033[0m          \0033[0;41m          \0033[0m        \0033[0;41m        \0033[0m"         
	@echo "            \0033[0;41m      \0033[0m        \0033[0;41m              \0033[0m      \0033[0;41m      \0033[0m"         
	@echo "   \0033[0;41m  \0033[0m        \0033[0;41m      \0033[0m       \0033[0;41m             \0033[0m      \0033[0;41m       \0033[0m         \0033[0;41m \0033[0m"         
	@echo "    \0033[0;41m      \0033[0m \0033[0;41m \0033[0m \0033[0;41m       \0033[0m        \0033[0;41m         \0033[0m        \0033[0;41m        \0033[0m    \0033[0;41m     \0033[0m"         
	@echo "     \0033[0;41m                 \0033[0m         \0033[0;41m    \0033[0m         \0033[0;41m                 \0033[0m"         
	@echo "       \0033[0;41m                \0033[0m                    \0033[0;41m                 \0033[0m"         
	@echo "        \0033[0;41m     \0033[0m   \0033[0;41m        \0033[0m                  \0033[0;41m                \0033[0m"         
	@echo "                    \0033[0;41m      \0033[0m              \0033[0;41m    \0033[0m          \0033[0;41m  \0033[0m"         
	@echo "                      \0033[0;41m     \0033[0m            \0033[0;41m    \0033[0m"         
	@echo "                        \0033[0;41m    \0033[0m         \0033[0;41m    \0033[0m"         
	@echo "                         \0033[0;41m    \0033[0m       \0033[0;41m     \0033[0m"         
	@echo "                         \0033[0;41m    \0033[0m      \0033[0;41m           \0033[0m"         
	@echo "                        \0033[0;41m      \0033[0m      \0033[0;41m         \0033[0m"         
	@echo "                    \0033[0;41m          \0033[0m      \0033[0;41m       \0033[0m"         
	@echo "                     \0033[0;41m         \0033[0m       \0033[0;41m     \0033[0m"         
	@echo "                       \0033[0;41m       \0033[0m       \0033[0;41m   \0033[0m"         
	@echo "                        \0033[0;41m      \0033[0m       \0033[0;41m  \0033[0m"         
	@echo "                          \0033[0;41m    \0033[0m"         
	@echo "                           \0033[0;41m  \0033[0m"         
	@echo "                            \0033[0;41m \0033[0m"         
	@echo ""
	@echo ""
	@./$(NAME) $(MAP)

play-bonus: $(LIB)
	make play -s -C $(BONUS_DIR)

.PHONY: all bonus clean fclean re coffee play play-bonus
