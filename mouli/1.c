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

void	try(int input, int wanted)
{
  if (input != wanted)
    printf("\x1B[31mFAIL\033[0m\n");
  else
    printf("\x1B[32mOKAY\033[0m\n");
}

int	main(void)
{
  char	*test = malloc(5);
  int	i;

  if (test == NULL)
    {
      write(1, "Malloc failed\n", strlen("Malloc failed\n"));
      return (0);
    }

  test[0] = 't';
  test[1] = 'e';
  test[2] = 's';
  test[3] = 't';
  test[4] = '\0';
  printf("*test == test : "); try(strcmp(test, "test") == 0, 1);

  free(test);

  char	*lol = malloc(18);
  lol[0] = 'l';
  lol[1] = 'o';
  lol[2] = 'l';
  lol[3] = '\0';
  printf("*lol == lol : "); try(strcmp(lol, "lol") == 0, 1);

  free(lol);

  char	*big = malloc(22);
  for (i = 0; i < 21; i++)
    big[i] = 'a' + i;
  big[i] = '\0';
  printf("*big == [a-u] : "); try(strcmp(big, "abcdefghijklmnopqrstu") == 0, 1);
  printf("big == test : "); try(big == test, 1);

  printf("\n");

  char	*newbig = realloc(big, 150);
  printf("newbig != big : "); try(newbig == big, 0);

  char	*newbig2 = realloc(newbig, 22);
  printf("newbig == newbig2 : "); try(newbig == newbig2, 1);
  printf("*newbig2 == [a-u] : "); try(strcmp(newbig2, "abcdefghijklmnopqrstu") == 0, 1);
  free(newbig2);

  show_alloc_mem();

  show_alloc_stats();

  return (0);
}
