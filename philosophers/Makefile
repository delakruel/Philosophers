NAME		=	philo

CC 			=	gcc
CFLAGS		=	-Wextra -Wall -Werror

SRC			=	main.c init.c philo.c utils.c

OBJS	=	$(SRC:.c=.o)

HEADER		=	philo.h

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY		:	all clean fclean re 

all			:	$(NAME)

$(NAME)		: $(OBJS) $(HEADER)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean		:
	rm -f $(OBJS)

fclean		:	clean
	rm -f $(NAME) 

re			:	fclean all