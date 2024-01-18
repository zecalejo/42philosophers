/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:06:25 by jnuncio-          #+#    #+#             */
/*   Updated: 2024/01/18 17:09:29 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
    (void)table;
	// if (table != NULL)
	// 	free_table(table);
	return (msg(str, detail, 0));
}

void	*error_null(char *str, char *detail, t_table *table)
{
    (void)table;
	// if (table != NULL)
	// 	free_table(table);
	msg(str, detail, EXIT_FAILURE);
	return (NULL);
}