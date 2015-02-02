/*
** free.c for freeswagg in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 16:17:41 2015 Antoine Buchser
** Last update Fri Jan 30 16:29:17 2015 Antoine Buchser
*/

#include <stdio.h>
#include "malloc.h"

void	free(void* ptr)
{
  t_blk	*blk;
  t_blk	*tmp;

  blk = ptr - (BLK_SIZE - 4);
  if (blk->self != ptr)
    return;
  blk->free = true;
  if (blk->prev && blk->prev->free)
    {
      tmp = blk->prev;
      tmp->size += blk->size + BLK_SIZE;
      tmp->next = blk->next;
      if (blk->next)
	blk->next->prev = tmp;
    }
  if (blk->next && blk->next->free)
    {
      tmp = blk->next;
      blk->next->prev->size += blk->next->size + BLK_SIZE;
      blk->next->prev->next = blk->next->next;
      if (tmp->next)
	tmp->next->prev = tmp->prev;
    }
  if (g_current == blk)
    {
      g_root = g_current == g_root ? NULL : g_root;
      g_current = blk->prev;
      sbrk(-(blk->size + BLK_SIZE));
    }
}
