/*
** print.c for  in /home/simoni_w/projet/teck2/Strace/strace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Sat May 18 14:29:18 2013 
** Last update Sat May 18 14:29:18 2013 
*/

#include "ftrace.h"
#include "errno.h"
#include "syscalls.h"

void		print_string(t_reg reg)
{
    long	buff;

    if ((void *)reg == NULL)
    {
	printf("NULL");
	return;
    }
    putchar('"');
    while (1)
    {
	buff = ptrace(PTRACE_PEEKTEXT, g_pid, (void *)reg, 0);
	if ((buff & 0xff) == 0)
	{
	    putchar('"');
	    return ;
	}
	putchar(buff & 0xff);
	reg++;
    }
}

void		print_value(t_reg reg, t_type type)
{
    if (type == INT)
	printf("%d", (signed int)reg);
    else if (type == STRING)
	print_string(reg);
    else if (type == ADDR)
    {
	if (reg)
	    printf("%p", (void *)reg);
	else
	    fputs("NULL", stdout);
    }
    else if (type == VOID)
	putchar('0');
    else
	putchar('?');
}

static void manage_syscall(const t_syscall_entry *syscall,
	const struct user_regs_struct *reg, int num)
{
    if (num == RET)
    {
	if ((signed)reg->rax < 0 && -reg->rax < ERRNO_COUNT)
	    printf("-1 %s (%s)", g_errno[-(signed)reg->rax].name,
		    strerror(-(signed)reg->rax));
	else
	    print_value(reg->rax, syscall->ret);
    }
    if (num == 0)
	print_value(reg->rdi, syscall->params[0]);
    else if (num == 1)
	print_value(reg->rsi, syscall->params[1]);
    else if (num == 2)
	print_value(reg->rdx, syscall->params[2]);
    else if (num == 3)
	print_value(reg->rcx, syscall->params[3]);
    else if (num == 4)
	print_value(reg->r8, syscall->params[4]);
    else if (num == 5)
	print_value(reg->r9, syscall->params[5]);
}

void			print_syscall(const struct user_regs_struct *reg)
{
    t_syscall_entry	syscall;
    int			nb_syscall;
    int			i;

    i = 0;
    syscall = g_syscall[reg->orig_rax];
    nb_syscall = syscall.num;
    printf("%s(", syscall.name);
    while (nb_syscall)
    {
	if (i != 0)
	    printf(", ");
	manage_syscall(&syscall, reg, i);
	i++;
	nb_syscall--;
    }
    printf(")\t= ");
    manage_syscall(&syscall, reg, RET);
    printf("\n");
}
