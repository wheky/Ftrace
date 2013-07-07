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
#include "gotplt.h"
#include "libpath.h"

pid_t	g_pid;

static int	find_graph(t_h *list)
{
    struct 	user_regs_struct reg;
    int		status;
    t_head	*stack;
    char	**libpath;
    long	ret;
    int		fd;

    fd = get_fd_file(NULL); /* Remplacer null par le nom du fichier, sinon output.dot sera cree par default */
    output_begin(fd);
    stack = stack_init();
    libpath = get_shared_libpath(g_pid);
    while (true)
    {
	ptrace(PTRACE_GETREGS, g_pid, (void *)0, &reg);

	ret = ptrace(PTRACE_PEEKTEXT, g_pid, reg.rip, 0);
	
	find_call(ret, fd, stack, &reg, g_pid, list);
	find_syscall(ret, fd, stack, &reg, g_pid);
	find_return(ret, stack, &reg, g_pid);

	if (ptrace(PTRACE_SINGLESTEP, g_pid, (void *)0, (void *)0) < 0)
	{
	    fprintf(stderr, "simplestep: %m\n");
	    return (-1);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
	    printf("+++ exited with %d +++\n", status);
	    output_end(fd);
	    return (status);
	}
    }
    output_end(fd);
    return (0);
}

static int	trace(int fd, pid_t pid, t_h *list)
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
    if (fd != -1)
    {
      printf("INITIALIZED\n");
      gotplt_initialize(fd);
    }
    return (find_graph(list));
}

static int	launch_and_trace(char **argv)
{
    pid_t	cpid;
    int		fd;
    t_h		*list;

    if ((fd = open(argv[0], O_RDONLY)) < 0)
	list = NULL;
    else
	list = call_my_nm(fd);
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
    //gotplt_initialize(fd);
    return (trace(fd, cpid, list));
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
	return (trace(-1, atoi(argv[2]), NULL));
    }
    return (launch_and_trace(argv + 1));
}
