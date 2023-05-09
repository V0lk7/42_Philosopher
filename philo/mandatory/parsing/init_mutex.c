/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:07:20 by jduval            #+#    #+#             */
/*   Updated: 2023/05/09 12:08:14 by jduval           ###   ########.fr       */
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
		pthread_mutex_destroy(&data->print);
		free_philo(philo);
		free_forks(forks);
		return (false);
	}
	if (init_mutex_philo(philo) == false)
	{
		pthread_mutex_destroy(&data->print);
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

	i = -1;
	while (philo[++i] != NULL)
	{
		if (pthread_mutex_init(&philo[i]->nbr_eat, NULL) != 0)
		{
			destroy_mutex_philo(philo, i);
			return (false);
		}
		if (pthread_mutex_init(&philo[i]->v_status, NULL) != 0)
		{
			destroy_mutex_philo(philo, i);
			destroy_mutex_verif(philo, i);
			return (false);
		}
		if (pthread_mutex_init(&philo[i]->time.v_death, NULL) != 0)
		{
			destroy_mutex_philo(philo, i);
			destroy_mutex_verif(philo, i);
			destroy_mutex_time(philo, i);
			return (false);
		}
	}
	return (true);
}

void	init_func(t_action **action)
{
	action[0] = job_eat;
	action[1] = job_sleep;
	action[2] = job_think;
	action[4] = NULL;
	return ;
}
