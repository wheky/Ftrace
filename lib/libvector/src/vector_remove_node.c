/*
** vector_remove_node.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:36:01 2012 jonathan tran
** Last update dim. avril 15 22:36:01 2012 jonathan tran
*/
#include <vector.h>
#include "vector_utility.h"

void		vectorRemoveNode(vector_t *vector, vector_node_t *node)
{
  if (vector->onRemove)
    vector->onRemove(vectorGetDataPointer(node));
  if (vector->front == node)
    vector->front = node->next;
  if (vector->back == node)
    vector->back = node->previous;
  if (node->previous)
    node->previous->next = node->next;
  if (node->next)
    node->next->previous = node->previous;
  vectorReleaseMemory(node);
  vector->size--;
}

