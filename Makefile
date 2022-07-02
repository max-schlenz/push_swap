# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschlenz <mschlenz@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:57:52 by mschlenz          #+#    #+#              #
#    Updated: 2022/07/02 11:01:11 by mschlenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FORMAT
DEFCL	=	\033[0m
RED		=	\033[0;31m
LBLUE	=	\033[1;34m
LCYAN	=	\033[1;36m

NAME		=	push_swap
NAME_BONUS	=	checker

SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIB_DIR		=	lib/

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
					
SRC_CHK			= 	checker
SRC_PS			=	push_swap

SRC_PATH		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC)))
SRC_PS_PATH		=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_PS)))
SRC_CHK_PATH	=	$(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_CHK)))
OBJ_PATH		=	$(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC)))

FLAGS			= 	#-Wall -Wextra -Werror
LIB				= 	-L lib -l ft
INCLUDES		= 	-I inc

all: create_dirs libft $(NAME)

libft: 	
	@make -C src/libft

bonus: libft $(NAME_BONUS)

$(NAME): $(SRC_PATH) message
	@gcc $(FLAGS) $(INCLUDES) $(LIB) $(SRC_PATH) $(SRC_PS_PATH) -o $(NAME)

$(NAME_BONUS): $(SRC_PATH) message_bonus
	@gcc $(FLAGS) $(INCLUDES) $(LIB) $(SRC_PATH) $(SRC_CHK_PATH) -o $(NAME_BONUS)

create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(LIB_DIR)

.INTERMEDIATE: message

.INTERMEDIATE: message_bonus

message:
	@echo "compiling ${LCYAN}push_swap${DEFCL}..."

message_bonus:
	@echo "compiling ${LCYAN}checker${DEFCL}..."

clean:
	@if [[ -n `find $(OBJ_DIR) -type f -name '*.o'` ]]; then \
		echo "removing ${LCYAN}push_swap${DEFCL} object files..."; \
		find $(OBJ_DIR) -type f -name '*.o' -delete; \
	fi
	@if [ -f "push_swap" ]; then \
		echo "removing ${LCYAN}push_swap${DEFCL} binary..."; \
		rm -f push_swap; \
	fi
	@if [ -f "checker" ]; then \
		echo "removing ${LCYAN}checker${DEFCL} binary...${DEFCL}"; \
		rm -f checker; \
	fi
	@make clean -C src/libft

fclean: clean
	@make fclean -C src/libft

re: fclean all bonus

.PHONY: all clean fclean re bonus
