
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

NAME = get_next_line.a

CFLAGS = -Wall -Wextra -Werror

CC = cc
RM = rm -f

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs $(NAME) $(OBJS)

exec:
	cc main.c $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) get_next_line.h.gch

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re