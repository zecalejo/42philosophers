/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:46:30 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/23 18:29:00 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (error_int(STR_ERR_INPUT_DIGIT, av[i], 0));
			j++;
		}
		i++;
	}
	return (1);
}

int	ph_atoi(char *str)
{
	unsigned long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (res > INT_MAX)
		return (error_int(STR_ERR_INPUT_DIGIT, NULL, 0));
	return (res);
}

unsigned long	gettimeofday_ms(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	write_status(t_philo *philo, int is_dead, char *status)
{
	pthread_mutex_lock(&philo->table->write_mtx);
	if (sim_stopped(philo->table) == TRUE && is_dead == FALSE)
	{
		pthread_mutex_unlock(&philo->table->write_mtx);
		return ;
	}
	printf("%lu %d %s\n", (gettimeofday_ms() - philo->table->start_time),
		philo->id, status);
	pthread_mutex_unlock(&philo->table->write_mtx);
}
