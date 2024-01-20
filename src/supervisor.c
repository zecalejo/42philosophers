/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:03:27 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/20 21:44:09 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_stop_sim_flag(t_table *table, int state)
{
	pthread_mutex_lock(&table->stop_sim_mtx);
		table->stop_sim = state;
	pthread_mutex_unlock(&table->stop_sim_mtx);
}


int philo_death(t_philo *philo)
{
	//code
}

static int	end_condition_reached(t_table *table)
{
	//code
	return (FALSE);
}

void	*supervisor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->n_meals == 0)
		return (NULL);
	set_stop_sim_flag(table, FALSE);
	while (1)
	{
		if (end_condition_reached(table) == TRUE)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
