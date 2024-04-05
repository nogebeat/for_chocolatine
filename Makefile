##
## EPITECH PROJECT, 2023
## make
## File description:
## make
##

CC	=	gcc

NAME	=	107transfer

SRC = 	src/transfer.c \

MAIN		=	src/main.c

TEST_SRC	=	tests/test01.c\
				tests/test_err.c\
				tests/test_err1.c\
				tests/test_err2.c\
				tests/test_arg.c

OBJS	=	$(SRC:.c=.o)

CFLAGS	+= -I./include/ -L -lmy -g -g3 -lgcov -lm

LIB += -L./lib/ -lshell

FTEST = -coverage -lcriterion -lgcov

BIZ = *~ *.log a.out *.gcov *.gcda *.gcno

all: 		$(NAME)

$(NAME): 	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(MAIN) $(CFLAGS)

clean:
		rm -f $(OBJS)

TU: 	rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME) unit_tests $(BIZ)

re:		fclean all

unit_tests: fclean $(NAME)
			$(CC) -o unit_tests $(SRC) $(TEST_SRC) $(FTEST)


tests_run:	unit_tests
			./unit_tests
			gcovr
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches
