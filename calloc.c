/*
** realloc.c for reallocoul in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 16:18:25 2015 Antoine Buchser
** Last update Wed Feb 11 19:12:11 2015 Antoine Buchser
*/

#include <string.h>
#include "malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  void	*dest;

  if ((dest = malloc(nmemb * size)) == NULL)
    return (NULL);
  memset(dest, 0, nmemb * size);
  return (dest);
}
