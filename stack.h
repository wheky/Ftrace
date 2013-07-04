/*
** stack.h for  in /home/simoni_w/projet/teck2/Ftrace/Ftrace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Sat Jun 29 17:30:53 2013 
** Last update Sat Jun 29 17:30:53 2013 
*/

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

/*typedef	long long unsigned int	_ADDR;*/
typedef	char *	_ADDR;

typedef struct		s_stack
{
    _ADDR		addr;
    struct s_stack	*next;
}	 		t_stack;

typedef struct	 	s_head
{
    t_stack	 	*head;
    t_stack	 	*tail;
    unsigned int	size;

}	 		t_head;

t_head	*stack_init();
void	stack_add(t_head *stack, _ADDR addr);
void	stack_pop(t_head *stack);
_ADDR	stack_get_first(t_head *stack);

#endif /* STACK_H */
