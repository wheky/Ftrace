/*
** find.c for  in /home/simoni_w/projet/teck2/Ftrace/Ftrace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Wed Jul 03 16:57:51 2013 
** Last update Wed Jul 03 16:57:51 2013 
*/

#include "ftrace.h"
#include "stack.h"
#include "syscalls.h"
#include "gotplt.h"
#include "list.h"

void	find_syscall(long ret, int fd, t_head *stack, struct user_regs_struct *reg, pid_t pid)
{
    t_syscall_entry	syscall;
    int			status;

    if ((ret & 0xffff) == 0x050f)
    {
	if (stack->size > 0)
	{
	    if (ptrace(PTRACE_SINGLESTEP, pid, (void *)0, (void *)0) < 0)
	    {
		fprintf(stderr, "simplestep: %m\n");
		output_end(fd);
		exit(-1);
	    }
	    wait(&status);
	    if (WIFEXITED(status))
	    {
		printf("+++ exited with %d +++\n", status);
		output_end(fd);
		exit(-1);
	    }
	    if (WIFSIGNALED(status))
	    {
		printf("+++ kill by %d +++\n", WTERMSIG(status));
		output_end(fd);
		exit(-1);
	    }
	    ptrace(PTRACE_GETREGS, pid, (void *)0, reg);
	    syscall = g_syscall[reg->orig_rax];
	    output_add_addr(fd, stack->head->addr, syscall.name, SYSCALL_NAME);
	}
    }
}

void		find_return(long ret, t_head *stack, struct user_regs_struct *reg, pid_t pid)
{
    long	sp;

    if ((ret & 0xff) == 0xc3)
    {
	sp = ptrace(PTRACE_PEEKTEXT, pid, reg->rsp, 0);
	if (ptrace(PTRACE_PEEKTEXT, pid, sp, 0) != ~0 && stack->size > 0)
	    stack_pop(stack); 
    }
}

void		write_and_add(int fd, t_head *stack, t_h *list,  char *to)
{
    char	*name;
    char	*func_addr;
    char	*name_and_addr;
    t_typeCall	t;

    asprintf(&func_addr, "func_0x%s", to);
    name = get_name(list, to);
    if (name != NULL)
    {
	asprintf(&name_and_addr, "%s\n( %s )", name, func_addr);
	t = get_type(list, to);
    }
    if (stack->size > 0)
    {
	if (name != NULL)
	    output_add_addr(fd, stack->head->addr, name_and_addr, t);
	else
	    output_add_addr(fd, stack->head->addr, func_addr, CALL_FCT);
    }
    else
    {
	if (name != NULL)
	    output_add_addr(fd, "? _start_ ?", name_and_addr, t);
	else
	    output_add_addr(fd, "? _start_ ?", func_addr, CALL_FCT);
    }
    if (name == NULL)
	stack_add(stack, func_addr);
    else
	stack_add(stack, name_and_addr);

}

void		find_call(long ret, int fd, t_head *stack, struct user_regs_struct *reg, pid_t pid, t_h *list)
{
    int		offset;
    char	*to;

    if ((ret & 0xff) == 0xe8)
    {
	offset = ret >> 8;
	if (offset < 0)
	{
	    offset = ~offset + 1;
	    if (ptrace(PTRACE_PEEKTEXT, pid, reg->rip - (offset - 5), 0) != ~0)
	    {
		if (in_plt((reg64_t) (reg->rip - (offset - 5))))
		  gotplt_add_dynamic_symbol(list, reg->rip - (offset - 5), pid);
		asprintf(&to, "%llx", reg->rip - (offset - 5));
		write_and_add(fd, stack, list, to);
	    }
	}
	else
	{
	    if (ptrace(PTRACE_PEEKTEXT, pid, reg->rip + offset + 5, 0) != ~0)
	    {
		if (in_plt((reg64_t) (reg->rip + offset + 5)))
		  gotplt_add_dynamic_symbol(list, reg->rip + offset + 5, pid);
		asprintf(&to, "%llx", reg->rip + offset + 5);
		write_and_add(fd, stack, list, to);
	    }
	}
    }    
}

