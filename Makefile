NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -MD -MP
I_LIBFT = ./include/lib/libft/include/
I_CUBE = ./include/
INCLUDES = -I$(I_LIBFT) -I$(I_CUBE)
OBJ_DIR = obj
LIBFT_DIR = ./include/lib/libft/
LIBFT = $(LIBFT_DIR)libft.a

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

CUBE_SRCS = src/main.c

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

$(NAME): $(LIBFT) $(CUBE_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CUBE_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@printf "\r${YELLOW}[CUB3D]${GREEN}    Executable $(NAME) created.\n${NC}"

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@if [ ! -f "$(ANIMATION_PID_FILE)" ]; then \
		$(call start_animation); \
	fi
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

clean:
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "${YELLOW}[CUB3D] ${GREEN}Object files cleaned.${NC}"

fclean: clean
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@rm -f $(NAME)
	@echo "${YELLOW}[CUB3D] ${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re check_readline
