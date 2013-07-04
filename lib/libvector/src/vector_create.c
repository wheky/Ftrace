/*
** vector_create.c for  in /home/pastek/42sh-2016-dinque_n/libvector
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 21:58:40 2012 jonathan tran
** Last update dim. avril 15 21:58:40 2012 jonathan tran
*/
#include <vector.h>
#include "vector_utility.h"

vector_t		*vectorCreate()
{
  vector_t		*vector;

  vector = vectorAllocateMemory(sizeof(vector_t));
  vector->front = 0;
  vector->back = 0;
  vector->onAdd = 0;
  vector->onRemove = 0;
  vector->size = 0;
  return (vector);
}
