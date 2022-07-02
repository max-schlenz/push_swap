# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2022/07/02 11:36:33 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEFCL	=	\033[0m
RED		=	\033[0;31m
LBLUE	=	\033[1;34m
LCYAN	=	\033[1;36m
PURPLE	=	\033[0;35m

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

all: create_dirs $(OBJ_PATH)

obj/%.o : src/%.c message
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@ar -ruc $(LIBFT) $@

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)


.INTERMEDIATE: message

message:
	@echo "${DEFCL}compiling ${LBLUE}get_next_line${DEFCL}..."

clean:
	@if [[ -n `find $(OBJ_DIR) -type f -name '*.o'` ]]; then \
		echo "${PURPLE}removing ${LBLUE}get_next_line${PURPLE} object files...${DEFCL}"; \
		find $(OBJ_DIR) -type f -name '*.o' -delete; \
	fi

fclean: clean

re: fclean all

.PHONY: all clean fclean re