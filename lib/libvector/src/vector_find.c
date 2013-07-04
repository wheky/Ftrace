/*
** vector_find.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 23:28:09 2012 jonathan tran
** Last update dim. avril 15 23:28:09 2012 jonathan tran
*/
#include <vector.h>

vector_node_t	*vectorFind(
    vector_t *vector,
    vector_callback_t callback,
    void *data
  )
{
  vector_node_t	*node;

  for (node = vector->front; node; node = node->next)
    if (callback(vectorGetDataPointer(node), data))
      return (node);
  return (0);
}
