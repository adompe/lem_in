# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adompe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 18:40:35 by adompe            #+#    #+#              #
#*   Updated: 2016/08/24 15:15:07 by adompe           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME		=	lem_in

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g

SRC_DIR		=	srcs/

OBJ_DIR		=	objs/

INC_DIR		=	includes/

LIBFT_DIR	=	libft/

LIBFT_LIB	=	libft/libft.a

PRINTF_LIB	=	libftprintf/libftprintf.a

SRC_FILES	=	\
				ants.c					\
				error.c					\
				get_data.c				\
				link.c					\
				main.c					\
				print.c					\
				rooms.c					\
				utils.c					\
				get_next_line.c

INC_FILES	=	\
				lem_in.h				\
				libft.h					\
				get_next_line.h			\

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

INCS		=	$(addprefix $(INC_DIR), $(INC_FILES))

OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

.SILENT:

all:		$(NAME)
	echo "\033[0;32m $(NAME) compiled ✅"

$(NAME):	$(OBJS) $(LIBFT_LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB)

$(OBJS):	$(SRCS) $(INCS)
	mkdir -p $(OBJ_DIR)
	make -C $(LIBFT_DIR)
	echo "\033[0;32m make LIBFT ✅"
	(cd $(OBJ_DIR);															\
	$(CC) -c $(addprefix ../, $(SRCS))					\
	-I $(addprefix ../, $(LIBFT_DIR)/$(INC_DIR))		\
	-I $(addprefix ../, $(INC_DIR)))
	echo "\033[0;32m objects compiled ✅"

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	echo "\033[0;31m clean LIBFT ✅"
	rm -Rf $(OBJ_DIR)
	echo "\033[0;31m rm obj ✅"

fclean:		clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	echo "\033[0;31m rm $(NAME) ✅"

re:			fclean all

debug:		CC = cc
debug:		FLAGS += --analyze
debug:		re

.PHONY:		fclean clean re
