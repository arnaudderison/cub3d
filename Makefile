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


all: $(NAME)

$(NAME): $(LIBFT) $(CUBE_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CUBE_OBJS) -L$(LIBFT_DIR) -lft -o $@
	@printf "\r${YELLOW}[CUB3D]${GREEN}    Executable $(NAME) created.\n${NC}"

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@printf "\r${YELLOW}[CUB3D]${GREEN}Compiling ...${NC}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

clean:
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}Object files cleaned.${NC}"

fclean: clean
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@rm -f $(NAME)
	@echo "${RED}All files removed.${NC}"

re: fclean all

.PHONY: all clean fclean re check_readline
