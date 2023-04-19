/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:29:44 by jduval            #+#    #+#             */
/*   Updated: 2023/04/19 11:41:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	think_to_death(t_philo *philo, long time);

void	job_think(t_philo *philo)
{
	long	time;

	time = get_the_time() + philo->data->time_of_think;
	if (time >= philo->time_of_death)
	{
		death(philo, time);
		return ;
	}
	philo->data->func[SLEEP + PRINT](philo);
	usleep(time * 1000);
	philo->status = EAT;
}

static void	think_to_death(t_philo *philo, long time)
{
	if ((time - philo->data->time_of_think) == philo->time_of_death)
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
