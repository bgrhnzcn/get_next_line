SRCS = get_next_line.c get_next_line_utils.c

NAME = get_next_line.a

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re:	fclean all