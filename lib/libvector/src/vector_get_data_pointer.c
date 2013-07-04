/*
** vector_get_data_pointer.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:26:17 2012 jonathan tran
** Last update Mon Apr 30 17:14:31 2012 Chris
*/
#include <vector.h>

void		*vectorGetDataPointer(vector_node_t *node)
{
  return ((void *)((char *) node + sizeof(vector_node_t)));
}
