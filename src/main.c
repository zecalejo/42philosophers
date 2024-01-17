/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:21 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/17 19:56:21 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;
	
	if (ac < 5 || ac > 6)
		return (printf("Diff nb of args.\n"));
	else
	{
		if (!check_args(av))
			return (printf("Only positive ints, please.\n"));
		table = table_init(ac, av);
		printf("Nb Philos = %lu\nT. Die = %lu\nT. Eat = %lu\nT. Sleep = %lu\n",
			table->n_philos, table->time_to_die, table->time_to_eat, table->time_to_sleep);
		if (table->max_meals)
			printf("Max Meals = %lu\n", table->max_meals);
	}
	free (table);
	return (0);
}
