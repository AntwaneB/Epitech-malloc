##
## Makefile for mallocduswaglovesupernatural in /home/buchse_a/Projects/PSU_2014_malloc
## 
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
## 
## Started on  Tue Jan 27 15:24:06 2015 Antoine Buchser
## Last update Thu Jan 29 16:07:07 2015 Antoine Buchser
##

CC	=	gcc
CFLAGS	+=	-fPIC -W -Wall -Wextra -Werror
LDFLAGS	=	-shared
RM	=	rm -f

SRCS	=	malloc.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy_malloc_$(HOSTTYPE).so

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

