/*
** vector_delete.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:12:10 2012 jonathan tran
** Last update dim. avril 15 22:12:10 2012 jonathan tran
*/
#include <vector.h>
#include "vector_utility.h"

void		vectorDelete(vector_t *vector)
{
  while (vector->size > 0)
    vectorPopBack(vector);
  vectorReleaseMemory(vector);
}
