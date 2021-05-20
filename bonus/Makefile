## Name of Project

NAME = cub3D

MAP = maps/skull.cub

## Color for compilating (pink)

COLOR = \0033[1;35m

## List of Directories

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

DEBUG = -g3 #-fsanitize=address

FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) #-D_REENTRANT

INC = $(./$(INC_DIR)/-I%.h)

CC = clang $(FLAGS) $(INC)

LIB_DIR = libft

LIBX_DIR = minilibx

INSTALL_LIBX = $(shell cd minilibx && sh configure && cd ..)

GAME_FT			= game_control_bonus move_player_bonus rotate_player_bonus save_bonus \
				  loops attack_loops dragon menu_control fight heal

PARSING_FT		= check_resolution_bonus dispatcher \
				  pars_map_bonus check_file_format_bonus check_map_open_bonus pars_file_bonus \
				  pars_path_bonus path_floor_skybox path_sprite_seven_to_nine path_sprite_two_to_six

RAYCASTING_FT	= raycasting_bonus sprite_bonus raycasting_utils_bonus floor_raycasting

UTILS_FT		= check_error_bonus cub_utils_bonus free_bonus mlx_utils_bonus \
				  load_img go_to_next_lvl

RENDERS_FT		= render_texture_bonus render_menu render_raycasting render_attack \
				  render_life mini_map render_weapon

SRC_FT 			= main_bonus

## List of Utilities

SRC = $(SRC_FT:%=$(SRC_DIR)/%.c) \
	$(GAME_FT:%=$(SRC_DIR)/$(GAME_DIR)/%.c) \
	$(PARSING_FT:%=$(SRC_DIR)/$(PARSING_DIR)/%.c) \
	$(RAYCASTING_FT:%=$(SRC_DIR)/$(RAYCASTING_DIR)/%.c) \
	$(UTILS_FT:%=$(SRC_DIR)/$(UTILS_DIR)/%.c) \
	$(RENDERS_FT:%=$(SRC_DIR)/$(RENDERS_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(OBJ_DIR) \
	$(GAME_DIR:%=$(OBJ_DIR)/%) \
	$(PARSING_DIR:%=$(OBJ_DIR)/%) \
	$(RAYCASTING_DIR:%=$(OBJ_DIR)/%) \
	$(UTILS_DIR:%=$(OBJ_DIR)/%) \
	$(RENDERS_DIR:%=$(OBJ_DIR)/%)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)$@ \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) -c $< -o $@
	@echo "$(COLOR)$(@:$(OBJ_DIR)/%=%) \033[100D\033[40C\0033[1;32m[Compiled]\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC) $(INC)
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@echo $(INSTALL_LIBX)
	@make -s -C $(LIB_DIR)
	@$(CC) $(OBJ) -Llibft -lft -Lminilibx -lmlx -lmlx_Linux -lXext -lX11 -lm -o $@
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"

bonus:

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -s -C $(LIB_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@make clean -s -C $(LIBX_DIR)
	@make fclean -s -C $(LIB_DIR)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

re: fclean all

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

.PHONY: all clean fclean re coffee play
