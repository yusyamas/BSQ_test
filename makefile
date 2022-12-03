NAME = bsq
SRCS = main.c math.c print.c square.c free.c is_file_1.c is_file_2.c read_map.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAG = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -o bsq
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS)
	rm -f $(NAME)
re:
	rm -f $(OBJS)
	rm -f $(NAME)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) $(OBJS) -o bsq
