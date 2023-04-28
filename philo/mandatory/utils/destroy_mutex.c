/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:38:38 by jduval            #+#    #+#             */
/*   Updated: 2023/04/28 15:11:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_all_mutex(t_data *data, t_philo **philo, t_fork **forks)
{
	destroy_mutex_data(data);
	destroy_mutex_forks(forks, -1);
	destroy_mutex_philo(philo, -1);
}

void	destroy_mutex_data(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->end_mutex);
}

void	destroy_mutex_forks(t_fork **forks, int i)
{
	if (i == -1)
	{
		i = 0;
		while (forks[i])
		{
			pthread_mutex_destroy(&forks[i]->fork);
			i++;
		}
		return ;
	}
	while (i >= 0)
	{
		pthread_mutex_destroy(&forks[i]->fork);
		i--;
	}
	return ;
}

void	destroy_mutex_philo(t_philo **philo, int i)
{
	if (i == -1)
	{
		i = 0;
		while (philo[i])
		{
			pthread_mutex_destroy(&philo[i]->nbr_eat);
			i++;
		}
		return ;
	}
	while (i >= 0)
	{
		pthread_mutex_destroy(&philo[i]->nbr_eat);
		i--;
	}
	return ;
}
