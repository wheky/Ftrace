/*
** list.h for  in /home/simoni_w/projet/teck2/Ftrace/Ftrace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Sat Jun 29 17:30:53 2013 
** Last update Sat Jun 29 17:30:53 2013 
*/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef enum	s_typeCall {
    SYSCALL_FCT,
    SYSCALL_NAME,
    CALL_FCT,
    CALL_LINKED,
    CALL_UNLINKED,
    CALL_STATIC,
    MAIN
}		t_typeCall;


typedef struct		s_list
{
    char		*name;
    char		*addr;
    t_typeCall		type;
    struct s_list	*next;
}	 		t_list;

typedef struct	 	s_h
{
    t_list	 	*head;
    t_list	 	*tail;
    unsigned int	size;
}	 		t_h;

t_h		*list_init();
void		list_add(t_h *list, char *addr, char *name, t_typeCall type);
char		*get_name(t_h *list, char *addr);
t_typeCall	get_type(t_h *list, char *addr);
void		print_list(t_h *list);

#endif /* LIST_H */
