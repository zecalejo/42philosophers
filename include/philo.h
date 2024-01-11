/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:40:08 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/11 20:40:25 by jnuncio-         ###   ########.fr       */
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

/******************************************************************************
*                                 Structures                                  *
******************************************************************************/

typedef struct s_philo
{
	/*data*/
}	t_philo;

typedef struct s_table
{
	int		n_philos;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int		n_meals;
}	t_table;


/******************************************************************************
*                           Function Prototypes                               *
******************************************************************************/

#endif