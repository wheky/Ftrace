/*
** vector_push_back_ex.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:58:37 2012 jonathan tran
** Last update dim. avril 15 22:58:37 2012 jonathan tran
*/
#include <vector.h>
#include "vector_utility.h"

void		vectorPushBackEx(vector_t *vector, void *data, unsigned size)
{
  vector_node_t	*node;

  node = vectorCreateNode(data, size);
  if (vector->onAdd)
    vector->onAdd(vectorGetDataPointer(node));
  node->previous = vector->back;
  node->next = 0;
  if (vector->back)
    vector->back->next = node;
  if (!vector->front)
    vector->front = node;
  vector->back = node;
  vector->size++;
}
