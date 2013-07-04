/*
** vector_allocate_memory.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:02:08 2012 jonathan tran
** Last update dim. avril 15 22:02:08 2012 jonathan tran
*/
#include <stdlib.h>
#include "vector_utility.h"

void		*vectorAllocateMemory(unsigned size)
{
  void		*p;

  p = malloc(size);
  if (!p)
    vectorRaiseError("Memory Allocation Error.");
  return (p);
}
