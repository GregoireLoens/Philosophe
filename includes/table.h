/*
** table.h for PSU_2016_philo in /home/loens_g/rendu/TEK2/SystemUnix/PSU_2016_philo/includes/table.h
**
** Made by Gregoire LOENS
** Login   <gregoire.loens@epitech.eu>
**
** Started on  Wed Mar 15 11:36:56 2017 Gregoire LOENS
** Last update Wed Mar 15 11:36:56 2017 Gregoire LOENS
*/

#ifndef TABLE_H_
# define TABLE_H_

# include		"philo_struct.h"

extern pthread_mutex_t	g_table_mutex;

/*
** Initialise the table structure.
** Return a pointer to the initialised tabled on success, NULL otherwise.
*/
t_table			*table_init(t_table *table, t_val *val);

/*
** Decrease the priority of a philosopher.
*/
void			table_update_priority(t_table *table, int id);

/*
** Check if a philosopher sent an "end message".
** Return true if the "message" was sent, false otherwise
*/
bool			table_check_end(t_table *table);

/*
** Return priority of the thread of the corresponding id
*/
int			table_check_priority(t_table *table, int id);

/*
** Set end to true
*/
void			table_set_end(t_table *table);

/*
** Return the priority of the left philosopher
** The id s the id of your current philosopher
*/
int			table_get_left_priority(t_table *table, int id);

/*
** Return the priority of the right philosopher
** The id s the id of your current philosopher
*/
int			table_get_right_priority(t_table *table, int id);

#endif /* !TABLE_H_ */
