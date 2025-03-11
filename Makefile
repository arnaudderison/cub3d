# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 19:00:25 by aderison          #+#    #+#              #
#    Updated: 2025/03/11 15:16:12 by arnaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -MD -MP

I_LIBFT = ./include/lib/libft/include/
I_CUBE = ./include/
INCLUDES = -I$(I_LIBFT) -I$(I_CUBE) -I$(MLX_DIR)
OBJ_DIR = obj
LIBFT_DIR = ./include/lib/libft/
MLX_DIR = ./include/lib/minilibx-linux/
LIBFT = $(LIBFT_DIR)libft.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz 

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

CUBE_SRCS = src/main.c \
			src/exit/error.c \
			src/exit/destroy_win.c \
			src/init/init_mlx.c \
			src/init/init_textures.c \
			src/init/init_img.c \
			src/graphics_engine/graphics_engine.c \
			src/graphics_engine/raycasting.c \
			src/graphics_engine/set_image_pixel.c \
			src/graphics_engine/update_modify_texture.c \
			src/moves/handler_move.c \
			src/moves/key_listener.c \
			src/moves/validate_move.c \
			src/moves/rotate.c

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
