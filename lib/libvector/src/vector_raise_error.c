/*
** vector_raise_error.c for  in /home/pastek/42sh-2016-dinque_n/libvector/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  dim. avril 15 22:06:54 2012 jonathan tran
** Last update dim. avril 15 22:06:54 2012 jonathan tran
*/
#include <unistd.h>
#include "vector_utility.h"

static int	__strlen(char *string)
{
  int		count;

  count = 0;
  while (*string++)
    count++;
  return (count);
}

void		vectorRaiseError(char *error)
{
  write(2, error, __strlen(error));
}
