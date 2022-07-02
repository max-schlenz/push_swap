# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2022/07/02 11:36:20 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FORMAT
DEFCL	=	\033[0m
RED		=	\033[0;31m
LBLUE	=	\033[1;34m
LCYAN	=	\033[1;36m
PURPLE	=	\033[0;35m

NAME		=	push_swap
NAME_BONUS	=	checker

SRC_DIR			=	src/
OBJ_DIR			=	obj/
LIB_DIR			=	lib/

SRC			= 	utils_lst \
				utils_lst2 \
				utils_misc \
				utils_misc2 \
				utils_parsing \
				sorting_index \
				sorting_pivot \
				sorting_push \
				sorting_swap \
				sorting_rotate \
				sorting_sorting \
				sorting_sort_small

LIB			=	libft \
				libftprintf
					
SRC_CHK			= 	checker
SRC_PS			=	push_swap

SRC_PATH		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC)))
OBJ_PATH		=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC)))
LIB_PATH		=	$(addsuffix .a, $(addprefix $(LIB_DIR), $(LIB)))
SRC_PS_PATH		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_PS)))
SRC_CHK_PATH	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_CHK)))


FLAGS			= 	#-Wall -Wextra -Werror

INCLUDES		= 	-I inc -L lib -l ft

all: create_dirs libft $(NAME)

libft:
	@make -C src/libft

bonus: libft $(NAME_BONUS)

$(NAME): $(SRC_PATH) $(LIB_PATH) message
	@gcc $(FLAGS) $(INCLUDES) $(SRC_PATH) $(SRC_PS_PATH) -o $(NAME)

$(NAME_BONUS): $(SRC_PATH) message_bonus
	@gcc $(FLAGS) $(INCLUDES) $(SRC_PATH) $(SRC_CHK_PATH) -o $(NAME_BONUS)

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)

.INTERMEDIATE: message

.INTERMEDIATE: message_bonus

message:
	@echo "${DEFCL}compiling ${LCYAN}push_swap${DEFCL}..."

message_bonus:
	@echo "${DEFCL}compiling ${LCYAN}checker${DEFCL}..."

clean:
	@if [[ -n `find $(OBJ_DIR) -type f -name '*.o'` ]]; then \
		echo "${PURPLE}removing ${LCYAN}push_swap${PURPLE} object files...${DEFCL}"; \
		find $(OBJ_DIR) -type f -name '*.o' -delete; \
	fi
	@if [ -f "push_swap" ]; then \
		echo "${PURPLE}removing ${LCYAN}push_swap${PURPLE} binary...${DEFCL}"; \
		rm -f push_swap; \
	fi
	@if [ -f "checker" ]; then \
		echo "${PURPLE}removing ${LCYAN}checker${PURPLE} binary...${DEFCL}"; \
		rm -f checker; \
	fi
	@make clean -C src/libft

fclean: clean
	@make fclean -C src/libft

re: fclean all bonus

.PHONY: all clean fclean re bonus
