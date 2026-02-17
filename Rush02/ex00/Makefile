NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = *.c
OBJS = $(SRCS: *.c=*.o)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
fclean:
	rm -f $(NAME)
