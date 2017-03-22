##
## Makefile for philo in /home/loens_g/rendu/TEK2/SystemUnix/PSU_2016_philo
## 
## Made by loens_g
## Login   <loens_g@epitech.net>
## 
## Started on  Tue Mar  7 18:08:46 2017 loens_g
## Last update Fri Mar 17 10:50:06 2017 Hugo SOSZYNSKI
##

INCLUDE		=	-I./includes

RM		=	rm -rf

CFLAGS		+=	$(INCLUDE)

CFLAGS		+=	-MD -MP

CFLAGS		+=	-W -Wall -Wextra

LDFLAGS		+=	-L. -lriceferee -lpthread

CC		=	gcc

DEBUG		?=	0

ifeq	($(DEBUG), 1)
	CC	=	gcc
	CFLAGS	+=	-g -ggdb3
endif

NAME		=	philo

SRCS		=	$(shell cat ./sources.mk)

OBJS		=	$(SRCS:.c=.o)

DEPS		=	$(SRCS:.c=.d)


all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

%.o:	%.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean:	clean
	$(RM) $(NAME) $(CLI)

re:	fclean
	@$(MAKE) all

.PHONY:	 all clean fclean re

-include	$(DEPS)
