/*
** free.c for freeswagg in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 16:17:41 2015 Antoine Buchser
** Last update Fri Jan 30 16:29:17 2015 Antoine Buchser
*/

#include "malloc.h"

void	merge_prev(t_blk *blk)
{
  t_blk	*prev;

  if (blk->prev && blk->prev->free)
    {
      prev = blk->prev;
      prev->next = blk->next;
      prev->size += blk->size + BLK_SIZE;
      if (blk->next)
	blk->next->prev = prev;
      if (g_current == blk)
	g_current = prev;
    }
}

void	merge_next(t_blk *blk)
{
  t_blk	*next;

  if (blk->next && blk->next->free)
    {
      next = blk->next;
      blk->next = next->next;
      blk->size += next->size + BLK_SIZE;
      if (blk->next)
	blk->next->prev = blk;
      if (g_current == next)
	g_current = blk;
    }
}

void	free(void* ptr)
{
  t_blk	*blk;
  t_blk	*tmp;

  if (!ptr)
    return;
  blk = ptr - (BLK_SIZE - 4);
  if (blk->self != ptr || blk->free)
    return;
  blk->free = true;
  merge_next(blk);
  merge_prev(blk);
  if (g_current->free)
    {
      g_root = g_current == g_root ? NULL : g_root;
      tmp = g_current;
      g_current = g_current->prev;
      if (g_current)
	g_current->next = NULL;
      sbrk(-(tmp->size + BLK_SIZE));
    }
}
