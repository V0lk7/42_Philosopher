/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:12:36 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 11:41:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	sleep_to_death(t_philo *philo, long time);

void	job_sleep(t_philo *philo)
{
	long	time;

	time = get_the_time() + philo->data->time_of_sleep;
	if (time >= philo->time_of_death)
	{
		sleep_to_death(philo, time);
		return ;
	}
	philo->data->func[SLEEP + PRINT](philo);
	usleep(time * 1000);
	philo->status = THINK;
}

static void	sleep_to_death(t_philo *philo, long time)
{
	if ((time - philo->data->time_of_sleep) == philo->time_of_death)
		death(philo);
	else
	{
		time = (philo->time_of_death - get_the_time()) * 1000;
		if (time >= 0)
		{
			philo->data->func[SLEEP + PRINT](philo);
			usleep(time);
		}
		death(philo);
	}
}
