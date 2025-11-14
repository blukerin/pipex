NAME = pipex

SRC = src/main.c src/childs.c src/memory_and_error.c src/utils.c
OBJS = $(SRC:.c=.o)

LIBFT_DIR = libft
INCLUDES = -I$(LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re