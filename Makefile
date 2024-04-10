# DEFINITIONS
NAME			= cub3D
NAME_BONUS		= cub3D_bonus
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
CC_FLAGS		= -g -O0 -Wall -Werror -Wextra -I $(DEPENDENCIES) -O3 #-lm  
VG				= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=leaks.log

# DIRECTORIES
DIRS	= raycast hooks map init clean extras file_validation minimap
PATHS	= $(addprefix $(SRC_DIR), $(DIRS))
vpath %.c $(SRC_DIR) $(PATHS)

# FILES
SRCS	= cube hook_functions hook_handle init minimap read_file validate_map rgb checker \
	raycast_start raycast_helper raycast_images_init clean draw extras get_map error_handling
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
OBJS_FILES	= .tst


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
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJS_FILES) :
	@mkdir -p $(OBJ_DIR)

clean :
	@make $(NODIRS) clean -C $(LIBFT_SRC)
	@make $(NODIRS) clean -C $(MLX_FLDR)
	@$(RM) leaks.log
	@$(RM) test.log
	@$(RM) $(OBJ_DIR)

fclean : clean
	@make fclean -C $(LIBFT_SRC)
	@$(RM) $(OBJS_FILES) $(LIBFT_NAME) $(MLX_NAME)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS)
	@make $(NODIRS) -C $(LIBFT_SRC)
	@cp $(LIBFT_SRC)/libft.a .
	@make $(NODIRS) -C $(MLX_FLDR)
	@cp $(MLX_FLDR)/libmlx_Linux.a .
	@cp $(MLX_FLDR)/libmlx.a .
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_NAME) $(MLX_FLAGS) -o $(NAME_BONUS)

run :
	@./$(NAME) $(DEFAULT_MAP)

leaks : all
	@$(VG) ./$(NAME) $(DEFAULT_MAP)

debug : all
	@gdb -tui --args $(NAME) $(DEFAULT_MAP)

.SILENT:

.PHONY : all, bonus, clean, fclean, re, run, leaks, debug
