/*
** malloc.c for mallocduswag in /home/buchse_a/Projects/PSU_2014_malloc
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Tue Jan 27 15:23:33 2015 Antoine Buchser
** Last update Thu Feb 12 17:15:28 2015 Antoine Buchser
*/

#include "malloc.h"

t_blk	*g_root = NULL;
t_blk	*g_current = NULL;
size_t	g_pagesize = 0;

static void	init_blk(t_blk *ptr, size_t size)
{
  ptr->next = NULL;
  ptr->prev = g_current;
  ptr->size = size;
  ptr->free = FALSE;
  if (g_current)
    g_current->next = ptr;
  g_current = ptr;
}

static t_blk	*split_block(t_blk *tmp, size_t size)
{
  t_blk		*newblk;

  if ((int)(tmp->size - (size + BLK_SIZE)) >= 8)
    {
      newblk = (t_blk *)((char*)tmp + BLK_SIZE + size);
      newblk->prev = tmp;
      newblk->next = tmp->next;
      newblk->size = tmp->size - (size + BLK_SIZE);
      newblk->free = TRUE;
      if (tmp->next)
	tmp->next->prev = newblk;
      tmp->next = newblk;
      tmp->size = size;
      if (g_current == tmp)
	g_current = newblk;
    }
  tmp->free = FALSE;
  return (tmp);
}

static void	*get_blk_addr(size_t size)
{
  t_blk		*ptr;
  t_blk		*tmp;
  size_t	pgsze_size;

  ptr = NULL;
  tmp = g_root;
  while (!ptr && tmp)
    {
      if (tmp->size >= size && tmp->free)
	ptr = split_block(tmp, size);
      tmp = tmp->next;
    }
  if (!ptr)
    {
      pgsze_size = (BLK_SIZE + size - 1) / g_pagesize
	* g_pagesize + g_pagesize;
      if ((ptr = sbrk(pgsze_size)) == (void *)-1)
	return (NULL);
      else
	{
	  init_blk(ptr, size);
	  ptr->size = pgsze_size - BLK_SIZE;
	  ptr = split_block(ptr, size);
	}
    }
  g_root = !g_root ? ptr : g_root;
  return (ptr);
}

void	*malloc(size_t size)
{
  t_blk	*ptr;

  if (g_pagesize == 0)
    g_pagesize = getpagesize();
  size = (size <= 0) ? 8 : size;
  size = PAGING(size);
  ptr = get_blk_addr(size);
  if (TRACE)
    my_alloc_stats(ALLOC, size);
  return ((char*)ptr + BLK_SIZE);
}
