/*
** malloc.c for mallocduswag in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Jan 27 15:23:33 2015 Antoine Buchser
** Last update Mon Feb  9 18:52:46 2015 Hugo SCHOCH
*/

#include <stdio.h>
#include <stdint.h>
#include "malloc.h"

void	show_alloc_mem(void)
{
  t_blk	*tmp;

  printf("break : 0x%X\n", (unsigned int)((long int)sbrk(0)));
  tmp = g_root;
  while (tmp)
    {
      if (!(tmp->free))
        {
          printf("0x%X - 0x%X : %u octets\n",
                 (unsigned int)((long int)tmp),
                 (unsigned int)((long int)(tmp->data + tmp->size + 4)),
                 (unsigned int)tmp->size);
        }
      tmp = tmp->next;
    }
}

void		my_alloc_stats(int type, size_t size)
{
  static size_t	frees = 0;
  static size_t allocs = 0;
  static size_t	freed_size = 0;
  static size_t	alloced_size = 0;

  if (type == FREE)
    {
      frees++;
      freed_size += size;
    }
  else if (type == ALLOC)
    {
      allocs++;
      alloced_size += size;
    }
  else
    {
      fprintf(stderr,
	      "\nHEAP SUMMARY:\n" \
	      "  total heap usage: %u allocs, %u frees, %u " \
	      "bytes allocated\n" \
	      "     unfreed bytes: %u bytes in %u blocks\n",
	      (uint)allocs, (uint)frees, (uint)alloced_size,
	      (uint)(alloced_size - freed_size), (uint)(allocs - frees));
    }
}

void	show_alloc_stats(void)
{
  my_alloc_stats(PRINT, 0);
}
