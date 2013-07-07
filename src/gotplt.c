/*
** gotplt.c for  in /home/pastek/Project/tek2/Ftrace/src
** 
** Made by jonathan tran
** Login   <tran_v@epitech.net>
** 
** Started on  Sun Jul 07 08:39:10 2013 jonathan tran
** Last update Sun Jul 07 08:39:10 2013 jonathan tran
*/
#include <elf.h>
#include "ftrace.h"
#include "gotplt.h"

static Elf64_Ehdr	*__elf;
static Elf64_Shdr	*__sections;
static Elf64_Shdr	*__got;
static Elf64_Shdr	*__plt;
static Elf64_Shdr	*__dynsym;
static Elf64_Shdr	*__dynstr;
static void		*__strtab;

static void		*__get_dynstr()
{
  unsigned	i;

  for (i = 0; i < __elf->e_shnum; i++)
    if (!strcmp(".dynstr", (char *) __strtab + __sections[i].sh_name))
      return ((void *) __elf + __sections[i].sh_offset);
  return (0);
}

void	gotplt_initialize(int fd)
{
  int	i;
  int	size;

  __elf = 0;
  if ((size = lseek(fd, 0, SEEK_END)) == -1)
    return ;
  if ((__elf = (Elf64_Ehdr *) mmap(0, size, PROT_READ, MAP_SHARED, fd, 0))
      == MAP_FAILED)
  {
    __elf = 0;
    return ;
  }
  __sections = (Elf64_Shdr *) ((void *) __elf + __elf->e_shoff);
  __strtab = (void *) __elf + __sections[__elf->e_shstrndx].sh_offset;
  for (i = 0; i < __elf->e_shnum; i++)
    if (__sections[i].sh_type != SHT_NULL)
    {
      if (!strcmp(".got", (char *) (__strtab + __sections[i].sh_name)))
	__got = __sections + i;
      if (!strcmp(".plt", (char *) (__strtab + __sections[i].sh_name)))
	__plt = __sections + i;
      else if (__sections[i].sh_type == SHT_DYNSYM)
      {
	__dynsym = __sections + i;
	__dynstr = __get_dynstr();
      }
    }
}

void		gotplt_add_dynamic_symbol(t_h *symbols, reg64_t rip, int pid)
{
  unsigned		i;
  unsigned		ndx;
  char			*straddr;
  char			*name;

  ndx = ptrace(PTRACE_PEEKTEXT, pid,
      rip + 7, 0);
  if (((Elf64_Sym *)((void *) __elf + __dynsym->sh_offset))[ndx].st_name)
  {
    asprintf(&straddr, "%x", (unsigned int) rip);
    asprintf(&name, "%s", (char *) __dynstr + ((Elf64_Sym *)((void *) __elf
	  + __dynsym->sh_offset))[ndx].st_name);
    list_add(symbols, straddr, name, CALL_LINKED);
  }
}

int	in_plt(reg64_t rip)
{
  if (!__plt)
    return (0);
  return (rip >= 0x400000 + __plt->sh_offset
      && rip < 0x400000 + __plt->sh_offset + __plt->sh_size);
}
