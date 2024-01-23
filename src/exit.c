/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:06:25 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/23 16:57:40 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_table(t_table *table)
{
	int	i;

	if (!table)
		return (NULL);
	if (table->fork_mtxs != NULL)
		free(table->fork_mtxs);
	if (table->philos != NULL)
	{
		i = 0;
		while (i < table->n_philos)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
			i++;
		}
		free(table->philos);
	}
	free(table);
	return (NULL);
}

void	destroy_mtxs(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philos)
	{
		pthread_mutex_destroy(&table->fork_mtxs[i]);
		pthread_mutex_destroy(&table->philos[i]->philo_mtx);
		i++;
	}
	pthread_mutex_destroy(&table->write_mtx);
	pthread_mutex_destroy(&table->stop_sim_mtx);
}

int	msg(char *str, char *detail, int exit_no)
{
	if (!detail)
		printf("%s", str);
	else
		printf(str, detail);
	return (exit_no);
}

int	error_int(char *str, char *detail, t_table *table)
{
	if (table != NULL)
		free_table(table);
	return (msg(str, detail, 0));
}

void	*error_null(char *str, char *detail, t_table *table)
{
	if (table != NULL)
		free_table(table);
	msg(str, detail, EXIT_FAILURE);
	return (NULL);
}
