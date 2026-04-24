# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/23 17:00:28 by nbaudoin          #+#    #+#              #
#    Updated: 2026/04/23 19:40:25 by nbaudoin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project info

NAME := so_long

# Compiler

CC := cc
FLAGS := -Wall -Werror -Wextra

# Libft files

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a

#MLX

MLX_FILE = libmlx.a
MLX_FLAG = -lX11 -lXext
MLX_PATH = ./minilibx-linux/
MLX_LIB =$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EXEC = $(MLX_LIB) $(MLX_FLAG)

##  Include

INCLUDE_LIBFT = -I . -I ${LIBFT_DIR}
INCLUDE_GNL = -I . -I ${GNL_DIR}
INCLUDE = ${INCLUDE_LIBFT}

# colors

cyan = /bin/echo -e "\x1b[36m\#\# $1\x1b[0m"

# directories

OBJ_DIR = obj
UTILS_DIR = src/utils
MAP_DIR = src/map
EVENT_DIR = src/events
FREE_DIR = src/free
COMPONENTS_DIR = src/components
ERROR_DIR = src/error
ASSET_DIR = textures
PARSE_DIR = src/parse
RENDER_DIR = src/render
GNL_DIR = get_next_line
PLAYER_DIR = src/player

# FILES

GNL_FILES = ${GNL_DIR}/get_next_line.c ${GNL_DIR}/get_next_line_utils.c

ERROR_FILES = ${ERROR_DIR}/print_error.c ${ERROR_DIR}/error_handler.c

EVENT_FILES =  ${EVENT_DIR}/close.c ${EVENT_DIR}/handle_hook.c

FREE_FILES = ${FREE_DIR}/free.c

MAP_FILES = ${MAP_DIR}/map_component_valid.c ${MAP_DIR}/read_map.c \
 			${MAP_DIR}/verify_path_valid.c ${MAP_DIR}/map_outline.c

PARSE_FILES = ${PARSE_DIR}/map_input_check.c

PLAYER_FILES = ${PLAYER_DIR}/animation.c ${PLAYER_DIR}/move.c

RENDER_FILES = ${RENDER_DIR}/window.c ${RENDER_DIR}/init_data.c \
				${RENDER_DIR}/render.c

UTILS_FILES = ${UTILS_DIR}/ft_str_format.c ${UTILS_DIR}/time.c

SRC_FILES = ${ERROR_FILES} ${EVENT_FILES} ${FREE_FILES} ${MAP_FILES} \
	${PARSE_FILES} ${RENDER_FILES} ${UTILS_FILES} ${GNL_FILES} ${PLAYER_FILES}

# Sources

SRC = main.c ${SRC_FILES}

# Object

OBJ = $(SRC:%.c=${OBJ_DIR}/%.o)

# Rules

all: $(NAME)
	@$(call cyan,"Compilation done !")

$(NAME): $(OBJ) $(LIBFT) ${MLX_LIB}
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) ${MLX_EXEC} -o $(NAME)
	@$(call cyan,"Creating so_long...")

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(call cyan,"Compiling libft...")

${MLX_LIB}:
	@$(call cyan, "Compiling mlx...")
	@make -s -C $(MLX_PATH)

clean:
	@$(call cyan,"Cleaning .o files...")
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_PATH) clean
	@$(call cyan,"All .o files are removed !")

fclean: clean
	@$(call cyan,"Cleaning executables and .a files...")
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(call cyan,"All executables and .a files are removed !")

re: fclean all

# BONUS PART

NAME_BONUS = so_long_bonus

# directory

OBJ_DIR_BONUS = obj_bonus
UTILS_DIR_BONUS = src_bonus/utils
MAP_DIR_BONUS = src_bonus/map
EVENT_DIR_BONUS = src_bonus/events
FREE_DIR_BONUS = src_bonus/free
COMPONENTS_DIR_BONUS = src_bonus/components
ERROR_DIR_BONUS = src_bonus/error
ASSET_DIR = textures
PARSE_DIR_BONUS = src_bonus/parse
RENDER_DIR_BONUS = src_bonus/render
GNL_DIR = get_next_line
PLAYER_DIR_BONUS = src_bonus/player

# FILES

ERROR_FILES_BONUS = ${ERROR_DIR_BONUS}/print_error_bonus.c ${ERROR_DIR_BONUS}/error_handler_bonus.c

EVENT_FILES_BONUS =  ${EVENT_DIR_BONUS}/close_bonus.c ${EVENT_DIR_BONUS}/handle_hook_bonus.c

FREE_FILES_BONUS = ${FREE_DIR_BONUS}/free_bonus.c

MAP_FILES_BONUS = ${MAP_DIR_BONUS}/map_component_valid_bonus.c ${MAP_DIR_BONUS}/read_map_bonus.c \
 			${MAP_DIR_BONUS}/verify_path_valid_bonus.c ${MAP_DIR_BONUS}/map_outline_bonus.c

PARSE_FILES_BONUS = ${PARSE_DIR_BONUS}/map_input_check_bonus.c

PLAYER_FILES_BONUS = ${PLAYER_DIR_BONUS}/animation_bonus.c ${PLAYER_DIR_BONUS}/move_bonus.c

RENDER_FILES_BONUS = ${RENDER_DIR_BONUS}/window_bonus.c ${RENDER_DIR_BONUS}/init_data_bonus.c \
				${RENDER_DIR_BONUS}/render_bonus.c

UTILS_FILES_BONUS = ${UTILS_DIR_BONUS}/ft_str_format_bonus.c ${UTILS_DIR_BONUS}/time_bonus.c

SRC_FILES_BONUS = ${ERROR_FILES_BONUS} ${EVENT_FILES_BONUS} ${FREE_FILES_BONUS} ${MAP_FILES_BONUS} \
	${PARSE_FILES_BONUS} ${RENDER_FILES_BONUS} ${UTILS_FILES_BONUS} ${GNL_FILES} ${PLAYER_FILES_BONUS}

# RULES

SRC_BONUS = src_bonus/main_bonus.c ${SRC_FILES_BONUS}

# Object

OBJ_BONUS = $(SRC_BONUS:%.c=${OBJ_DIR_BONUS}/%.o)

bonus :$(NAME_BONUS)
	@$(call cyan,"Compilation done !")

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) ${MLX_LIB}
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) ${MLX_EXEC} -o $(NAME_BONUS)
	@$(call cyan,"Creating so_long...")

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: all clean fclean re bonus
