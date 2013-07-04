/*
** vector_browse_ex.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  lun. avril 16 14:01:40 2012 jonathan tran
** Last update lun. avril 16 14:01:40 2012 jonathan tran
*/
#include <vector.h>

void		vectorBrowseEx(
    vector_t *vector,
    vector_callback_t callback,
    void *data)
{
  vector_node_t	*node;

  for (node = vector->front; node; node = node->next)
    callback(vectorGetDataPointer(node), data);
}
