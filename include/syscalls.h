/*
** syscalls.h for  in /home/simoni_w/projet/teck2/Strace/strace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Thu May 09 02:36:31 2013 
** Last update Thu May 09 02:36:31 2013 
*/

#ifndef SYSCALLS_H
#define SYSCALLS_H

typedef struct 	s_syscall_entry
{
    int		num;
    char	*name;
    t_type      ret;
    t_type      params[6];
}		t_syscall_entry;

static t_syscall_entry g_syscall[] =
{
#ifndef USE_GENERATED
# include "tab_syscalls_default.h"
#else
# include "tab_syscalls.h"
#endif
};

#endif/* SYSCALLS_H */
