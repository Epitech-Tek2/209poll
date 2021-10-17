##
## EPITECH PROJECT, 2021
## poll
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	sources/main.c

NAME	=	209poll

CFLAGS	=	-I./includes -g

LDFLAGS += -lm

LBLIBS	=	-L./bin/ -lstring -lcstring -llist
LIB_PATH	=	libs

OBJS	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LBLIBS) $(LDFLAGS)

tests_run: all
	gcc bonus/*.c tests/*.c -o unit_tests --coverage -lcriterion $(CFLAGS) $(LBLIBS) $(LDFLAGS)
	- ./unit_tests

lib:
	$(MAKE) -C $(LIB_PATH)/

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_PATH)/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_PATH)/ fclean

re: fclean all

.PHONY: all clean fclean re