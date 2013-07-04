/*
** vector_push_front_ex.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:46:15 2012 jonathan tran
** Last update dim. avril 15 22:46:15 2012 jonathan tran
*/
#include <vector.h>
#include "vector_utility.h"

void		vectorPushFrontEx(vector_t *vector, void *data, unsigned size)
{
  vector_node_t	*node;

  node = vectorCreateNode(data, size);
  if (vector->onAdd)
    vector->onAdd(vectorGetDataPointer(node));
  node->previous = 0;
  node->next = vector->front;
  if (vector->front)
    vector->front->previous = node;
  if (!vector->back)
    vector->back = node;
  vector->front = node;
  vector->size++;
}
