/*
** malloc.c for mallocduswag in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Jan 27 15:23:33 2015 Antoine Buchser
** Last update Thu Jan 29 15:54:15 2015 Antoine Buchser
*/

#include "malloc.h"

static void	init_blk(t_blk *ptr, size_t size)
{
  ptr->next = NULL;
  ptr->prev = g_current;
  ptr->self = ptr;
  ptr->size = size;
  ptr->free = false;
  if (g_current)
    g_current->next = ptr;
  g_current = ptr;
}

static void	*get_blk_addr(size_t size)
{
  t_blk		*ptr;
  t_blk		*tmp;

  ptr = NULL;
  tmp = g_root;
  while (!ptr && tmp)
    {
      if (tmp->size >= size && tmp->free)
	{
	  ptr = tmp;
	  ptr->free = false;
	}
      tmp = tmp->next;
    }
  if (!ptr)
    {
      if ((ptr = sbrk(BLK_SIZE + size)) == (void *)-1)
	return (NULL);
      else
	init_blk(ptr, size);
    }
  if (!g_root)
    g_root = ptr;
  return (ptr);
}

void	*malloc(size_t size)
{
  t_blk	*ptr;

  size = PAGING(size);
  ptr = get_blk_addr(size);
  return (&(ptr->data));
}
