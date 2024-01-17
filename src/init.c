/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:57 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/17 20:06:15 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table_init(int ac, char **av)
{
	t_table	*table;
	
	table = malloc(sizeof(t_table *) * 1);
	table->n_philos = ph_atoi(av[1]);
	table->time_to_die = ph_atoi(av[2]);
	table->time_to_eat = ph_atoi(av[3]);
	table->time_to_sleep = ph_atoi(av[4]);
	if (ac == 6)
		table->max_meals = ph_atoi(av[5]);
	return (table);
}

t_philo	**philos_init(t_table *table)
{
	t_philo				**philos;
	unsigned long int	i;

	i = 0;
	philos = malloc(sizeof(t_philo *) * table->n_philos);
	if (!philos)
	{
		printf("error: unable to allocate memory (t_philo **philos)\n");
		return (NULL);
	}
	while (i < table->n_philos)
	{
		philos[i] = malloc(sizeof(t_philo *) * 1);
		if (!philos[i])
		{
			printf("error: unable to allocate memory (t_philo *philos[%lu])\n", i);
			return (NULL);
		}
		if (pthread_mutex_init(&philos[i]->ph_mutex, 0) != 0)
		{
			printf("error: unable to initialize mutex (t_philo *philos[%lu])\n", i);
			return (NULL);
		}
		philos[i]->id = i + 1;		
		philos[i]->meals_eaten = 0;
		i++;
	}
	return (philos);
}
