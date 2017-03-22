/*
** philosophers_utils.c for PSU_2016_philo in /home/soszyn_h/rendu/PSU/PSU_2016_philo/sources/philosophers_utils.c
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Wed Mar 15 13:08:58 2017 Hugo SOSZYNSKI
** Last update Wed Mar 15 13:08:58 2017 Hugo SOSZYNSKI
*/

#include		<pthread.h>
#include		<malloc.h>
#include		"philosophers.h"

static pthread_mutex_t	*create_mutex_tab(int nb)
{
  pthread_mutex_t	*mutexes;
  int			cpt;
  int			ret;

  mutexes = malloc(sizeof(pthread_mutex_t) * nb);
  if (mutexes == NULL)
    return (NULL);
  cpt = 0;
  while (cpt < nb)
  {
    ret = pthread_mutex_init(&(mutexes[cpt]), NULL);
    if (ret != 0)
      return (NULL);
    cpt++;
  }
  return (mutexes);
}

static int		alloc_philo(t_table *table,
				      t_phil **philo,
				      pthread_mutex_t **mutexes)
{
  *philo = malloc(sizeof(t_phil) * table->nb_philo);
  if (*philo == NULL)
    return (1);
  *mutexes = create_mutex_tab(table->nb_philo);
  if (*mutexes == NULL)
  {
    free(*philo);
    return (1);
  }
  return (0);
}

t_phil			*philosophers_create(t_table *table,
						   pthread_mutex_t **mutexes)
{
  t_phil		*philo;
  int			cpt;

  if (alloc_philo(table, &philo, mutexes) != 0)
    return (NULL);
  cpt = 0;
  while (cpt < table->nb_philo)
  {
    philo[cpt].id = cpt;
    philo[cpt].table = table;
    philo[cpt].state = UNDEF;
    philo[cpt].left = &((*mutexes)[cpt]);
    philo[cpt].right = &((*mutexes)[(cpt + 1) % table->nb_philo]);
    cpt++;
  }
  return (philo);
}

void		mutex_destroy(pthread_mutex_t *tab, t_table *table)
{
  int		cpt;

  cpt = 0;
  while (cpt < table->nb_philo)
  {
    pthread_mutex_destroy(&(tab[cpt]));
    cpt++;
  }
  free(tab);
}

int		launch_philosophers(t_table *table, t_phil *philo)
{
  int		cpt;
  pthread_t	*threads;
  int		ret;

  threads = malloc(sizeof(pthread_t) * table->nb_philo);
  if (threads == NULL)
    return (1);
  cpt = 0;
  while (cpt < table->nb_philo)
  {
    ret = pthread_create(&(threads[cpt]), NULL, philosophers, &(philo[cpt]));
    if (ret != 0)
      return (1);
    cpt++;
  }
  cpt = 0;
  while (cpt < table->nb_philo)
  {
    pthread_join(threads[cpt], NULL);
    cpt++;
  }
  free(threads);
  return (0);
}