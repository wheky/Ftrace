/*
 ** main.c for  in /home/gayot_o/dev/tek2/strace
 ** 
 ** Made by olivier gayot
 ** Login   <gayot_o@epitech.net>
 ** 
 ** Started on  Mon May 06 16:20:43 2013 olivier gayot
 ** Last update Mon May 06 16:20:43 2013 olivier gayot
 */

#include "ftrace.h"
#include "stack.h"

pid_t	g_pid;

static int	find_call(void)
{
    struct 	user_regs_struct reg;
    int		status;
    t_head	*stack;
    long	ret;
    long	sp;
    int		fd;
    int		offset;

    /* On recupere le fd du fichier de config du graph 
     * (Remplacer null par le nom du fichier, sinon output.dot sera cree par default) */
    fd = get_fd_file(NULL);
    output_begin(fd);

    stack = stack_init();
    while (true)
    {
	ptrace(PTRACE_GETREGS, g_pid, (void *)0, &reg);

	ret = ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip, 0);
	/* On test si c'est un syscall */
	if ((ret & 0xffff) == 0x050f)
	{
	    if (stack->size > 0)
		output_add_addr(fd, stack->head->addr, reg.rax);
	}
	/* --------------------------------- */

	/* On test si c'est un return */
	if ((ret & 0xff) == 0xc3)
	{
	    sp = ptrace(PTRACE_PEEKTEXT, g_pid, reg.rsp, 0);
	    if (ptrace(PTRACE_PEEKTEXT, g_pid, sp, 0) != ~0 && stack->size > 0)
		stack_pop(stack); 
	}
	/* --------------------------------- */

	/* On test si c'est un call */
	if ((ret & 0xff) == 0xe8)
	{
	    offset = ret >> 8;
	    if (offset < 0)
	    {
		offset = ~offset + 1;
		if (ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip - (offset - 5), 0) != ~0)
		{
		    if (stack->size > 0)
			output_add_addr(fd, stack->head->addr, reg.rip - (offset - 5));
		    stack_add(stack, reg.rip - (offset - 5));
		}
	    }
	    else
	    {
		if (ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip + offset + 5, 0) != ~0)
		{
		    if (stack->size > 0)
			output_add_addr(fd, stack->head->addr, reg.rip + offset + 5);
		    stack_add(stack, reg.rip + offset + 5);
		}
	    }
	    /*printf("%d\n", stack->size);*/
	}    
	/* --------------------------------- */

	if (ptrace(PTRACE_SINGLESTEP, g_pid, (void *)0, (void *)0) < 0)
	{
	    fprintf(stderr, "simplestep: %m\n");
	    return (-1);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
	    printf("+++ exited with %d +++\n", status);
	    /* On ferme le fichier */
	    output_end(fd);
	    return (status);
	}
    }
    output_end(fd);
    return (0);
}

static int	trace(pid_t pid)
{
    int		status;

    g_pid = pid;
    if (ptrace(PTRACE_ATTACH, g_pid, (void *)0, (void *)0) < 0)
    {
	fprintf(stderr, "ptrace: %m\n");
	return (-1);
    }
    signal(SIGINT, &sighandler);
    signal(SIGQUIT, &sighandler);
    waitpid(g_pid, &status, WUNTRACED);
    if (!WIFSTOPPED(status))
    {
	fprintf(stderr, "unexpected status\n");
	return (-1);
    }
    return (find_call());
}

static int	launch_and_trace(char **argv)
{
    pid_t	cpid;

    if ((cpid = fork()) < 0)
    {
	fprintf(stderr, "Fork failed: %m\n");
	return (-1);
    }
    if (cpid == 0)
    {
	ptrace(PTRACE_TRACEME, 0, (void *)0, (void *)0);
	execvp(argv[0], argv);
	fprintf(stderr, "%s: %m\n", argv[0]);
	exit(-1);
    }
    return (trace(cpid));
}

int	main(int argc, char *argv[])
{
    if (argc < 2)
    {
	fprintf(stderr, "Usage: %s [-p pid] | PROG [ARGS]\n", argv[0]);
	return (-1);
    }
    if (strcmp(argv[1], "-p") == 0)
    {
	if (argc != 3)
	{
	    fprintf(stderr, "Usage: %s [-p pid] | PROG [ARGS]\n", argv[0]);
	    return (-1);
	}
	return (trace(atoi(argv[2])));
    }
    return (launch_and_trace(argv + 1));
}
