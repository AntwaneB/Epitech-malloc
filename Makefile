##
## Makefile for mallocduswaglovesupernatural in /home/buchse_a/Projects/PSU_2014_malloc
## 
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
## 
## Started on  Tue Jan 27 15:24:06 2015 Antoine Buchser
## Last update Thu Jan 29 16:20:22 2015 Antoine Buchser
##

CC		=	gcc
CFLAGS		+=	-fPIC -W -Wall -Wextra -Werror -g
LDFLAGS		=	-shared -fPIC
RM		=	rm -f

SRCS		=	malloc.c \
			realloc.c \
			free.c \
			show_alloc_mem.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	libmy_malloc_$(HOSTTYPE).so

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
			ln -fs $(NAME) libmy_malloc.so

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)
			$(RM) libmy_malloc.so

re:			fclean all

