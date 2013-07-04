/*
** vector_create_node.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:48:01 2012 jonathan tran
** Last update dim. avril 15 22:48:01 2012 jonathan tran
*/
#include <vector.h>
#include "vector_utility.h"

static void		__memcpy(void *dst, void *src, unsigned size)
{
  unsigned		i;

  for (i = 0; i < size; i++)
    *((char *) dst + i) = *((char *) src + i);
}

vector_node_t		*vectorCreateNode(void *data, unsigned size)
{
  vector_node_t		*node;

  node = vectorAllocateMemory(sizeof(vector_node_t) + size);
  __memcpy((char *) node + sizeof(vector_node_t), data, size);
  return (node);
}
