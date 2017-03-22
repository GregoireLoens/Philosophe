/*
** philosophers_states.h for PSU_2016_philo in /home/soszyn_h/rendu/PSU/PSU_2016_philo/includes/philosophers_states.h
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Fri Mar 17 11:56:15 2017 Hugo SOSZYNSKI
** Last update Fri Mar 17 11:56:15 2017 Hugo SOSZYNSKI
*/

#ifndef PHILOSOPHERS_STATES_H_
# define PHILOSOPHERS_STATES_H_

# include	<pthread.h>
# include	"philo_struct.h"

/*
** This function make the philosopher eat and then rest
** The "first" parameter is the first mutex to be unlocked
** The "last" parameter is the last mutex to be unlocked
** and the chopstick to be taken
*/
void		philosopher_eat(t_phil *self,
				    pthread_mutex_t *first,
				    pthread_mutex_t *last);

/*
** This function make the philosopher think
** The "chopstick" parameter is the chopstick to be taken
*/
void		philosopher_think(t_phil *self,
				      pthread_mutex_t *chopstick);

/*
** This function make the philosopher sleep
*/
void		philosopher_sleep(t_phil *self);

#endif /* !PHILOSOPHERS_STATES_H _*/
