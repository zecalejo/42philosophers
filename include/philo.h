/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:40:08 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/18 10:25:32 by jnuncio-         ###   ########.fr       */
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

/******************************************************************************
*                                     Macros                                  *
******************************************************************************/

# define NC	"\e[0m"
# define RED	"\e[31m"
# define GREEN  "\e[32m"
# define YELLOW "\e[33m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

# define STR_ERR_THREAD	"%s error: Could not create thread.\n"
# define STR_ERR_MALLOC	"%s error: Could not allocate memory.\n"
# define STR_ERR_MUTEX	"%s error: Could not create mutex.\n"

/******************************************************************************
*                                 Structures                                  *
******************************************************************************/

typedef struct s_philo
{
	pthread_t			*philo;
	unsigned long int	id;
	unsigned long int	meals_eaten;
	unsigned long int	last_meal;
	pthread_mutex_t		ph_mutex;
}	t_philo;

typedef struct s_forks
{
	/*data*/
}	t_forks;

typedef struct s_table
{
	unsigned long int	n_philos;
	unsigned long int	time_to_die;
	unsigned long int	time_to_eat;
	unsigned long int	time_to_sleep;
	unsigned long int	n_meals;
	t_philo				**philos;
}	t_table;


/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/

//		parsing.c
int 		check_args(char **av);

//		utils.c
int 		ph_atoi(char *str);

//		init.c
t_table		*table_init(int ac, char **av);
t_philo		**philos_init(t_table *table);

#endif