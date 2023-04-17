/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:30:00 by jduval            #+#    #+#             */
/*   Updated: 2023/04/17 14:12:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../philo.h"

void	free_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i])
	{
		free(philo[i]);
		i++;
	}
	free(philo);
	return ;
}

void	free_forks(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i])
	{
		pthread_mutex_destroy(&forks[i]->fork);
		free(forks[i]);
		i++;
	}
	free(forks);
	return ;
}

void	free_all(t_fork **forks, t_philo **philo)
{
	free_forks(forks);
	free_philo(philo);
	return ;
}
