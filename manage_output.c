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
}

void	output_end(int fd)
{
    write(fd, "}", 1);
    close(fd);
}

void		output_add_addr(int fd, _ADDR from, _ADDR to)
{
    char	*line;

    asprintf(&line, "\"%llx\" -> \"%llx\"\n", from, to);
    write(fd, line, strlen(line));
}
