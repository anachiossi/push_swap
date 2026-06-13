NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT		= libft.a
LIBPRINTF	= libftprintf.a

SRCS	= main.c parse.c stack.c stack_utils.c \
		  operations_base.c operations_ps.c operations_r.c operations_rr.c \
		  dispatcher.c sort.c sort_special.c

OBJ_DIR	= obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBPRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
