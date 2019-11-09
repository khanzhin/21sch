# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtodd <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 09:57:08 by wtodd             #+#    #+#              #
#    Updated: 2019/11/09 11:08:08 by wtodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
	  map.c\
	  recognition.c\
	  validation.c\
	  validation_eof_access_usage.c\
	  validation_check_file.c\
	  build_tetro.c\
	  find_check_move_tetro.c\
	  ft_str_to_int2.c

OBJ = $(SRC:.c=.o) 

INC = fillit.h

LIBFT = libft/

all: $(NAME)
	
$(NAME):
	@make -C $(LIBFT)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I $(INC) -L. libft/libft.a
	@echo "\033[4;36mCompiling...\033[0m"
	@echo "\033[1;32m_|_|_|_|  _|_|_|  _|        _|        _|_|_|  _|_|_|_|_|   \033[0m"
	@echo "\033[1;32m_|          _|    _|        _|          _|        _| \033[0m"
	@echo "\033[1;32m_|_|_|      _|    _|        _|          _|        _|\033[0m"
	@echo "\033[1;32m_|          _|    _|        _|          _|        _| \033[0m"
	@echo "\033[1;32m_|        _|_|_|  _|_|_|_|  _|_|_|_|  _|_|_|      _|  \033[0m"

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean
	@echo  "\033[1;31m*.o file delete\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@echo "\033[4;31mlibrary deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
