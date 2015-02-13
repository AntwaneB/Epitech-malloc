/*
** realloc.c for reallocoul in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 16:18:25 2015 Antoine Buchser
** Last update Thu Feb 12 13:56:11 2015 Antoine Buchser
*/

#include <string.h>
#include "malloc.h"

static void	copy_content(void *dest, t_blk *blk)
{
  memcpy(dest, (char*)blk + BLK_SIZE, blk->size);
}

void	*realloc(void *ptr, size_t size)
{
  t_blk	*blk;
  void	*dest;

  if (!ptr)
    return (malloc(size));
  if (size == 0)
    {
      free(ptr);
      return (NULL);
    }
  blk = (t_blk*)((char*)ptr - BLK_SIZE);
  if (blk->free)
    return (NULL);
  if (blk->size >= PAGING(size))
    return (ptr);
  dest = malloc(size);
  if (dest)
    copy_content(dest, blk);
  free(ptr);
  return (dest);
}
