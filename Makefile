# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 16:10:53 by lmaume            #+#    #+#              #
#    Updated: 2024/05/30 18:43:28 by lmaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	push_swap.c \
		push.c \
		push2.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		utils.c \
		list.c \
		verif.c \
		count_moves.c \
		count_moves2.c \
		algorythm_till_five.c \
		algorythm_pass_five.c

PRINTF = ./printf/libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) all -C ./printf
	@cp $(PRINTF) $(NAME)
	@cc $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

clean :
	@$(MAKE) clean -C ./printf
	@$(RM) $(OBJS)

fclean : clean
	@$(MAKE) fclean -C ./printf
	@$(RM) $(NAME)

re : fclean all
