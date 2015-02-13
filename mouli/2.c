/*
** main.c for testcool in /home/buchse_a/Projects/PSU_2014_malloc
**
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
**
** Started on  Thu Jan 29 14:09:44 2015 Antoine Buchser
** Last update Thu Feb 12 17:09:21 2015 Antoine Buchser
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
  int	*ints;
  int	i;

  ints = malloc(4 * sizeof(int));
  for (i = 0; i < 4; i++)
    ints[i] = i + 1337;
  for (i = 0; i < 4; i++)
    {
      printf("ints[%d] == %d : ", i, i + 1337); try(ints[i] == i + 1337, 1);
    }
  free(ints);

  void	*pos = sbrk(0);

  char	*pows = malloc(3274);
  free(pows);
  printf("pos == sbrk(0) : "); try(pos == sbrk(0), 1);
  printf("pos(%p) != sbrk(%p)\n", pos, sbrk(0));

  return (0);
}
