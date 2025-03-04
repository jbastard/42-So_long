NAME		=	so_long

#COMPILATION
CC			=	clang
FLAG		=	-Wall -Wextra -Werror -g

#VISUAL
MAKEFLAGS	+=	--no-print-directory
SILENT		=	> /dev/null 2>&1
RM_LINE			= @tput cuu1 && tput el

NC			= \033[0m
GREEN		= \033[0;92m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
RED			= \033[0;31m
CYAN		= \033[0;36m
BLACK		= \033[0;30m

GREEN_BG	= \033[42m
WHITE_BG	= \033[107m
L_GREEN_BG	= \033[102m
L_YELLOW_BG	= \033[103m
L_RED_BG	= \033[101m

DONE		= echo "✅"

#FILES DIRECTORIES
SRC_DIR		=	srcs/
CORE_DIR	=	core/
PARSING_DIR	=	parsing/
GAME_DIR	=	game/
GRAPHIC_DIR	=	graphics/
ERROR_DIR	=	error/
UTILS_DIR	=	utils/

INC_DIR		=	includes/
OBJ_DIR		=	objs/

#LIBFT
LIBFT_GIT	=	https://github.com/jbastard/42-Libft-updated.git
LIBFT_PATH	=	libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

#MLX
MLX_GIT		=	https://github.com/42Paris/minilibx-linux.git
MLX_PATH	=	minilibx-linux/
MLX_FILE	=	libmlx.a
MLX_FLAG	=	-lX11 -lXext
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

#SRCS FILES
C_FILE		=	${CORE_DIR}main.c \
				${CORE_DIR}init.c \
				${GAME_DIR}inputs.c \
				${GAME_DIR}player_moves.c \
				${PARSING_DIR}parsing.c \
				${PARSING_DIR}map_checker.c \
				${PARSING_DIR}flood_fill.c \
				${GRAPHIC_DIR}load_all_sprites.c \
				${GRAPHIC_DIR}load_sprites_ui.c \
				${GRAPHIC_DIR}load_sprites_environment.c \
				${GRAPHIC_DIR}load_char.c \
				${GRAPHIC_DIR}display_map.c \
				${GRAPHIC_DIR}display_moves.c \
				${GRAPHIC_DIR}display_ui.c \
				${GRAPHIC_DIR}animations.c \
				${ERROR_DIR}error_handler.c \
				${UTILS_DIR}utils.c

SRC			=	$(addprefix $(SRC_DIR), $(C_FILE))
OBJ			=	$(addprefix $(OBJ_DIR), $(C_FILE:.c=.o))

#OBJ CREATION IN OBJ DIR
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

#CLONE AND MAKE LIBFT
$(LIBFT_LIB):
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		printf "${BLACK}${L_YELLOW_BG}     Cloning libft from GitHub..   :${NC}";\
		git clone $(LIBFT_GIT) $(LIBFT_PATH) ${SILENT};\
		${DONE};\
	else \
		printf "${BLACK}${L_GREEN_BG}     Libft already cloned.         :${NC}";\
	fi
	@make -C $(LIBFT_PATH) ${SILENT}

# MLX
$(MLX_LIB):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		printf "${BLACK}${L_YELLOW_BG}      Cloning MLX from GitHub..    :${NC}";\
		git clone $(MLX_GIT) $(MLX_PATH) ${SILENT};\
		${DONE};\
	else \
		printf "${BLACK}${L_GREEN_BG}      MLX already cloned.          :${NC}";\
	fi
	@make -sC $(MLX_PATH) ${SILENT}

# COMPILING
$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJ)
	@if [ ! -d "$(LIBFT_PATH)" ] && [ -d "$(MLX_PATH)" ]; then \
		printf "${BLACK}${GREEN_BG}            Compiling libs         :${NC}"; \
		${DONE};\
	fi
	@printf "${BLACK}${L_GREEN_BG}  Building the ${NAME} executable  :${NC}"
	@$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@${DONE}

clean:
	@printf "${BLACK}${L_RED_BG} Removing ${NAME} objects and libs :${NC}"
	@rm -rf $(OBJ_DIR)
	@${DONE}

fclean:
	@printf "${BLACK}${L_RED_BG} Removing ${NAME} and dependancies :${NC}"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_PATH)
	@rm -rf $(LIBFT_PATH)
	@${DONE}

re: fclean all

.PHONY: all clean fclean re
