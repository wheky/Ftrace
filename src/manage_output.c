/*
** manage_output.c for  in /home/simoni_w/projet/teck2/Ftrace/Ftrace
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Sat Jun 29 18:35:01 2013 
** Last update Sat Jun 29 18:35:01 2013 
*/

#include "ftrace.h"
#include "gotplt.h"

int	get_fd_file(char *file) /* NULL = output.dot */
{
    int	fd;

    if (file == NULL)
	fd = open("output.dot", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
	perror("open");
	exit(-1);
    }
    return fd;
}

void	output_begin(int fd)
{
    write(fd, "digraph G {\n", 12);
    write(fd, "node [style=filled];\n", 21);
}

void	output_end(int fd)
{
    write(fd, "}", 1);
    close(fd);
}

void		output_add_addr(int fd, _ADDR from, _ADDR to, t_typeCall t)
{
    char	*line;

    if (from == NULL)
	from = strdup("? START ?");
    asprintf(&line, "\"%s\" -> \"%s\";\n", from, to);
    write(fd, line, strlen(line));
    if (t == SYSCALL_NAME)
	asprintf(&line, "\"%s\" [shape=box, color=red];\n", to);
    else if (t == CALL_STATIC)
	asprintf(&line, "\"%s\" [color=springgreen4];\n", to);
    else if (t == CALL_UNLINKED)
	asprintf(&line, "\"%s\" [color=mediumorchid2];\n", to);
    else if (t == CALL_LINKED)
	asprintf(&line, "\"%s\" [color=purple];\n", to);
    else if (t == MAIN)
	asprintf(&line, "\"%s\" [shape=diamond, style=radial, color=gold, fontsize=20.0];\n", to);
    else
	asprintf(&line, "\"%s\" [color=lightblue2];\n", to);
    write(fd, line, strlen(line));
}
