# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2022/07/02 11:36:26 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEFCL	=	\033[0m
RED		=	\033[0;31m
LBLUE	=	\033[1;34m
LCYAN	=	\033[1;36m
PURPLE	=	\033[0;35m

NAME 		= libft.a

SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	../../lib/

SRC			= ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
			  ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
			  ft_toupper ft_tolower ft_itoa ft_atoi ft_strlen ft_strchr ft_strrchr ft_strncmp \
			  ft_strlcat ft_strlcpy ft_strdup ft_strnstr ft_strjoin ft_substr ft_striteri ft_strtrim ft_split ft_strmapi \
			  ft_calloc ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_bzero \
			  ft_lstnew ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter ft_lstlast ft_lstsize

SRC_PATH	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC)))
OBJ_PATH	=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC)))

FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-I inc

all: create_dirs $(OBJ_PATH) $(NAME)

obj/%.o : src/%.c message
	@cc $(FLAGS) $(INCLUDES) -c $< -o $@
	@ar -ruc $(LIB_DIR)$(NAME) $@

$(NAME): $(OBJ_PATH)
	@make -C src/ft_printf
	@make -C src/get_next_line

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)

.INTERMEDIATE: message

message:
	@echo "${DEFCL}compiling ${LBLUE}libft${DEFCL}..."
	
clean:
	@if [[ -n `find $(OBJ_DIR) -type f -name '*.o'` ]]; then \
		echo "${PURPLE}removing ${LBLUE}libft${PURPLE} object files...${DEFCL}"; \
		find $(OBJ_DIR) -type f -name '*.o' -delete; \
	fi
	@make clean -C src/ft_printf
	@make clean -C src/get_next_line

fclean: clean
	@if [ -f "$(LIB_DIR)libft.a" ]; then \
		echo "${PURPLE}removing ${LBLUE}libft${PURPLE} library file...${DEFCL}"; \
		rm -f $(LIB_DIR)libft.a; \
	fi
	@make fclean -C src/ft_printf
	@make fclean -C src/get_next_line
	
re: fclean $(NAME)

.PHONY: clean fclean re bonus