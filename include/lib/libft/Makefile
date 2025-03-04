LIBFT = libft.a
LIBFT_I = ./include/
CC = gcc
OBJ_DIR = obj
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(LIBFT_I)

# Couleurs
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
CYAN=\033[0;36m
NC=\033[0m

# Sources Libft
LIBFT_SRCS = $(wildcard src/**/*.c)
LIBFT_OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(LIBFT_SRCS))

# Fichier PID pour l'animation
ANIMATION_PID_FILE = .animation.pid

# Démarre l'animation
define start_animation
	printf "${CYAN}"; \
	( while :; do \
		printf "\r[LIBFT] Compilation... \|"; sleep 0.1; \
		printf "\r[LIBFT] Compilation... /"; sleep 0.1; \
		printf "\r[LIBFT] Compilation... -"; sleep 0.1; \
		printf "\r[LIBFT] Compilation... \\"; sleep 0.1; \
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

# Règles de compilation
all: $(LIBFT)
	@$(call stop_animation)

$(LIBFT): $(LIBFT_OBJS)
	@ar rcs $@ $^
	@printf "${YELLOW}\r[LIBFT]${GREEN}    $@ créé avec succès${NC}\n"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@if [ ! -f "$(ANIMATION_PID_FILE)" ]; then \
		$(call start_animation); \
	fi
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(call stop_animation)
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}Fichiers objets nettoyés.${NC}"

fclean: clean
	@rm -f $(LIBFT)
	@echo "${RED}Tous les fichiers ont été supprimés.${NC}"

re: fclean all

.PHONY: all clean fclean re