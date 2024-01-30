# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:49:05 by jegger-s          #+#    #+#              #
#    Updated: 2022/11/08 12:49:08 by jegger-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
      	ft_memchr.c\
      	ft_memcmp.c\
      	ft_memcpy.c\
      	ft_memmove.c\
      	ft_memset.c\
      	ft_putchar_fd.c\
      	ft_putendl_fd.c\
      	ft_putnbr_fd.c\
      	ft_putstr_fd.c\
      	ft_split.c\
      	ft_strchr.c\
      	ft_strdup.c\
      	ft_striteri.c\
      	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_atoi.c\
	get_next_line.c\
	get_next_line_utils.c\

SRC_B = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstclear.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstsize.c\
		ft_lstmap.c
		
NAME = libft.a
FLAGS = -Wall -Wextra -Werror -g
OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	ar -crs $@ $^
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft.\033[0m"

bonus:	$(OBJS_B) $(OBJS)
	ar -crs $(NAME) $^
	@echo "Successfully compiled Libft with Bonus."

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

clean:
	rm -rf $(OBJS) $(OBJS_B)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"
	
fclean: clean
	rm -rf $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libft.a deleted.\033[0m"
	
re: fclean all

.PHONY: all bonus clean fclean re
