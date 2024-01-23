/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:21 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/23 17:11:58 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_sim(t_table *table)
{
	int	i;

	table->start_time = gettimeofday_ms();
	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				&philo_routine, table->philos[i]) != 0)
			return (error_int(STR_ERR_THREAD, NULL, table));
		i++;
	}
	if (table->n_philos > 1)
	{
		if (pthread_create(&table->supervisor, NULL,
				&supervisor, table) != 0)
			return (error_int(STR_ERR_THREAD, NULL, table));
	}
	return (TRUE);
}

static void	stop_sim(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	if (table->n_philos > 1)
		pthread_join(table->supervisor, NULL);
	destroy_mtxs(table);
	free_table(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac < 5 || ac > 6)
		return (msg(STR_USAGE, NULL, EXIT_FAILURE));
	if (!valid_input(av))
		return (EXIT_FAILURE);
	table = table_init(ac, av);
	if (!table)
		return (EXIT_FAILURE);
	if (!start_sim(table))
		return (EXIT_FAILURE);
	stop_sim(table);
	return (EXIT_SUCCESS);
}
