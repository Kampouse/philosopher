NAME = philo

FLAGS = -Wall -Wextra -Werror -g
SRCS =  main.c  verify.c  philo.c philo_utils.c init.c utils.c
RM =  rm -rf 
.c.o:
	@gcc ${FLAGS}  -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}
CC = gcc 

all: ${NAME}
${NAME}:${OBJS} 
		@$(MAKE) -C libft
		@${CC} ${OBJS} ${FLAGS}   -o ${NAME}
	

run: all
	./philo 1  200 200 200 

val: all
	valgrind   --leak-check=full --track-origins=yes -s --trace-children=yes  ./philo 1 310 200 100 2 40

test: all
	 @echo "error asserting"
	./philo 5
	./philo 5 2
	./philo 5 2 3
	./philo 5 2 4 5
	./philo 5 2 4 6 7
	./philo 5 2 4 6 7 8
	./philo 5 2 4 6 7 0
 


clean:
	    ${RM} ${OBJS}	
git:
		@git add ${SRCS} Makefile

fclean: clean
	@${RM} ${NAME}
	@$(MAKE) -C libft fclean
re: fclean all
	
.PHONY: clean fclean re all
