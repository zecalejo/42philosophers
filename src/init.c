/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:57 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/17 14:03:40 by jnuncio-         ###   ########.fr       */
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

t_philos	*philos_init(int n_philos)
{
	t_philos	*philos;

	philos = malloc(sizeof(t_philos *) * 1);
	return (philos);
}
