/*
** realloc.c for reallocoul in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 16:18:25 2015 Antoine Buchser
** Last update Fri Jan 30 16:31:00 2015 Antoine Buchser
*/

#include <string.h>
#include <stdio.h>
#include "malloc.h"

static void	copy_content(void *dest, t_blk *blk)
{
  memcpy(dest, blk->self, blk->size);
}

void	*realloc(void *ptr, size_t size)
{
  t_blk	*blk;
  void	*dest;

  blk = ptr - (BLK_SIZE - 4);
  if (blk->self != ptr || blk->free)
    return (NULL);
  if (blk->size >= PAGING(size))
    return (ptr);
  dest = malloc(size);
  if (dest)
    copy_content(dest, blk);
  free(ptr);
  return (dest);
}
