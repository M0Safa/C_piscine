# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosafa <mosafa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 14:10:38 by mosafa            #+#    #+#              #
#    Updated: 2025/08/07 14:11:25 by mosafa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRCS =	do_op.c \
		help.c \
	
OBJS = $(SRCS:.c=.o)
SS = cc
CFLAGS = -Wall -Wextra -Werror
all : $(NAME)
$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<
fclean: clean
	rm -f $(NAME)
clean:
	rm -f $(OBJS)
re: fclean all
.PHONY: all clean fclean re
