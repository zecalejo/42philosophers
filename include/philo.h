/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:40:08 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/23 21:15:25 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

/************************************************************************
*								Macros									*
************************************************************************/
# define MAX_PHILOS	200
# define FALSE 0
# define TRUE 1

# define STR_USAGE	"The arguments should be as follows:\n \
	./philo <number_of_philosophers> \
	<time_to_die> <time_to_eat> <time_to_sleep> \
	[number_of_times_each_philosopher_must_eat]\n"
# define STR_ERR_INPUT_DIGIT	"Invalid input: %s\n \
	Should be a positive integer.\n"
# define STR_ERR_INPUT_NPHIL	"Invalid input: %s\n \
	There must be between 1 and 200 philosophers.\n"
# define STR_ERR_THREAD	"error: Could not create thread.\n"
# define STR_ERR_MALLOC	"error: Could not allocate memory.\n"
# define STR_ERR_MUTEX	"error: Could not create mutex.\n"

/************************************************************************
*								Structures								*
************************************************************************/

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					n_philos;
	long long int		time_to_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	int					n_meals;
	long long int		start_time;
	int					stop_sim;
	pthread_t			supervisor;
	pthread_mutex_t		write_mtx;
	pthread_mutex_t		stop_sim_mtx;
	pthread_mutex_t		*fork_mtxs;
	t_philo				**philos;
}	t_table;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					fork[2];
	int					meals_eaten;
	long long int		last_meal;
	pthread_mutex_t		philo_mtx;
	t_table				*table;
}	t_philo;

/************************************************************************
*							Function Prototypes							*
************************************************************************/

//		utils.c
int				valid_input(char **av);
int				ph_atoi(char *str);
long long int	gettimeofday_ms(void);
void			write_status(t_philo *philo, int is_dead, char *status);

//		init.c
t_table			*table_init(int ac, char **av);
t_philo			**philos_init(t_table *table);

//		routines.c
void			*philo_routine(void *data);

//		supervisor.c
int				sim_stopped(t_table *table);
void			*supervisor(void *data);

//		exit.c
void			*free_table(t_table *table);
void			destroy_mtxs(t_table *table);
int				msg(char *str, char *detail, int exit_no);
int				error_int(char *str, char *detail, t_table *table);
void			*error_null(char *str, char *detail, t_table *table);

#endif