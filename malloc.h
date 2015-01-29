/*
** malloc.h for malloctropswagdelamortquitue in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 12:50:51 2015 Antoine Buchser
** Last update Thu Jan 29 15:27:32 2015 Antoine Buchser
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>

# define false		0
# define true		!false

typedef int	t_bool;

# define PAGING(s)	(s - 1) / 4 * 4 + 4

typedef struct	s_blk
{
  struct s_sgmt	*next;
  struct s_sgmt	*prev;
  void		*self;
  size_t	size;
  t_bool	free;
  char		data;
}		t_blk;

# define BLK_SIZE	sizeof(t_blk)

t_blk	*g_root = NULL;
t_blk	*g_current = NULL;

#endif /* !MALLOC_H_ */
