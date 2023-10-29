# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 23:49:05 by knishiok          #+#    #+#              #
#    Updated: 2023/10/29 15:13:58 by knishiok         ###   ########.fr        #
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
	srcs/operations_base.c \
	srcs/operations_swap_push.c \
	srcs/operations_rotate.c \
	srcs/operations_reverse_rotate.c \
	srcs/push_swap.c \
	srcs/case_three.c \
	srcs/case_six.c \
	srcs/push_swap.c \
	srcs/push_swap_utils.c \
	srcs/push_swap_utils2.c \
	srcs/push_swap_operations.c \
	utils/list_funcs.c

BSRCS = bonus/main_bonus.c \
	srcs/parse_input.c \
	srcs/operations_base.c \
	srcs/operations_swap_push.c \
	srcs/operations_rotate.c \
	srcs/operations_reverse_rotate.c \
	srcs/case_three.c \
	srcs/push_swap_utils.c \
	srcs/push_swap_utils2.c \
	srcs/compress.c \
	utils/list_funcs.c
	

BONUS = checker

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

bonus: $(BONUS)

$(BONUS): $(BOBJS) $(LIB)
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
	$(BONUS)

re: fclean all

.PHONY: all clean fclean re