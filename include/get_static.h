/*
** my_nm.h for  in /home/simoni_w/projet/teck2/NMObjdump
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Thu Mar 14 15:39:33 2013 
** Last update Thu Mar 14 15:39:33 2013 
*/

#ifndef _GET_STATIC_H_
#define _GET_STATIC_H_

#define _GNU_SOURCE

#include <elf.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include "list.h"

typedef struct	s_file_64
{
    void	*ptrEnd;
    Elf64_Sym	*symtab;
    Elf64_Shdr	*shdr;
    Elf64_Ehdr	*elf;
}		t_file_64;

#define	INDEX_SEQ	file->symtab[i].st_shndx

/* MY_NM_C */
int	run_through_64(char *tab, t_file_64 *file, t_h *list, int len);
t_h 	*print_sh_name_64(t_file_64 *file);
t_h	*call_my_nm(int fd);
void	my_error();

#endif /* _GET_STATIC_H_ */
