/*
** sighandler.c for  in /home/gayot_o/dev/tek2/strace
** 
** Made by olivier gayot
** Login   <gayot_o@epitech.net>
** 
** Started on  Sun May 19 20:52:49 2013 olivier gayot
** Last update Sun May 19 20:52:49 2013 olivier gayot
*/

#include <sys/ptrace.h>
#include <sys/types.h>
#include <stdlib.h>

extern pid_t	g_pid;

void sighandler(int sig)
{
    (void)sig;
    ptrace(PTRACE_DETACH, g_pid, (void *)0, (void *)0);
    exit(0);
}
