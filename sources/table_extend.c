/*
** table_extend.c for PSU_2016_philo in /home/soszyn_h/rendu/PSU/PSU_2016_philo/sources/table_extend.c
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Sun Mar 19 11:06:10 2017 Hugo SOSZYNSKI
** Last update Sun Mar 19 11:06:10 2017 Hugo SOSZYNSKI
*/

#include	<pthread.h>
#include	"table.h"

int		table_get_left_priority(t_table *table, int id)
{
  int		priority;
  int		idx;

  if (id == 0)
    idx = table->nb_philo - 1;
  else
    idx = id - 1;
  pthread_mutex_lock(&g_table_mutex);
  priority = table->priority[idx];
  pthread_mutex_unlock(&g_table_mutex);
  return (priority);
}

int		table_get_right_priority(t_table *table, int id)
{
  int		priority;
  int		idx;

  idx = (id + 1) % table->nb_philo;
  pthread_mutex_lock(&g_table_mutex);
  priority = table->priority[idx];
  pthread_mutex_unlock(&g_table_mutex);
  return (priority);
}

