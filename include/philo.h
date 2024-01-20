/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:40:08 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/20 15:54:55 by jnuncio-         ###   ########.fr       */
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

/******************************************************************************
*                                     Macros                                  *
******************************************************************************/
# define MAX_PHILOS	INT_MAX

# define NC	"\e[0m"
# define RED	"\e[31m"
# define GREEN  "\e[32m"
# define YELLOW "\e[33m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

# define STR_USAGE	"The arguments should be as follows:\n./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"
# define STR_ERR_INPUT_DIGIT	"Invalid input: %s\nShould be a positive integer.\n"
# define STR_ERR_INPUT_NPHIL	"Invalid input: %s\nThere must be between 1 and %s philosophers.\n"
# define STR_ERR_THREAD	"error: Could not create thread.\n"
# define STR_ERR_MALLOC	"error: Could not allocate memory.\n"
# define STR_ERR_MUTEX	"error: Could not create mutex.\n"

/******************************************************************************
*                                 Structures                                  *
******************************************************************************/

typedef struct s_philo
{
	pthread_t			*philo;
	int					id;
	int					fork[2];
	int					meals_eaten;
	unsigned long int	last_meal;
	pthread_mutex_t		ph_mutex;
}	t_philo;

typedef struct s_table
{
	int					n_philos;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;
	int					n_meals;
	int					stop_sim;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		sim_stop_lock;
	pthread_mutex_t		*fork_locks;
	t_philo				**philos;
}	t_table;


/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/

//		parsing.c
int 		valid_input(char **av);

//		utils.c
int 		ph_atoi(char *str);

//		init.c
t_table		*table_init(int ac, char **av);
t_philo		**philos_init(t_table *table);

//		exit.c
int			msg(char *str, char *detail, int exit_no);
int			error_int(char *str, char *detail, t_table *table);
void		*error_null(char *str, char *detail, t_table *table);

#endif