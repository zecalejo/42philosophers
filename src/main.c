/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:21 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/18 17:13:46 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;
	
	if (ac < 5 || ac > 6)
		return (error_int(STR_USAGE, NULL, 0));
	else
	{
		if (!check_input(av))
			return (0);
		table = table_init(ac, av);
		printf("Nb Philos = %d\nT. Die = %lu\nT. Eat = %lu\nT. Sleep = %lu\n",
			table->n_philos, table->time_to_die, table->time_to_eat, table->time_to_sleep);
		if (table->n_meals)
			printf("Max Meals = %d\n", table->n_meals);
	}
	free (table);
	return (0);
}
