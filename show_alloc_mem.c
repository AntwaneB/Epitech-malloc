/*
** malloc.c for mallocduswag in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Jan 27 15:23:33 2015 Antoine Buchser
** Last update Fri Feb  6 11:42:37 2015 Antoine Buchser
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
		 (unsigned int)((long int)(tmp + tmp->size)),
		 (unsigned int)tmp->size);
	}
      tmp = tmp->next;
    }
}
