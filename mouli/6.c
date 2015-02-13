/*
** main.c for testcool in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 14:09:44 2015 Antoine Buchser
** Last update Thu Feb 12 14:51:59 2015 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	try(int input, int wanted)
{
  if (input != wanted)
    printf("\x1B[31mFAIL\033[0m\n");
  else
    printf("\x1B[32mOKAY\033[0m\n");
}

int	main(void)
{
  printf("%p\n", sbrk(0));

  char	*lil = malloc(42);
  free(lil);

  char	*big = malloc(1457664);
  free(big);

  printf("%p\n", sbrk(0));

  return (0);
}
