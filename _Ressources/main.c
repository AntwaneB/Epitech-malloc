/*
** main.c for testcool in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 14:09:44 2015 Antoine Buchser
** Last update Fri Jan 30 12:41:57 2015 Antoine Buchser
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
  char	*test = malloc(5);

  if (test == NULL)
    {
      write(1, "Malloc failed\n", strlen("Malloc failed\n"));
      return (0);
    }

  printf("Malloced test at : %p\n", test);
  test[0] = 't';
  test[1] = 'e';
  test[2] = 's';
  test[3] = 't';
  test[4] = '\0';
  printf("*test = %s\n", test);

  free(test);
  printf("Freed test\n", test);

  char	*lol = malloc(3);
  printf("\nMalloced lol at : %p\n", lol);
  lol[0] = 'l';
  lol[1] = 'o';
  lol[2] = 'l';
  lol[3] = '\0';
  printf("*lol = %s\n", lol);

  free(lol);
  printf("Freed lol\n", lol);

  return (0);
}
