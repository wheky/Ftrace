/*
** main.c for  in /home/simoni_w/projet/teck2/NMObjdump
** 
** Made by 
** Login   <simoni_w@epitech.net>
** 
** Started on  Wed Mar 13 11:14:00 2013 
** Last update Wed Mar 13 11:14:00 2013 
*/
#define _GNU_SOURCE
#include <stdio.h>
#include "get_static.h"

int		print_result_64(char *tab, t_file_64 *file, int i,
	t_h *list)
{
    char	*addr;
    char	*name;

    asprintf(&addr, "%x", (unsigned int)file->symtab[i].st_value);
    asprintf(&name, "%s", &tab[file->symtab[i].st_name]);
    list_add(list, addr, name);
    return (0);
}

t_h		*manage_symtab_64(t_file_64 *file, int i)
{
    int		len;
    char	*tab;
    t_h	*list;

    list = list_init();
    if ((void *)(file->symtab = (Elf64_Sym *)((char *)file->elf
		    + file->shdr[i].sh_offset)) >= file->ptrEnd)
	 my_error();
    if ((void *)(tab = (char *)((char *)file->elf
	    + file->shdr[file->shdr[i].sh_link].sh_offset)) >= file->ptrEnd)
	 my_error();
    if ((len = file->shdr[i].sh_size / sizeof(Elf64_Sym)) < 1)
	 my_error();
    if (run_through_64(tab, file, list, len) == -1)
	 my_error();
    return (list);
}

int		run_through_64(char *tab, t_file_64 *file, t_h *list, int len)
{
    int 	i;

    i = 0;
    while (i < len)
    {
	if ((void *)(&file->symtab[i] + sizeof(Elf64_Sym)) >= file->ptrEnd)
	     my_error();
	if (strcmp(&tab[file->symtab[i].st_name], "") != 0 &&
		file->symtab[i].st_info != 4)
	    print_result_64(tab, file, i, list);
	i++;
    }
    return (0);
}

t_h		*print_sh_name_64(t_file_64 *file)
{
    int		shnum;
    int		i;

    i = 0;
    shnum = file->elf->e_shnum;
    while (i < shnum)
    {
	if ((void *)&(file->shdr[i]) + sizeof(Elf64_Shdr) >= file->ptrEnd)
	     my_error();
	if (file->shdr[i].sh_type == SHT_RELA)
	{
	  unsigned j = 0;
	  while (j < file->shdr[i].sh_size)
	  {
	    Elf64_Rela* p = (void *) file->elf + file->shdr[i].sh_offset + j;
	    //printf("%p\n", (void *) (p++)->r_offset);
	    j += sizeof(Elf64_Rela);
	  }
	}
	if (file->shdr[i].sh_type == SHT_SYMTAB)
	    return (manage_symtab_64(file, i));
	i++;
    }
    return (0);
}
