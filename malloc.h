/*
** malloc.h for malloctropswagdelamortquitue in /home/buchse_a/Projects/PSU_2014_malloc
** 
** Made by Antoine Buchser
** Login   <buchse_a@epitech.net>
** 
** Started on  Thu Jan 29 12:50:51 2015 Antoine Buchser
** Last update Thu Feb 12 17:22:21 2015 Antoine Buchser
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>

# define FALSE		0
# define TRUE		!FALSE

typedef int		t_bool;
typedef unsigned int	uint;

# define PAGING(s)	(s - 1) / 8 * 8 + 8

typedef struct		s_blk
{
  struct s_blk		*next;
  struct s_blk		*prev;
  size_t		size;
  t_bool		free;
}		t_blk;

# define BLK_SIZE	sizeof(struct s_blk)

# define FREE		-1
# define ALLOC		1
# define PRINT		0
# define TRACE		1

extern t_blk	*g_root;
extern t_blk	*g_current;
extern size_t	g_pagesize;

void	*malloc(size_t);
void	free(void *);
void	*realloc(void *, size_t);
void	*calloc(size_t, size_t);
void	show_alloc_mem(void);
void	my_alloc_stats(int, size_t);
void	show_alloc_stats(void);

#endif /* !MALLOC_H_ */
