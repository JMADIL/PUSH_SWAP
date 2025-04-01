NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	pars_args.c \
		push_swap.c \
		utils/utils_2.c \
		utils/ft_split.c \
		utils/utils_1.c \
		utils/utils_0.c \
		utils/lst_utils.c \
		assign_indexes.c \
		simple_sort.c \
		moves/push.c \
		moves/rotate.c \
		moves/reverse_rotate.c \
		moves/swap.c \
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
