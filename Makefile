# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 09:03:04 by brouzaud          #+#    #+#              #
#    Updated: 2025/12/22 09:03:04 by brouzaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror -ggdb 
INC = -I./include 

SRCS = parsing_utils.c parsing.c reverse_rotate.c rotate.c simple_algo.c split.c swap.c utils.c main.c
OBJS = $(SRCS:.c=.o)

NAME = Push_swap

HEADERS = push_swap.h
all: $(NAME)
	@echo Compiled !

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "$(NAME) is ready !"

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo -- $(NAME) is clean --

fclean: clean
	@rm -f $(NAME)
	@echo -- Everything is clean --

re: fclean all

test: $(NAME)
	@./$(NAME)
	@echo -- END OF TESTING--
	@rm -f $(OBJS)
	@rm -f $(NAME)
gdb: $(NAME)
	gdb ./$(NAME)
val:
	@valgrind ./$(NAME)
	@rm -f $(OBJS)
	@rm -f $(NAME)


.PHONY: all clean fclean re