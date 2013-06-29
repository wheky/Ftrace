/*
** strace.h for  in /home/simoni_w/projet/teck2/Strace/strace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Sat May 18 14:29:57 2013 
** Last update Sat May 18 14:29:57 2013 
*/

#ifndef STRACE_H
#define STRACE_H

#define _GNU_SOURCE

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/reg.h>
#include <sys/user.h>
#include <asm/unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RET -1

typedef	unsigned long long int t_reg;

extern pid_t	g_pid;

typedef enum	s_type{
    VOID,
    INT,
    STRING,
    ADDR,
    ARRAY,
    UNKNOWN,
    STRUCT,
    VARARGS
}		t_type;

/* PRINT_C */
void	print_value(t_reg reg, t_type type);
void	print_syscall(const struct user_regs_struct *reg);

void	sighandler(int);

typedef	long long unsigned int	_ADDR;

/* MANAGE_OUTPUT_C */
int	get_fd_file(char *file); /* NULL = output.dot*/
void	output_begin(int fd);
void	output_end(int fd);
void	output_add_addr(int fd, _ADDR from, _ADDR to);

#endif /* STRACE_H */
