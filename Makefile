CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS =	ft_split.c instructions1.c  instuctions2.c   instructions3.c  linked_list_helper.c   parcing_utils.c \
		parcing.c  sort_utils.c sort_algorithm.c  sort.c  main.c

OBJS = $(SRCS:.c=.o)


NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
