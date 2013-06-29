##
## Makefile for  in /home/gayot_o/dev/tek2/strace
## 
## Made by olivier gayot
## Login   <gayot_o@epitech.net>
## 
## Started on  Mon May 06 16:21:09 2013 olivier gayot
## Last update Mon May 06 16:21:09 2013 olivier gayot
##

CC       ?= gcc 
CFLAGS   += -W -Wall -std=c99 -Wextra -D _BSD_SOURCE

## uncomment the following line to use generated syscall table
## (launch make gen before) You can also add -D USE_GENERATED to the CFLAGS
## environment variable.
 CFLAGS += -D USE_GENERATED -g

NAME      = ftrace
SRC       = main.c		\
	    print.c     	\
	    sighandler.c 	\
	    stack.c

all: depend $(NAME)

depend: .depend

.depend: $(SRC)
	@$(RM) .depend
	@$(CC) $(CFLAGS) -MM $^ > .depend

include .depend

OBJ     = $(SRC:.c=.o)

$(NAME): $(OBJ) 
	$(CC) -o $@ $^ $(LDFLAGS)

gen:
	perl extract.pl > tab_syscalls.h

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all depend clean fclean all re
