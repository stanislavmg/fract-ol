NAME = fractol

INCLUDE = fractol.h

SRCS = main.c utils.c render.c events.c validation.c string.c init.c

OBJ = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re