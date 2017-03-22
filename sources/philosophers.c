/*
** philosophers.c for PSU_2016_philo in /home/soszyn_h/rendu/PSU/PSU_2016_philo/sources/philosophers.c
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Tue Mar 14 11:25:55 2017 Hugo SOSZYNSKI
** Last update Tue Mar 14 11:25:55 2017 Hugo SOSZYNSKI
*/

#include	<pthread.h>
#include	<errno.h>
#include	"philosophers.h"
#include	"philosophers_states.h"
#include 	"table.h"

static bool	should_eat(t_phil *self)
{
  int		self_priority;

  self_priority = table_check_priority(self->table, self->id);
  if (self_priority >= table_get_left_priority(self->table, self->id) &&
      self_priority >= table_get_right_priority(self->table, self->id))
    return (true);
  return (false);
}

static void	even_philosopher(t_phil *self)
{
  int		ret;

  while (table_check_end(self->table) == false)
  {
    if (self->state != THINK && should_eat(self))
    {
      ret = pthread_mutex_trylock(self->left);
      if (ret != EBUSY)
	philosopher_think(self, self->left);
      else
      {
	if (self->state != REST)
	  philosopher_sleep(self);
      }
    }
    else if (self->state == THINK)
    {
      ret = pthread_mutex_trylock(self->right);
      if (ret != EBUSY)
	philosopher_eat(self, self->left, self->right);
    }
    ret = table_check_priority(self->table, self->id);
    if (ret == 0)
      table_set_end(self->table);
  }
}

static void	odd_philosopher(t_phil *self)
{
  int		ret;

  while (table_check_end(self->table) == false)
  {
    if (self->state != THINK && should_eat(self))
    {
      ret = pthread_mutex_trylock(self->right);
      if (ret != EBUSY)
	philosopher_think(self, self->right);
      else
      {
	if (self->state != REST)
	  philosopher_sleep(self);
      }
    }
    else if (self->state == THINK)
    {
      ret = pthread_mutex_trylock(self->left);
      if (ret != EBUSY)
	philosopher_eat(self, self->right, self->left);
    }
    ret = table_check_priority(self->table, self->id);
    if (ret == 0)
      table_set_end(self->table);
  }
}

void		*philosophers(void *args)
{
  t_phil	*self;

  self = args;
  if (self->id % 2 == 0)
    even_philosopher(self);
  else
    odd_philosopher(self);
  pthread_exit(0);
}