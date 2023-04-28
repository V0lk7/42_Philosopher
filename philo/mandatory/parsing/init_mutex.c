/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:07:20 by jduval            #+#    #+#             */
/*   Updated: 2023/04/28 14:58:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdlib.h>

bool	init_all_mutex(t_philo **philo, t_fork **forks, t_data *data)
{
	if (init_mutex_data(data) == false)
	{
		free_philo(philo);
		free_forks(forks);
		return (false);
	}
	if (init_mutex_forks(forks) == false)
	{
		destroy_mutex_data(data);
		free_philo(philo);
		free_forks(forks);
		return (false);
	}
	if (init_mutex_philo(philo) == false)
	{
		destroy_mutex_data(data);
		destroy_mutex_forks(forks, -1);
		free_philo(philo);
		free_forks(forks);
		return (false);
	}
	return (true);
}

bool	init_mutex_data(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->end_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print);
		return (false);
	}
	return (true);
}

bool	init_mutex_forks(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i] != NULL)
	{
		if (pthread_mutex_init(&forks[i]->fork, NULL) != 0)
		{
			destroy_mutex_forks(forks, i);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_mutex_philo(t_philo **philo)
{
	int	i;

	i = 0;
	while (philo[i] != NULL)
	{
		if (pthread_mutex_init(&philo[i]->nbr_eat, NULL) != 0)
		{
			destroy_mutex_philo(philo, i);
			return (false);
		}
		i++;
	}
	return (true);
}
