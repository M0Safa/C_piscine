# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosafa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 10:49:04 by mosafa            #+#    #+#              #
#    Updated: 2025/08/07 10:49:09 by mosafa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	srcs/ft_putchar.c \
		srcs/ft_swap.c \
		srcs/ft_putstr.c \
		srcs/ft_strlen.c \
		srcs/ft_strcmp.c \

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : $(OBJS)
		ar rcs ${NAME} ${OBJS}
%.o:%.c
		$(CC) $(CFLAGS) -I includes -c -o $@ $<
clean:
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re: fclean all
