/*
** philosophers.h for PSU_2016_philo in /home/soszyn_h/rendu/PSU/PSU_2016_philo/includes/philosophers.h
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 13 14:40:34 2017 Hugo SOSZYNSKI
** Last update Mon Mar 13 14:40:34 2017 Hugo SOSZYNSKI
*/

#ifndef PHILOSOPHERS_H_
# define PHILOSOPHERS_H_

# include	"philo_struct.h"

/*
** Verify the arguments passed by the command line and fill a t_val structure.
** Return 0 on success, 1 otherwise.
*/
int		verif_arg(t_val *philo, int argc, char **argv);

/*
** Allocate and initialise philosophers structures
** Return a philosophers table on success, NULL otherwise.
*/
t_phil		*philosophers_create(t_table *table, pthread_mutex_t **mut);

/*
** Free the mutex tab
*/
void		mutex_destroy(pthread_mutex_t *tab, t_table *table);

/*
** Thread starting function
*/
void		*philosophers(void *args);

/*
** Create the threads and launch them.
** Return 0 on success, 1 otherwise.
*/
int		launch_philosophers(t_table *table, t_phil *philo);

#endif /* !PHILOSOPHERS_H_ */
