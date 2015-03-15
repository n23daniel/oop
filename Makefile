NAME = lab1_3
FLAGS = -Wall -Wextra -Werror
SRCS = run.c Controller/*.c Domain/*.c Repository/*.c Repository/*.c UI/*.c Utils/*.c
OBJS = *.o #${SRCS:.c=.o}

all:
	gcc -c $(SRCS)
	gcc -o $(NAME) $(OBJS)
	
clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all
