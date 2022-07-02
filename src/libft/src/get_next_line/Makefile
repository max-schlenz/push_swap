# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2022/07/02 09:12:54 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEFCL	=	\033[0m
RED		=	\033[0;31m
LBLUE	=	\033[1;34m

INC_DIR		=	../../inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	../../../../lib/

SRC			= 	get_next_line \
				get_next_line_utils

SRC_PATH	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC)))
OBJ_PATH	=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC)))

FLAGS		=	-Wall -Wextra -Werror
INCLUDES	= 	-I $(INC_DIR)

LIBFT		=	$(LIB_DIR)libft.a

all: create_dirs $(OBJ_PATH) add_to_lib

obj/%.o : src/%.c message
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)

add_to_lib: $(OBJ_PATH)
	@ar -ruc $(LIB_DIR)libft.a obj/*.o

.INTERMEDIATE: message

message:
	@echo "compiling ${LBLUE}get_next_line${DEFCL}..."

clean:
	@if [[ -n `find $(OBJ_DIR) -type f -name '*.o'` ]]; then \
		echo "removing ${LBLUE}get_next_line${DEFCL} object files..."; \
		find $(OBJ_DIR) -type f -name '*.o' -delete; \
	fi

fclean: clean

re: fclean all

.PHONY: all clean fclean re