/*
** free.c for freeswagg in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 16:17:41 2015 Antoine Buchser
** Last update Fri Jan 30 12:39:48 2015 Antoine Buchser
*/

#include <stdio.h>
#include "malloc.h"

void	free(void* ptr)
{
  t_blk	*blk;

  blk = ptr - (BLK_SIZE - 4);
  if (blk->self != ptr)
    return;
  blk->free = true;
  printf("prev = %p\n", blk->prev);
  printf("prev = %p\n", blk->);
}
