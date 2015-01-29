/*
** main.c for testcool in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 14:09:44 2015 Antoine Buchser
** Last update Thu Jan 29 15:57:03 2015 Antoine Buchser
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

  write(1, "=== Start ===\n", strlen("=== Start ===\n"));
  test[0] = 'l';
  write(1, "0... ", strlen("0... "));
  test[1] = 'o';
  write(1, "1... ", strlen("1... "));
  test[2] = 'l';
  write(1, "2... ", strlen("2... "));
  test[3] = '\n';
  write(1, "3... ", strlen("3... "));
  test[4] = '\0';
  write(1, "4... ", strlen("4... "));
  write(1, "\n=== End ===\n", strlen("\n=== End ===\n"));

  write(1, test, 5);

  while (1);

  return (0);
}
