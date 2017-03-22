/*
** philophers_states.c for PSU_2016_philo in /home/soszyn_h/rendu/PSU/PSU_2016_philo/sources/philophers_states.c
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Fri Mar 17 11:48:03 2017 Hugo SOSZYNSKI
** Last update Fri Mar 17 11:48:03 2017 Hugo SOSZYNSKI
*/

#include	<pthread.h>
#include	"philo_struct.h"
#include	"extern.h"
#include	"table.h"

void		philosopher_sleep(t_phil *self)
{
  self->state = REST;
  lphilo_sleep();
}

void		philosopher_eat(t_phil *self,
				    pthread_mutex_t *first,
				    pthread_mutex_t *last)
{
  lphilo_take_chopstick(last);
  self->state = EAT;
  lphilo_eat();
  table_update_priority(self->table, self->id);
  pthread_mutex_unlock(first);
  lphilo_release_chopstick(first);
  pthread_mutex_unlock(last);
  lphilo_release_chopstick(last);
  self->state = REST;
  lphilo_sleep();
}

void		philosopher_think(t_phil *self,
				      pthread_mutex_t *chopstick)
{
  lphilo_take_chopstick(chopstick);
  self->state = THINK;
  lphilo_think();
}