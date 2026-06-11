NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS	= main.c parse.c stack.c stack_utils.c operations.c \
		  print_count.c rotate.c dispatcher.c disorder.c \
		  sort_simple.c sort_special.c sort_medium.c sort_complex.c

OBJ_DIR	= obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
