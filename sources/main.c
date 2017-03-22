/*
** main.c for PSU_2016_philo in /home/loens_g/rendu/TEK2/SystemUnix/PSU_2016_philo/sources/main.c
**
** Made by Gregoire LOENS
** Login   <gregoire.loens@epitech.eu>
**
** Started on  Tue Mar 07 13:35:57 2017 Gregoire LOENS
** Last update Tue Mar  7 18:15:34 2017 loens_g
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"philosophers.h"
#include		"table.h"
#include		"extern.h"

static int		init(pthread_mutex_t **mutexes,
			       t_table *table,
			       t_phil **philo,
			       t_args *args)
{
  t_val			val;
  int			ret;

  ret = verif_arg(&val, args->argc, args->argv);
  if (ret == 1)
  {
    fprintf(stderr, "Invalid Argument\n");
    return (1);
  }
  if (table_init(table, &val) == NULL)
  {
    fprintf(stderr, "Unable to create table for the philosophers\n");
    return (1);
  }
  *philo = philosophers_create(table, mutexes);
  if (*philo == NULL)
  {
    fprintf(stderr, "Unable to create philosophers\n");
    return (1);
  }
  return (0);
}

int			main(int argc, char **argv)
{
  pthread_mutex_t	*mutexes;
  t_table		table;
  t_phil		*philo;
  t_args		args;
  int			ret;

  RCFStartup(argc, argv);
  args.argc = argc;
  args.argv = argv;
  ret = init(&mutexes, &table, &philo, &args);
  if (ret != 0)
    return (1);
  launch_philosophers(&table, philo);
  free(philo);
  mutex_destroy(mutexes, &table);
  free(table.priority);
  RCFCleanup();
  return (0);
}
