/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:12:36 by jduval            #+#    #+#             */
/*   Updated: 2023/04/28 13:32:17 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

static void	sleep_to_death(t_philo *philo, long time);

void	job_sleep(t_philo *philo)
{
	if (end_check(philo->data, philo) == true)
		return ;
	philo->time.job = get_the_time(philo->time.zero);
	if (philo->time.job + philo->data->time_of_sleep >= philo->time.death)
	{
		sleep_to_death(philo, philo->time.job);
		return ;
	}
	philo->data->func[SLEEP + PRINT](philo);
	usleep(philo->data->time_of_sleep * 1000);
	philo->status = THINK;
}

static void	sleep_to_death(t_philo *philo, long time)
{
	if (end_check(philo->data, philo) == true)
		return ;
	if ((time - philo->data->time_of_sleep) == philo->time.death)
		death(philo);
	else
	{
		time = (philo->time.death - get_the_time(philo->time.zero));
		if (time >= 0)
		{
			philo->data->func[SLEEP + PRINT](philo);
			usleep(time * 1000);
		}
		death(philo);
	}
}
