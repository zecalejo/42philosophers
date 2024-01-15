/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:40:08 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/15 19:40:48 by jnuncio-         ###   ########.fr       */
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
	/*data*/
}	t_philo;

typedef struct s_forks
{
	/*data*/
}	t_forks;

typedef struct s_table
{
	long int	n_philos;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	long int	max_meals;
}	t_table;


/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/

//		utils.c
long int 	ph_atoi(char *str);

//		init.c
void		table_init(t_table *table, int ac, char **av);

#endif