/*
** malloc.c for mallocduswag in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Jan 27 15:23:33 2015 Antoine Buchser
** Last update Fri Jan 30 16:29:48 2015 Antoine Buchser
*/

#include <stdio.h>
#include <stdint.h>
#include "malloc.h"

void	show_alloc_mem(void)
{
  t_blk	*tmp;

  printf("break : 0x%05X\n", (unsigned int)((long int)sbrk(0)));
  tmp = g_root;
  while (tmp)
    {
      printf("0x%05X - 0x%05X : %u octets\n",
	     (unsigned int)((long int)tmp),
	     (unsigned int)((long int)(tmp + tmp->size)),
	     (unsigned int)tmp->size);
      tmp = tmp->next;
    }
}
