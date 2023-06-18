NAME = tracker
CC =  gcc 
FLAGS = -Wall -Wextra -Werror 
RM = rm -f 


SRCS = main.c\
		calculations.c\
		results.c\
		get_user_values.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)


all: $(NAME)


clean: 
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(NAME)

re: fclean all

.PHONY = re clean fclean all