/*
** list.c for  in /home/simoni_w/projet/teck2/Ftrace/Ftrace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Sat Jun 29 16:53:18 2013 
** Last update Sat Jun 29 16:53:18 2013 
*/

#include "stack.h"

t_head		*stack_init()
{
    t_head	*stack;

    stack = malloc(sizeof(t_head));
    stack->size = 0;
    stack->head = NULL;
    stack->tail = NULL;
    return stack;
}

void		stack_add(t_head *stack, _ADDR addr)
{
    t_stack	*e;

    e = malloc(sizeof(t_stack));
    e->addr = addr;
    if (stack->size == 0)
    {
	stack->size = 1;
	stack->head = e;
	stack->tail = e;
	e->next = NULL;
    }
    else
    {
	stack->size++;
	e->next = stack->head;
	stack->head = e;
    }
}

void		stack_pop(t_head *stack)
{
    t_stack	*save;

    if (stack->size == 0)
	return;
    save = stack->head;
    if (stack->size == 1)
    {
	free(save);
	stack->head = NULL;
	stack->tail = NULL;
    }
    else
    {
	stack->head = stack->head->next;
	free(save);
    }
    stack->size--;
}

_ADDR		stack_get_first(t_head *stack)
{
    if (stack == NULL || stack->head == NULL)
	return NULL;
    return stack->head->addr;
}

