/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:57 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/11 20:46:12 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table *table_init(int ac, char **av)
{
	t_table *table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (ERROR);
	table->n_philos = ph_atoi(av[1]);
	table->time_to_die = ph_atoi(av[2]);
	table->time_to_die = ph_atoi(av[3]);
	table->time_to_sleep = ph_atoi(av[4]);
	if (ac == 6)
		table->n_meals = ph_atoi(av[5]);
	return (table);
}