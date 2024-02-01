# DEFINITIONS
NAME			= cube3d
DEPENDENCIES	= include
CC				= cc
LIBFT_SRC		= libft
LIBFT_NAME		= libft.a
MLX_NAME		= libmlx_Linux.a libmlx.a
SRC_DIR			= src/
OBJ_DIR			= obj/
RM				= rm -rf
NODIRS			= --no-print-directory
MLX_FLDR		= mlx_linux
MLX_FLAGS		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CC_FLAGS		= -g -Wall -Werror -Wextra -lm  -I $(DEPENDENCIES) -O3
VG				= valgrind --leak-check=full --suppressions=sup --track-origins=yes #--log-file=leaks.log
#provavelmente ter de alterar alguma cena para melhor incluir minilibx

# DIRECTORIES
DIRS	= calcs draw hooks map
PATHS	= $(addprefix $(SRC_DIR), $(DIRS))
vpath %.c src $(PATHS)

# FILES
SRCS		= cube calcs draw hook_functions map_init minimap read_file \
		save_map validate_map
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
	@$(RM) $(OBJ_DIR)

fclean :
	@make fclean -C $(LIBFT_SRC)
	@make clean -C $(MLX_FLDR)
	@$(RM) $(OBJS_FILES) $(LIBFT_NAME) $(MLX_NAME)
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)

re : fclean all

.SILENT:

.PHONY : all, clean, fclean, re