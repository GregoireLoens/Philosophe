/*
** command_line.c for PSU_2016_philo in /home/soszyn_h/rendu/PSU/PSU_2016_philo/sources/command_line.c
**
** Made by Hugo SOSZYNSKI
** Login   <hugo.soszynski@epitech.eu>
**
** Started on  Mon Mar 13 14:38:48 2017 Hugo SOSZYNSKI
** Last update Mon Mar 13 14:38:48 2017 Hugo SOSZYNSKI
*/

#include	<memory.h>
#include	<stdlib.h>
#include	"philo_struct.h"
#include "../includes/philo_struct.h"

static int	check_nb(char **argv)
{
  int		cpt;

  cpt = 0;
  while (argv[2][cpt])
  {
    if (argv[2][cpt] < '0' && argv[2][cpt] > '9')
      return (1);
    cpt++;
  }
  cpt = 0;
  while (argv[4][cpt])
  {
    if (argv[4][cpt] < '0' && argv[4][cpt] > '9')
      return (1);
    cpt++;
  }
  return (0);
}

int		verif_arg(t_val *philo, int argc, char **argv)
{
  int 		cpt;
  int		ret;

  cpt = 1;
  if (argc != 5)
    return (1);
  ret = check_nb(argv);
  if (ret == 1)
    return (1);
  while (argv[cpt])
  {
    ret = strcmp(argv[cpt], "-p");
    if (ret == 0)
      philo->nb_philo = atoi(argv[cpt + 1]);
    if (philo->nb_philo < 2)
      return (1);
    ret = strcmp(argv[cpt], "-e");
    if (ret == 0)
      philo->nb_eat = atoi(argv[cpt + 1]);
    cpt += 2;
  }
  return (0);
}
