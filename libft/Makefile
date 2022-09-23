NAME		=	libft.a

CFLAGS		=	-Werror -Wall -Wextra

SRC			=	$(shell find . -type f -name  "*.c")

OBJS		=	$(SRC:.c=.o)

HEADER	 	=	libft.h get_next_line.h

%.o: %.c $(HEADER)
	gcc -c $(CFLAGS) -I. $< -o $@

all:$(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all