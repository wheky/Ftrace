/*
** vector_pop_front.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 23:05:27 2012 jonathan tran
** Last update dim. avril 15 23:05:27 2012 jonathan tran
*/
#include <vector.h>
#include "vector_utility.h"

void		vectorPopFront(vector_t *vector)
{
  vectorRemoveNode(vector, vector->front);
}
