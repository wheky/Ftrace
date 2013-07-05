/*
** list.c for  in /home/simoni_w/projet/teck2/Ftrace/Ftrace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Sat Jun 29 16:53:18 2013 
** Last update Sat Jun 29 16:53:18 2013 
*/

#include <string.h>
#include "list.h"

t_h		*list_init()
{
    t_h	*list;

    list = malloc(sizeof(t_h));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void			print_list(t_h *list)
{
    unsigned int	i = 0;
    t_list		*e;

    if (list == NULL)
	return ;
    e = list->head;
    while (i < list->size)
    {
	printf("on a addr = %s et name = %s\n", e->addr, e->name);
	e = e->next;
	i++;
    }
}

void		list_add(t_h *list, char *addr, char *name)
{
    t_list	*e;

    e = malloc(sizeof(t_list));
    e->addr = addr;
    e->name = name;
    if (list->size == 0)
    {
	list->size = 1;
	list->head = e;
	list->tail = e;
	e->next = NULL;
    }
    else
    {
	list->size++;
	e->next = list->head;
	list->head = e;
    }
}

char		*get_name(t_h *list, char *addr)
{
    t_list	*l;

    if (list == NULL || addr == NULL || list->size == 0)
	return NULL;
    l = list->head;
    while (l != list->tail)
    {
	if (l->addr != NULL && !strncmp(l->addr, addr, strlen(addr)))
	    return l->name;
	l = l->next;
    }
	if (l->addr != NULL && !strncmp(l->addr, addr, strlen(addr)))
	return l->name;
    return NULL;
}
