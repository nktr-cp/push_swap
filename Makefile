# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 23:49:05 by knishiok          #+#    #+#              #
#    Updated: 2023/10/21 04:11:59 by knishiok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

INC = -I includes

LIB = libft/libft.a

SRCS = srcs/main.c \
	srcs/parse_input.c \
	srcs/push_swap_utils.c \
	srcs/compress.c \
	srcs/stack.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIB):
	make -C libft

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(LIB)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re