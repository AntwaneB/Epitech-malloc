/*
** malloc.c for mallocduswag in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Tue Jan 27 15:23:33 2015 Antoine Buchser
** Last update Mon Feb  9 18:51:14 2015 Hugo SCHOCH
*/

#include "malloc.h"

t_blk	*g_root = NULL;
t_blk	*g_current = NULL;

static void	init_blk(t_blk *ptr, size_t size)
{
  ptr->next = NULL;
  ptr->prev = g_current;
  ptr->self = ptr->data;
  ptr->size = size;
  ptr->free = FALSE;
  if (g_current)
    g_current->next = ptr;
  g_current = ptr;
}

/*
** static t_blk	*split_block(t_blk *tmp, size_t size)
** {
**  t_blk		*newblk;
**
**  if (tmp->size - (size + BLK_SIZE) >= 4)
**    {
**      newblk = (t_blk *)(tmp->data + size + 4);
**      newblk->prev = tmp;
**      newblk->next = tmp->next;
**      newblk->size = tmp->size - (size + BLK_SIZE);
**      newblk->free = true;
**      newblk->self = newblk->data;
**      if (tmp->next)
**	tmp->next->prev = newblk;
**      tmp->next = newblk;
**      tmp->size = size;
**      if (g_current == tmp)
**	g_current = newblk;
**    }
**  (void)size;
**  return (tmp);
** }
*/

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
          ptr->free = FALSE;
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

  size = (size <= 0) ? 4 : size;
  size = PAGING(size);
  ptr = get_blk_addr(size);
  if (TRACE)
    my_alloc_stats(ALLOC, size);
  return (ptr->data);
}
