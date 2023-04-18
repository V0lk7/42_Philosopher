/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:02:25 by jduval            #+#    #+#             */
/*   Updated: 2023/04/18 16:27:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	unsigned int	time;

	time = get_the_time() + philo->data->time_of_eat;
	if (philo->fork_l == NULL)
	{
		one_philo(philo);
		return ;
	}
	if (time >= philo->time_of_death)
	{
		eat_to_death(philo, time);
		return ;
	}
	pthread_mutex_lock(&philo->fork_l->fork);
	pthread_mutex_lock(&philo->fork_r->fork);
	usleep(philo->data->time_of_eat * 1000);
	philo->status = SLEEP;
}

void	eat_to_death(t_philo *philo, unsigned int time)
{
	if ((time - philo->data->time_of_eat) == philo->time_of_death)
		the_death(philo);
	else
	{
		pthread_mutex_lock(&philo->fork_l->fork);
		pthread_mutex_lock(&philo->fork_r->fork);
		time = (get_the_time() - time_of_death) * 1000;
		if (time >= 0)
		{
			usleep(time);
		}
		the_death(philo);
	}
}
