/*
** vector_utility.h for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:03:35 2012 jonathan tran
** Last update dim. avril 15 22:03:35 2012 jonathan tran
*/
#ifndef VECTOR_UTILITY_H_
#define VECTOR_UTILITY_H_

#include <vector.h>

void			*vectorAllocateMemory(unsigned);
void			vectorReleaseMemory(void *);
void			vectorRaiseError(char *);

vector_node_t		*vectorCreateNode(void *, unsigned);

#endif
