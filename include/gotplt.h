/*
** gotplt.h for  in /home/pastek/Project/tek2/Ftrace/include
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  Sun Jul 07 08:39:36 2013 jonathan tran
** Last update Sun Jul 07 08:39:36 2013 jonathan tran
*/
#ifndef GOTPLT_H_
# define GOTPLT_H_

#include "list.h"

typedef unsigned long long	reg64_t;

void	gotplt_initialize(int);
void	gotplt_add_dynamic_symbol(t_h *, reg64_t, reg64_t, reg64_t, int);
int	in_plt(reg64_t);

#endif
