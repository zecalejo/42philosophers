/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:03:27 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/21 23:51:02 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_stop_sim_flag(t_table *table, int state)
{
	pthread_mutex_lock(&table->stop_sim_mtx);
	table->stop_sim = state;
	pthread_mutex_unlock(&table->stop_sim_mtx);
}

int	sim_stopped(t_table *table)
{
	int	tf;
	
	tf = FALSE;
	pthread_mutex_lock(&table->stop_sim_mtx);
	if (table->stop_sim == TRUE)
		tf = TRUE;
	pthread_mutex_unlock(&table->stop_sim_mtx);
	return (tf);
}

int philo_death(t_philo *philo)
{
	unsigned long	time;

	time = gettimeofday_ms();
	if ((time - philo->last_meal) >= philo->table->time_to_die)
	{
		set_stop_sim_flag(philo->table, TRUE);
		write_status(philo, TRUE, "died");
		// pthread_mutex_unlock(&philo->philo_mtx);
		return (TRUE);
	}
	return (FALSE);
}

static int	end_condition_reached(t_table *table)
{
	int	i;
	int	all_ate_enough;

	all_ate_enough = TRUE;
	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_lock(&table->philos[i]->philo_mtx);
		if (philo_death(table->philos[i]))
			return (TRUE);
		if (table->n_meals != -1)
			if (table->philos[i]->meals_eaten < table->n_meals)
				all_ate_enough = FALSE;
		pthread_mutex_unlock(&table->philos[i]->philo_mtx);
		i++;
	}
	if (table->n_meals != -1 && all_ate_enough == TRUE)
	{
		set_stop_sim_flag(table, TRUE);
		return (TRUE);
	}
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
