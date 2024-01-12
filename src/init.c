/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:57 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/12 16:55:45 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void table_init(t_table *table, int ac, char **av)
{
	// table = malloc(sizeof(t_table) * 1);
	// if (!table)
	// 	return ;
	table->n_philos = ph_atoi(av[1]);
	table->time_to_die = ph_atoi(av[2]);
	table->time_to_eat = ph_atoi(av[3]);
	table->time_to_sleep = ph_atoi(av[4]);
	if (ac == 6)
		table->max_meals = ph_atoi(av[5]);
	printf("av[1] = %ld\nav[2] = %ld\nav[3] = %ld\nav[4] = %ld\nav[5] = %ld\n",
		table->n_philos, table->time_to_die, table->time_to_eat, table->time_to_sleep, table->max_meals);
	return ;
}