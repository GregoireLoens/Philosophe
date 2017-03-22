/*
** philo_struct.h for PSU_2016_philo in /home/loens_g/rendu/TEK2/SystemUnix/PSU_2016_philo/includes/philo_struct.h
**
** Made by Gregoire LOENS
** Login   <gregoire.loens@epitech.eu>
**
** Started on  Tue Mar 07 13:45:58 2017 Gregoire LOENS
** Last update Tue Mar 07 13:45:58 2017 Gregoire LOENS
*/

#ifndef PHILO_STRUCT_H_
# define PHILO_STRUCT_H_

# include		<pthread.h>
# include		<stdbool.h>

typedef enum		e_state
{
  UNDEF = -1,
  THINK = 0,
  EAT,
  REST
}			state;

typedef struct		s_args
{
  int			argc;
  char			**argv;
}			t_args;

typedef struct 		s_val
{
  int			nb_philo;
  int			nb_eat;
}			t_val;

typedef struct		s_table
{
  bool 			end;
  int			nb_philo;
  int			*priority;
}			t_table;

typedef struct		s_phil
{
  state			state;
  int			id;
  pthread_mutex_t	*left;
  pthread_mutex_t	*right;
  t_table		*table;
}			t_phil;

#endif /* !PHILO_STRUCT_H_ */
