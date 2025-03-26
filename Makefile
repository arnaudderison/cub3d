# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aderison <aderison@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 19:00:25 by aderison          #+#    #+#              #
#    Updated: 2025/03/26 15:59:22 by aderison         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -MD -MP -O2 -O3 -march=native -funroll-loops -flto -ffast-math

I_LIBFT = ./include/lib/libft/include/
I_CUBE = ./include/
INCLUDES = -I$(I_LIBFT) -I$(I_CUBE) -I$(MLX_DIR)
OBJ_DIR = obj
LIBFT_DIR = ./include/lib/libft/
MLX_DIR = ./include/lib/minilibx-linux/
LIBFT = $(LIBFT_DIR)libft.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -O2

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

# MAPS = \
#     src/assets/maps/good/cheese_maze.cub \
#     src/assets/maps/good/creepy.cub \
#     src/assets/maps/good/dungeon.cub \
#     src/assets/maps/good/library.cub \
#     src/assets/maps/good/matrix.cub \
#     src/assets/maps/good/sad_face.cub \
#     src/assets/maps/good/square_map.cub \
#     src/assets/maps/good/subject_map.cub \
#     src/assets/maps/good/test_map.cub \
#     src/assets/maps/good/test_map_hole.cub \
#     src/assets/maps/good/test_pos_bottom.cub \
#     src/assets/maps/good/test_pos_left.cub \
#     src/assets/maps/good/test_pos_right.cub \
#     src/assets/maps/good/test_pos_top.cub \
#     src/assets/maps/good/test_textures.cub \
#     src/assets/maps/good/test_whitespace.cub \
#     src/assets/maps/good/works.cub
	

CUBE_SRCS = src/parsing/parsing.c \
			src/parsing/init_data.c \
			src/parsing/init_datatex.c \
			src/parsing/init_player.c \
			src/parsing/init_map.c \
			src/parsing/parse_map.c \
			src/parsing/init_color.c \
			src/parsing/utils.c \
			src/parsing/debug.c src/main.c \
			src/exit/error.c \
			src/exit/destroy_win.c \
			src/exit/freeall.c \
			src/exit/set_errinfo.c \
			src/init/init_mlx.c \
			src/init/init_textures.c \
			src/init/init_img.c \
			src/init/init_minimap.c \
			src/graphics_engine/graphics_engine.c \
			src/graphics_engine/raycasting.c \
			src/graphics_engine/set_image_pixel.c \
			src/graphics_engine/update_modify_texture.c \
			src/graphics_engine/magic_ceiling.c \
			src/moves/handler_move.c \
			src/moves/key_listener.c \
			src/moves/validate_move.c \
			src/moves/rotate.c \
			src/minimap/render_minimap.c \
			src/graphics_engine/door.c

CUBE_OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(CUBE_SRCS))
DEPS = $(CUBE_OBJS:.o=.d)

# Fichier PID pour l'animation
ANIMATION_PID_FILE = .animation.pid

# Démarre l'animation
define start_animation
	( while :; do \
		printf "\r${YELLOW}[LIBFT]${CYAN} Compilation... \|"; sleep 0.1; \
		printf "\r${YELLOW}[LIBFT]${CYAN} Compilation... /"; sleep 0.1; \
		printf "\r${YELLOW}[LIBFT]${CYAN} Compilation... -"; sleep 0.1; \
		printf "\r${YELLOW}[LIBFT]${CYAN} Compilation... \\"; sleep 0.1; \
	done ) & \
	echo $$! > $(ANIMATION_PID_FILE)
endef

# Arrête l'animation
define stop_animation
	@if [ -f "$(ANIMATION_PID_FILE)" ]; then \
		kill $$(cat $(ANIMATION_PID_FILE)) 2>/dev/null || true; \
		rm -f $(ANIMATION_PID_FILE); \
		printf "\r${NC}"; \
	fi
endef


all: $(NAME)
	@$(call stop_animation)
	
$(NAME): libx $(LIBFT) $(CUBE_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CUBE_OBJS) -L$(LIBFT_DIR) $(MLX_FLAGS) -lft -o $@
	@printf "\r${YELLOW}[CUB3D]${GREEN}    Executable $(NAME) created.\n${NC}"

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

libx:
	@make -C $(MLX_DIR) --no-print-directory
	@printf "\r${YELLOW}[MINILIBX]${GREEN} OK\n${NC}"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@if [ ! -f "$(ANIMATION_PID_FILE)" ]; then \
		$(call start_animation); \
	fi
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)
	
clean:
	@$(call stop_animation)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_DIR) --no-print-directory
	@echo "${YELLOW}[CUB3D] ${GREEN}Object files cleaned.${NC}"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@rm -f $(NAME)
	@echo "${YELLOW}[CUB3D] ${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re
