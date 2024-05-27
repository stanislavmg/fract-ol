NAME = fractol

LIB = libft.a

LIBDIR = ./libft/libft.a

INCLUDE = fractol.h

SRCS = main.c

OBJ = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(INCLUDE) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBDIR) -o $(NAME)

$(LIB)	:
	$(MAKE) -sC ./libft

%.o		:	%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re