/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:35:21 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/11 18:18:04 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_routine(void *data)
{
	pthread_t	*philo;
	unsigned int	i;

	philo = (pthread_t *)data;
	return (NULL);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac >= 5 && ac <= 6)
	{
		while (i <= )
		pthread_create(&tid1, NULL, thread_routine, &counter);
		printf("Main: Created first thread [%ld]\n", tid1);
		pthread_create(&tid2, NULL, thread_routine, &counter);
		printf("Main: Created second thread [%ld]\n", tid2);
		pthread_join(tid1, NULL);
		printf("Main: Joined first thread [%ld]\n", tid1);
		pthread_join(tid2, NULL);
		printf("Main: Joined second thread [%ld]\n", tid2);
		if (counter.count != (2 * TIMES_TO_COUNT))
			printf("%sMain: ERROR ! Total count is %u%s\n",
						RED, counter.count, NC);
		else
			printf("%sMain: OK. Total count is %u%s\n",
						GREEN, counter.count, NC);
		pthread_mutex_destroy(&counter.count_mutex);
	}
	return (0);
}
