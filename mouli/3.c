/*
** main.c for testcool in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 14:09:44 2015 Antoine Buchser
** Last update Fri Jan 30 16:31:41 2015 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	try(int input, int wanted)
{
  if (input != wanted)
    printf("\x1B[31mFAIL\033[0m\n");
  else
    printf("\x1B[32mOKAY\033[0m\n");
  return (input == wanted);
}

int	main(void)
{
  int	*ints;
  int	*prev;
  void	*pos;
  int	i;

  pos = sbrk(0);
  for (i = 1; i <= 10005; i++)
    {
      ints = malloc(4 * (rand() % 10000) * sizeof(int));
      free(ints);
      printf("sbrk(0) == pos : ");
      if (!try(sbrk(0) == pos, 1))
	printf("sbrk(%p) != pos(%p)\n", sbrk(0), pos);
    }

  return (0);
}
