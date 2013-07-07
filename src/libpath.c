/*
** test.c for  in /home/masson_y/test
** 
** Made by 
** Login   <masson_y@epitech.net>
** 
** Started on  Sun Jul 07 02:54:11 2013 
** Last update Sun Jul 07 02:54:11 2013 
*/

#define	_GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char 		*get_lpath(char *line)
{
    char 	*str;
    char 	*token;
    char 	*saveptr;
    int 	j;
    int		isl;

    isl = 0;
    j = 1;
    str = line;
    while ((token = strtok_r(str, " ", &saveptr)) != NULL)
    {
	if (j == 1 && !strncmp(token, "7f", 2))
	    isl = 1;
	else if (j == 6 && isl && strlen(token) > 1 &&
		token[0] != '[')
	{
	    return (token);
	    isl = 0;
	}
	j++;
	str = NULL;
    }
    return (NULL);
}

void		add_lpath(char ***tab, char *lpath)
{
    int		i;

    i = 0;
    if (*tab == NULL)
    {
	*tab = malloc(2 * sizeof (char *));
	if (*tab == NULL)
	    return ;
	*tab[0] = strdup(lpath);
	*tab[1] = NULL;
    }
    else
    {
	while ((*tab)[i])
	{
	    if (!strcmp(((*tab)[i]), lpath))
		return ;
	    i++;
	}
	*tab = realloc(*tab, i * sizeof (char *) + 2);
	(*tab)[i] = strdup(lpath);
	(*tab)[i + 1] = NULL;
    }
}

char 		**get_shared_libpath(pid_t pid)
{
    char 	**tab;
    FILE 	*f;
    char 	*path;
    char 	*line;
    size_t 	len;
    char 	*lpath;

    len = 0;
    line = NULL;
    tab = NULL;
    asprintf(&path, "/proc/%d/maps", pid);
    f = fopen(path, "r");
    while ((getline(&line, &len, f)) != -1)
    {
	line[strlen(line) - 1] = 0;
	if ((lpath = get_lpath(line)))
	    add_lpath(&tab, lpath);
    }
    return (tab);
}
