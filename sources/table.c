/*
** table.c for PSU_2016_philo in /home/loens_g/rendu/TEK2/SystemUnix/PSU_2016_philo/sources/table.c
**
** Made by Gregoire LOENS
** Login   <gregoire.loens@epitech.eu>
**
** Started on  Wed Mar 15 11:36:30 2017 Gregoire LOENS
** Last update Wed Mar 15 11:36:30 2017 Gregoire LOENS
*/

#include	<malloc.h>
#include	"philo_struct.h"

pthread_mutex_t	g_table_mutex = PTHREAD_MUTEX_INITIALIZER;


void		table_set_end(t_table *table)
{
  pthread_mutex_lock(&g_table_mutex);
  table->end = true;
  pthread_mutex_unlock(&g_table_mutex);
}

int		table_check_priority(t_table *table, int id)
{
  int		ret;

  pthread_mutex_lock(&g_table_mutex);
  ret = table->priority[id];
  pthread_mutex_unlock(&g_table_mutex);
  return (ret);
}

t_table		*table_init(t_table *table, t_val *val)
{
  int		cpt;

  cpt = 0;
  table->end = false;
  table->nb_philo = val->nb_philo;
  table->priority = malloc(sizeof(int) * val->nb_philo);
  if (table->priority == NULL)
    return (NULL);
  while (cpt < val->nb_philo)
  {
    table->priority[cpt] = val->nb_eat;
    cpt++;
  }
  return (table);
}

bool		table_check_end(t_table *table)
{
  bool		ret;

  pthread_mutex_lock(&g_table_mutex);
  ret = table->end;
  pthread_mutex_unlock(&g_table_mutex);
  return (ret);
}

void		table_update_priority(t_table *table, int id)
{
  pthread_mutex_lock(&g_table_mutex);
  table->priority[id] -= 1;
  pthread_mutex_unlock(&g_table_mutex);
}
