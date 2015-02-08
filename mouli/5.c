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

void	try(int input, int wanted)
{
  if (input != wanted)
    printf("\x1B[31mFAIL\033[0m\n");
  else
    printf("\x1B[32mOKAY\033[0m\n");
}

int	main(void)
{
  char	*datas = malloc(150);

  show_alloc_mem();
  printf("==========================\n");

  free(datas);

  show_alloc_mem();
  printf("==========================\n");

  char	*p1 = malloc(15);
  char	*p2 = malloc(121);

  show_alloc_mem();

  return (0);
}
