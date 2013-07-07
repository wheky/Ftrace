/*
** main.c for  in /home/simoni_w/projet/teck2/NMObjdump
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Thu Mar 14 15:48:51 2013 
** Last update Thu Mar 14 15:48:51 2013 
*/
#include <stdio.h>
#include "get_static.h"

void	my_error()
{
    printf("Error file\n");
    exit(-1);
}

t_h	*manage_64(t_file_64 *file)
{
    if ((void *)(file->shdr = (Elf64_Shdr *)((char *)file->elf
		   + file->elf->e_shoff)) >= file->ptrEnd)
	my_error();
    if (file->elf->e_shoff == 0)
	my_error();
    return (print_sh_name_64(file));
}

t_h	*call_my_nm(int fd)
{
    t_file_64	*file;
    int		size;
    void	*data;

    if ((file = malloc(sizeof(t_file_64))) == NULL)
	my_error();
    if ((size = lseek(fd, 0, SEEK_END)) == -1)
	my_error();
    if ((data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
	my_error();
    if (size < (int)sizeof(Elf64_Ehdr))
	my_error();
    file->ptrEnd = data + size;
    file->elf = (Elf64_Ehdr *)data;
    if (file->elf->e_ident[EI_MAG0] != ELFMAG0 ||
	    file->elf->e_ident[EI_MAG1] != ELFMAG1 ||
	    file->elf->e_ident[EI_MAG2] != ELFMAG2 ||
	    file->elf->e_ident[EI_MAG3] != ELFMAG3)
	my_error();
    if (file->elf->e_ident[EI_CLASS] == ELFCLASS64)
    {
      t_h *list = manage_64(file);
        munmap(data, size);
	return (list);
    }
    else if (file->elf->e_ident[EI_CLASS] == ELFCLASS32)
    {
	printf("Fichier 32b non gere pour le moment\n");
	exit(-1);
    }
    my_error();
    return NULL;
}
