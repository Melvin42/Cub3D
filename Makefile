## Name of Project

NAME = cub3D

MAP = maps/map.cub

## Color for compilating (pink)

COLOR = \0033[1;35m

## List of Directories

INC_DIR = inc
OBJ_DIR = obj
SRC_DIR = src

# Add dirs here

TEMPLATE_DIR = template_dir

## Compilating Utilities

#FAST = -Ofast

#DEBUG = -g3 -fsanitize=address

FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT

INC = $(./$(INC_DIR)/-I%.h)

CC = clang $(FLAGS) $(INC)

LIB_NAME = libft/libft.a

LIB_DIR = libft

#TEMPLATE_FT = template_file

SRC_FT = main check_error cub_utils move_player pars_file pars_path \
		raycasting_utils rotate_player sprite color game_control \
		mlx_utils pars_map raycasting render_texture save

## List of Utilities

SRC = $(SRC_FT:%=$(SRC_DIR)/%.c) 
	#$(TEMPLATE_FT:%=$(SRC_DIR)/$(TEMPLATE_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(OBJ_DIR) 
	#$(TEMPLATE_DIR:%=$(OBJ_DIR)/%)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)$@ \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@#@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) -c $< -o $@
	@echo "$(COLOR)$(@:$(OBJ_DIR)/%=%) \033[100D\033[40C\0033[1;32m[Compiled]\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC) $(INC)
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@make -s -C $(LIB_DIR)
	@$(CC) -lm $(OBJ) $(LIB_NAME) -lmlx -lXext -lX11 -o $@
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -s -C $(LIB_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIB_DIR)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

re: fclean all


define print_aligned_coffee
    @t=$(NAME); \
	l=$${#t};\
	i=$$((8 - l / 2));\
	echo "          \0033[1;32m\033[3C\033[$${i}CAnd Your program \"$(NAME)\" "
endef

coffee: all clean
	@echo ""
	@echo "                             {"
	@echo "                          {   }"
	@echo "                           }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "                        \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "                       \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "                       \0033[1;34m| -.._____..- |"
	@echo "                       |             ;--."
	@echo "                       |            (__  \ "
	@echo "                       |             | )  )"
	@echo "                       |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "                       |             /  / "
	@echo "                       |            (  / "
	@echo "                       \             | "
	@echo "                         -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C                    Take Your Coffee"
	$(call print_aligned_coffee)

play: coffee
	@echo ""         
	@echo ""         
	@echo "                             \0033[0;41m    \0033[0m"         
	@echo "                        \0033[0;41m           \0033[0m"         
	@echo "           \0033[0;41m  \0033[0m        \0033[0;41m                  \0033[0m"         
	@echo "            \0033[0;41m     \0033[0m \0033[0;41m                        \0033[0m"         
	@echo "            \0033[0;41m                                 \0033[0m  \0033[0;41m    \0033[0m"         
	@echo "           \0033[0;41m                                        \0033[0m"         
	@echo "         \0033[0;41m               \0033[0m            \0033[0;41m              \0033[0m"         
	@echo "       \0033[0;41m             \0033[0m      \0033[1;37mWORLD OF\0033[1;34m   \0033[0;41m            \0033[0m"         
	@echo "    \0033[0;41m              \0033[0m        \0033[1;37mWARCUB3D\0033[1;34m    \0033[0;41m             \0033[0m"         
	@echo "  \0033[0;41m              \0033[0m             \0033[0;41m \0033[0m            \0033[0;41m             \0033[0m"         
	@echo "    \0033[0;41m            \0033[0m           \0033[0;41m      \0033[0m          \0033[0;41m             \0033[0m"         
	@echo "       \0033[0;41m        \0033[0m          \0033[0;41m          \0033[0m        \0033[0;41m        \0033[0m"         
	@echo "         \0033[0;41m      \0033[0m        \0033[0;41m              \0033[0m      \0033[0;41m      \0033[0m"         
	@echo "\0033[0;41m  \0033[0m        \0033[0;41m      \0033[0m       \0033[0;41m             \0033[0m      \0033[0;41m       \0033[0m         \0033[0;41m \0033[0m"         
	@echo " \0033[0;41m      \0033[0m \0033[0;41m \0033[0m \0033[0;41m       \0033[0m        \0033[0;41m         \0033[0m        \0033[0;41m        \0033[0m    \0033[0;41m     \0033[0m"         
	@echo "  \0033[0;41m                 \0033[0m         \0033[0;41m    \0033[0m         \0033[0;41m                 \0033[0m"         
	@echo "    \0033[0;41m                \0033[0m                    \0033[0;41m                 \0033[0m"         
	@echo "     \0033[0;41m     \0033[0m   \0033[0;41m        \0033[0m                  \0033[0;41m                \0033[0m"         
	@echo "                 \0033[0;41m      \0033[0m              \0033[0;41m    \0033[0m          \0033[0;41m  \0033[0m"         
	@echo "                   \0033[0;41m     \0033[0m            \0033[0;41m    \0033[0m"         
	@echo "                     \0033[0;41m    \0033[0m         \0033[0;41m    \0033[0m"         
	@echo "                      \0033[0;41m    \0033[0m       \0033[0;41m     \0033[0m"         
	@echo "                      \0033[0;41m    \0033[0m      \0033[0;41m           \0033[0m"         
	@echo "                     \0033[0;41m      \0033[0m      \0033[0;41m         \0033[0m"         
	@echo "                 \0033[0;41m          \0033[0m      \0033[0;41m       \0033[0m"         
	@echo "                  \0033[0;41m         \0033[0m       \0033[0;41m     \0033[0m"         
	@echo "                    \0033[0;41m       \0033[0m       \0033[0;41m   \0033[0m"         
	@echo "                     \0033[0;41m      \0033[0m       \0033[0;41m  \0033[0m"         
	@echo "                       \0033[0;41m    \0033[0m"         
	@echo "                        \0033[0;41m  \0033[0m"         
	@echo "                         \0033[0;41m \0033[0m"         
	@echo ""
	@echo ""
	./$(NAME) $(MAP)

.PHONY: all clean fclean re coffee play
