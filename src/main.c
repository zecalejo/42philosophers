/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:21 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/12 16:47:13 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*thread_routine(void *data)
// {
// 	pthread_t	*philo;
// 	unsigned int	i;

// 	philo = (pthread_t *)data;
// 	return (NULL);
// }

int	main(int ac, char **av)
{
	static t_table	table;
	
	table_init(&table, ac, av);
	printf("Nb Philos = %ld\nT. Die = %ld\nT. Eat = %ld\nT. Sleep = %ld\nMax Meals = %ld\n",
		table.n_philos, table.time_to_die, table.time_to_eat, table.time_to_sleep, table.max_meals);
	return (0);
}
