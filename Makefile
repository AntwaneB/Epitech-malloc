##
## Makefile for mallocduswaglovesupernatural in /home/buchse_a/Projects/PSU_2014_malloc
## 
## Made by Antoine Buchser
## Login   <buchse_a@epitech.net>
## 
## Started on  Tue Jan 27 15:24:06 2015 Antoine Buchser
## Last update Tue Jan 27 15:50:18 2015 Antoine Buchser
##

CC	=	gcc
CFLAGS	+=	-W -Wall -Wextra -Werror
RM	=	rm -f

SRCS	=	malloc.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy_malloc_$(HOSTTYPE).so

all:		$(NAME)

$(NAME):
		$(CC) -c -fPIC $(SRCS)
		$(CC) -o $(NAME) -shared $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

