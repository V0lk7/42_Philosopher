/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:36:24 by jduval            #+#    #+#             */
/*   Updated: 2023/05/05 14:06:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdlib.h>

void	create_pthread_error(t_philo **philo, int index)
{
	if (index == 0)
		return ;
	make_end(philo);
	while (index > 0)
	{
		pthread_join(philo[index]->id, NULL);
		index--;
	}
	return ;
}

void	free_and_destroy(t_fork **forks, int index)
{
	while (index >= 0)
	{
		pthread_mutex_destroy(&forks[index]->fork);
		index--;
	}
	index = 0;
	while (forks[index] != NULL)
	{
		free(forks[index]);
		index++;
	}
	free(forks);
}
