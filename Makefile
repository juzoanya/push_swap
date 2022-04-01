# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:54:59 by juzoanya          #+#    #+#              #
#    Updated: 2022/03/25 13:21:39 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft



CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	$(wildcard */*.c) \
		push_swap.c \
		small_sort.c \
		mid_sort.c \
		big_sort.c \
		push_action.c \
		swap_action.c \
		rotate_action.c \
		rev_rotate_action.c \
		checks.c \
		helpers.c \
		list_util.c \
		utils.c \

OBJ = $(SRC:.c=.o)

#INCLUDES = libft/libft.a

VAL			:= valgrind
VAL_FLAGS	:= --leak-check=full --show-leak-kinds=all --tool=memcheck --log-file=valgrind-out.txt

ARGS =	8 2 6 3

all: $(NAME)

$(NAME):
#	@make -C $(LIBFT)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)
	@echo "$(NAME) created"

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o)

clean:
#	@make -C libft/ clean
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
#	@make -C libft/ fclean
	@echo "$(NAME) deleted"

re: fclean all

memcheck: clean all
	clear
	$(VAL) $(VAL_FLAGS) ./$(NAME) $(ARGS)

.PHONY: all, clean, fclean, re