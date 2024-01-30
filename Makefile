# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 09:56:15 by jegger-s          #+#    #+#              #
#    Updated: 2023/10/25 09:56:19 by jegger-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
INCLUDE = -I/usr/include -Imlx_linux
SRC = 	main.c \
		read_file.c \
		hook_functions.c \
		save_map.c \
		validate_map.c 
		
LIBFT = ./libft/libft.a
NAME = cube
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -O3 -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C ./libft
	
re: fclean all
