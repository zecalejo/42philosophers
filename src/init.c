/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:57 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/22 16:42:25 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*forks_init(t_table *table)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!forks)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, 0));
		i++;
	}
	return (forks);
}

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id - 1;
	philo->fork[1] = philo->id % philo->table->n_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = philo->id % philo->table->n_philos;
		philo->fork[1] = philo->id - 1;
	}
}

t_philo	**philos_init(t_table *table)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo *) * table->n_philos);
	if (!philos)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	while (i < table->n_philos)
	{
		philos[i] = malloc(sizeof(t_philo *) * 1);
		if (!philos[i])
			return (error_null(STR_ERR_MALLOC, NULL, 0));
		if (pthread_mutex_init(&philos[i]->philo_mtx, 0) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, 0));
		philos[i]->table = table;
		philos[i]->id = i + 1;		
		philos[i]->meals_eaten = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

static int	global_mtxs_init(t_table *table)
{
	table->fork_mtxs = forks_init(table);
	if (!table->fork_mtxs)
		return (FALSE);
	if (pthread_mutex_init(&table->stop_sim_mtx, 0) != 0)
		return (error_int(STR_ERR_MUTEX, NULL, table));
	if (pthread_mutex_init(&table->write_mtx, 0) != 0)
		return (error_int(STR_ERR_MUTEX, NULL, table));
	return (TRUE);
}

t_table	*table_init(int ac, char **av)
{
	t_table	*table;
	
	table = malloc(sizeof(t_table *) * 1);
	table->n_philos = ph_atoi(av[1]);
	if (table->n_philos < 1 || table->n_philos > MAX_PHILOS)
		return (error_null(STR_ERR_INPUT_NPHIL, av[1], 0));
	table->time_to_die = ph_atoi(av[2]);
	table->time_to_eat = ph_atoi(av[3]);
	table->time_to_sleep = ph_atoi(av[4]);
	table->n_meals = -1;
	if (ac == 6)
		table->n_meals = ph_atoi(av[5]);
	table->philos = philos_init(table);
	if (!table->philos)
		return (NULL);
	if (!global_mtxs_init(table))
		return (NULL);
	table->stop_sim = FALSE;
	return (table);
}
