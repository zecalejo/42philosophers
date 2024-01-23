/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:15:54 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/23 21:15:28 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	status_duration(t_table *table, long long int duration)
{
	long long int	end_status;

	end_status = gettimeofday_ms() + duration;
	while (gettimeofday_ms() < end_status)
	{
		if (sim_stopped(table))
			break ;
		usleep(100);
	}
}

static void	eat_sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_mtxs[philo->fork[0]]);
	write_status(philo, FALSE, "has taken a fork");
	pthread_mutex_lock(&philo->table->fork_mtxs[philo->fork[1]]);
	write_status(philo, FALSE, "has taken a fork");
	write_status(philo, FALSE, "is eating");
	pthread_mutex_lock(&philo->philo_mtx);
	philo->last_meal = gettimeofday_ms();
	pthread_mutex_unlock(&philo->philo_mtx);
	status_duration(philo->table, philo->table->time_to_eat);
	if (sim_stopped(philo->table) == FALSE)
	{
		pthread_mutex_lock(&philo->philo_mtx);
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->philo_mtx);
	}
	write_status(philo, FALSE, "is sleeping");
	pthread_mutex_unlock(&philo->table->fork_mtxs[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->fork_mtxs[philo->fork[0]]);
	status_duration(philo->table, philo->table->time_to_sleep);
}

static void	think_routine(t_philo *philo, int silent)
{
	long long int	thinking_time;

	pthread_mutex_lock(&philo->philo_mtx);
	thinking_time = (philo->table->time_to_die - (gettimeofday_ms() \
		- philo->last_meal) - philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->philo_mtx);
	if (thinking_time < 0)
		thinking_time = 0;
	if (thinking_time == 0 && silent == TRUE)
		thinking_time = 1;
	if (thinking_time > 600)
		thinking_time = 200;
	if (silent == FALSE)
		write_status(philo, FALSE, "is thinking");
	status_duration(philo->table, thinking_time);
}

static void	*foreveralone_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork_mtxs[philo->fork[0]]);
	write_status(philo, FALSE, "has taken a fork");
	status_duration(philo->table, philo->table->time_to_die);
	write_status(philo, FALSE, "died");
	pthread_mutex_unlock(&philo->table->fork_mtxs[philo->fork[0]]);
	return (NULL);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->table->n_meals == 0)
		return (NULL);
	pthread_mutex_lock(&philo->philo_mtx);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->philo_mtx);
	if (philo->table->time_to_die == 0)
		return (NULL);
	if (philo->table->n_philos == 1)
		return (foreveralone_routine(philo));
	else if (philo->id % 2)
		think_routine(philo, TRUE);
	while (sim_stopped(philo->table) == FALSE)
	{
		if (philo->meals_eaten == philo->table->n_meals)
			break ;
		eat_sleep_routine(philo);
		think_routine(philo, FALSE);
	}
	return (NULL);
}
