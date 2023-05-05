/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:12:36 by jduval            #+#    #+#             */
/*   Updated: 2023/05/05 17:43:56 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <unistd.h>

static void	sleep_to_death(t_philo *philo);

void	job_sleep(t_philo *philo)
{
	long	time;

	time = get_time(philo->time.zero) + philo->data->time_of_sleep;
	pthread_mutex_lock(&philo->time.v_death);
	if (time >= philo->time.death)
	{
		pthread_mutex_unlock(&philo->time.v_death);
		sleep_to_death(philo);
		return ;
	}
	pthread_mutex_unlock(&philo->time.v_death);
	philo->data->func[PRINT_SLEEP](philo);
	if (am_i_dead(philo) == true || is_the_end(philo) == true)
		return ;
	usleep(philo->data->time_of_sleep * 1000);
	change_state(philo, THINK);
}

static void	sleep_to_death(t_philo *philo)
{
	long	time;

	if (is_the_end(philo) == true || am_i_dead(philo) == true)
		return ;
	pthread_mutex_lock(&philo->time.v_death);
	time = (philo->time.death - get_time(philo->time.zero));
	pthread_mutex_unlock(&philo->time.v_death);
	if (time >= 0)
	{
		philo->data->func[PRINT_SLEEP](philo);
		pthread_mutex_lock(&philo->time.v_death);
		time = (philo->time.death - get_time(philo->time.zero));
		pthread_mutex_unlock(&philo->time.v_death);
		usleep(time * 1000);
	}
}
