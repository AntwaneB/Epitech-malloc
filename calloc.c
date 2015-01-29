/*
** calloc.c for malloctropouflol in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 16:09:01 2015 Antoine Buchser
** Last update Thu Jan 29 16:12:22 2015 Antoine Buchser
*/

#include "malloc.h"

void	*calloc(size_t size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    return (NULL);
  memset(ptr, 0, size);
  return (ptr);
}
