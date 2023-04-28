/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:17:29 by jduval            #+#    #+#             */
/*   Updated: 2023/04/28 11:45:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <sys/time.h>
#include <stdlib.h>

bool	all_philo_have_eat(t_philo **philo)
{
	int		i;

	if (philo[0]->data->nbr_of_eat == -1)
		return (false);
	i = 0;
	while (philo[i])
	{
		pthread_mutex_lock(&philo[i]->nbr_eat);
		if (philo[i]->nbr_of_eat < philo[i]->data->nbr_of_eat)
		{
			pthread_mutex_unlock(&philo[i]->nbr_eat);
			return (false);
		}
		pthread_mutex_unlock(&philo[i]->nbr_eat);
		i++;
	}
	return (true);
}

long	get_the_time(long zero)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + (time.tv_usec / 1000) - zero);
}

bool	end_check(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->end_mutex);
	if (data->end == true)
	{
		pthread_mutex_unlock(&data->end_mutex);
		return (true);
	}
	pthread_mutex_unlock(&data->end_mutex);
	pthread_mutex_lock(&philo->nbr_eat);
	if (philo->nbr_of_eat == data->nbr_of_eat)
	{
		pthread_mutex_unlock(&philo->nbr_eat);
		return (true);
	}
	pthread_mutex_unlock(&philo->nbr_eat);
	return (false);
}

void	init_func(t_action **action)
{
	action[0] = job_eat;
	action[1] = job_sleep;
	action[2] = job_think;
	action[3] = print_eat;
	action[4] = print_sleep;
	action[5] = print_think;
	action[6] = print_death;
	action[7] = print_fork;
	action[8] = NULL;
	return ;
}
