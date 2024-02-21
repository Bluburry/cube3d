# DEFINITIONS
NAME			= cub3d
DEPENDENCIES	= include
CC				= cc
LIBFT_SRC		= libft
LIBFT_NAME		= libft.a
MLX_NAME		= libmlx_Linux.a libmlx.a
SRC_DIR			= src/
OBJ_DIR			= obj/
RM				= rm -rf
DEFAULT_MAP		= maps/map.cub
NODIRS			= --no-print-directory
MLX_FLDR		= mlx_linux
MLX_FLAGS		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CC_FLAGS		= -g -Wall -Werror -Wextra -lm  -I $(DEPENDENCIES) -O3
VG				= valgrind -s --leak-check=full --track-origins=yes --log-file=leaks.log
#provavelmente ter de alterar alguma cena para melhor incluir minilibx

# DIRECTORIES
DIRS	= calcs draw hooks map init
PATHS	= $(addprefix $(SRC_DIR), $(DIRS))
vpath %.c src $(PATHS)

# FILES
SRCS		= cube calcs draw hook_functions init minimap read_file \
		save_map validate_map raycast_start
OBJS		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS))) #$(addsuffix .o, $(SRCS)))

OBJS_FILES	=	.tst

# COMPILATION
all : $(NAME)

$(NAME) : $(OBJS)
	@make $(NODIRS) -C $(LIBFT_SRC)
	@cp $(LIBFT_SRC)/libft.a .
	@make $(NODIRS) -C $(MLX_FLDR)
	@cp $(MLX_FLDR)/libmlx_Linux.a .
	@cp $(MLX_FLDR)/libmlx.a .
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_NAME) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o : %.c | $(OBJS_FILES)
	@echo "Compiling: $<"
	@$(CC) $(CC_FLAGS) $(MLX_FLAGS) -c $< -o $@

$(OBJS_FILES) :
	@mkdir -p $(OBJ_DIR)

clean :
	@make $(NODIRS) clean -C $(LIBFT_SRC)
	@make $(NODIRS) clean -C $(MLX_FLDR)
	@$(RM) leaks.log
	@$(RM) $(OBJ_DIR)

fclean : clean
	@make fclean -C $(LIBFT_SRC)
	@$(RM) $(OBJS_FILES) $(LIBFT_NAME) $(MLX_NAME)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)

re : fclean all

run : all
	@./$(NAME) $(DEFAULT_MAP)

leaks : all
	@$(VG) ./$(NAME) $(DEFAULT_MAP)

debug :
	@gdb -tui --args $(NAME) $(DEFAULT_MAP)

.SILENT:

.PHONY : all, clean, fclean, re, run, leaks, debug
