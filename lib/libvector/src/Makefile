##
## Makefile for  in /home/pastek/42sh-2016-dinque_n/libvector
## 
## Made by jonathan tran
## Login   <tran_v@epitech.net>
## 
## Started on  dim. avril 15 22:15:20 2012 jonathan tran
## Last update dim. avril 15 22:15:20 2012 jonathan tran
##

CC =		gcc
CFLAGS =	-c -I include/
LDFLAGS =	
DEBUG = 	-W -Wall -Wextra -g
SRC =		src/vector_allocate_memory.c			\
		src/vector_release_memory.c			\
		src/vector_raise_error.c			\
		src/vector_create_node.c			\
		src/vector_create.c				\
		src/vector_delete.c				\
		src/vector_get_data_pointer.c			\
		src/vector_remove_node.c			\
		src/vector_push_front_ex.c			\
		src/vector_push_back_ex.c			\
		src/vector_pop_front.c				\
		src/vector_pop_back.c				\
		src/vector_browse.c				\
		src/vector_browse_ex.c				\
		src/vector_find.c
OBJ =		$(SRC:.c=.o)
NAME =		bin/libvector.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

debug:
	$(CC) -c $(SRC) $(CFLAGS) $(DEBUG)
	ar -rcs $(NAME) $(OBJ)
	rm vector_*.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
