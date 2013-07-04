/*
** vector_browse.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 23:18:19 2012 jonathan tran
** Last update dim. avril 15 23:18:19 2012 jonathan tran
*/
#include <vector.h>

void		vectorBrowse(vector_t *vector, vector_callback_t callback)
{
  vector_node_t	*node;

  for (node = vector->front; node; node = node->next)
    callback(vectorGetDataPointer(node));
}
