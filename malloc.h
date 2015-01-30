/*
** malloc.h for malloctropswagdelamortquitue in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 12:50:51 2015 Antoine Buchser
** Last update Thu Jan 29 16:23:27 2015 Antoine Buchser
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
  struct s_blk	*next;
  struct s_blk	*prev;
  void		*self;
  size_t	size;
  t_bool	free;
  char		data[1];
}		t_blk;

# define BLK_SIZE	sizeof(t_blk)

extern t_blk	*g_root;
extern t_blk	*g_current;

void	*malloc(size_t size);

#endif /* !MALLOC_H_ */
