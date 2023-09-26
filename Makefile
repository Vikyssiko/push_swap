NAME		=	push_swap

CHECKER		=	checker

LIBFT		=	libft.a

LIBFT_DIR	=	libft

BONUS_DIR	=	bonus

BONUS_SRCS	=	$(BONUS_DIR)/checker.c \
				$(BONUS_DIR)/main.c \
				$(SRC_DIR)/errors.c \
				$(SRC_DIR)/stack.c \
				$(SRC_DIR)/is_sorted.c \
				$(SRC_DIR)/position.c \
				$(SRC_DIR)/swap.c

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

SRC_DIR		=	src

SRCS		=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/count_operations.c \
				$(SRC_DIR)/errors.c \
				$(SRC_DIR)/is_sorted.c \
				$(SRC_DIR)/move_element.c \
				$(SRC_DIR)/position.c \
				$(SRC_DIR)/position_while_sort.c \
				$(SRC_DIR)/push_to_a.c \
				$(SRC_DIR)/reverse_rotate.c \
				$(SRC_DIR)/rotate.c \
				$(SRC_DIR)/sort.c \
				$(SRC_DIR)/sort_three.c \
				$(SRC_DIR)/stack.c \
				$(SRC_DIR)/swap.c \
				$(SRC_DIR)/swap_and_push.c

OBJS		=	$(SRCS:.c=.o)

DEPS		=	header

CFLAGS		+=	-Wall \
				-Wextra \
				-Werror \
				-I$(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)
	cc $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean
	make all

bonus: $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)
	cc $(CFLAGS) $(BONUS_OBJS) -o $(CHECKER) $(LIBFT_DIR)/$(LIBFT)

.PHONY:	re fclean clean all bonus