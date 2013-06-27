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

pid_t	g_pid;

static int	find_call(void)
{
    struct 	user_regs_struct reg;
    bool	is_syscall;
    int		status;

    while (true)
    {
	is_syscall = false;
	ptrace(PTRACE_GETREGS, g_pid, (void *)0, &reg);

	/* ON testera si c'est un call ici */
	if ((ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip, 0) & 0xffff) == 0x050f)
	    is_syscall = true;

	/* TODO REMOVE */
	    is_syscall = false;

	if ((ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip, 0) & 0xff) == 0xe8)
	{
	    printf("Possible call -->%lx \t", ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip, 0));
	    printf("ADDR = %lx\n", reg.rip);
	}    
	/*if (reg.rip == 0x400522)*/
	/*{*/
	/*printf("*********************%lx\n", ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip, 0));*/
	/*}*/

	if (ptrace(PTRACE_SINGLESTEP, g_pid, (void *)0, (void *)0) < 0)
	{
	    fprintf(stderr, "simplestep: %m\n");
	    return (-1);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
	    printf("+++ exited with %d +++\n", status);
	    return (status);
	}
	if (is_syscall)
	{
	    ptrace(PTRACE_GETREGS, g_pid, (void *)0, &reg);
	    print_syscall(&reg);
	}
    }
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
